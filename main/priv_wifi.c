#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include <esp_http_client.h>
#include <esp_system.h>
#include <time.h>
#include <esp_tls.h>

#include "lwip/err.h"
#include "lwip/sys.h"

#include "priv_wifi.h"
#include <sntp.h>

#define MIN(a, b)              (((a) < (b)) ? (a) : (b))
#define MAX_HTTP_RECV_BUFFER   512
#define MAX_HTTP_OUTPUT_BUFFER (100 * 480)

/* The examples use WiFi configuration that you can set via project
   configuration menu

   If you'd rather not, just change the below entries to strings with
   the config you want - ie #define EXAMPLE_WIFI_SSID "mywifissid"
*/

#define EXAMPLE_ESP_WIFI_SSID     "Ip8"
#define EXAMPLE_ESP_WIFI_PASS     "Master20"
#define EXAMPLE_ESP_MAXIMUM_RETRY 4

/* FreeRTOS event group to signal when we are connected*/
static EventGroupHandle_t s_wifi_event_group;

/* The event group allows multiple bits for each event, but we only care about
 * two events:
 * - we are connected to the AP with an IP
 * - we failed to connect after the maximum amount of retries */
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

static const char *TAG = "wifi station";

static int s_retry_num = 0;

#define CONTENT_TYPE_UNKNOWN 0
#define CONTENT_TYPE_CBOR 1
#define CONTENT_TYPE_JSON 2

struct user_data {
    uint8_t *buffer;
    uint32_t idx;
    uint32_t type;
};

static void
event_handler(void *arg, esp_event_base_t event_base, int32_t event_id,
              void *event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT &&
               event_id == WIFI_EVENT_STA_DISCONNECTED) {
        if (s_retry_num < EXAMPLE_ESP_MAXIMUM_RETRY) {
            esp_wifi_connect();
            s_retry_num++;
            ESP_LOGI(TAG, "retry to connect to the AP");
        } else {
            xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
        }
        ESP_LOGI(TAG, "connect to the AP fail");
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
        s_retry_num = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
    }
}

enum wifi_error
priv_wifi_init(void)
{
    enum wifi_error   err = WIFI_ERR_UNAVAILABLE;

    s_wifi_event_group = xEventGroupCreate();

    ESP_ERROR_CHECK(esp_netif_init());

    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    esp_event_handler_instance_t instance_any_id;
    esp_event_handler_instance_t instance_got_ip;
    ESP_ERROR_CHECK(esp_event_handler_instance_register(
        WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL, &instance_any_id));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(
        IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL, &instance_got_ip));
    wifi_config_t wifi_config = {
        .sta = {
            .ssid = EXAMPLE_ESP_WIFI_SSID,
            .password = EXAMPLE_ESP_WIFI_PASS,
            /* Setting a password implies station will connect to all security modes including WEP/WPA.
             * However these modes are deprecated and not advisable to be used. Incase your Access point
             * doesn't support WPA2, these mode can be enabled by commenting below line */
	     .threshold.authmode = WIFI_AUTH_WPA2_PSK,
        },
    };
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG, "wifi_init_sta finished.");

    /* Waiting until either the connection is established (WIFI_CONNECTED_BIT)
     * or connection failed for the maximum
     * number of re-tries (WIFI_FAIL_BIT). The bits are set by event_handler()
     * (see above) */
    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
                                           WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
                                           pdFALSE, pdFALSE, portMAX_DELAY);

    /* xEventGroupWaitBits() returns the bits before the call returned, hence we
     * can test which event actually happened. */
    if (bits & WIFI_CONNECTED_BIT) {
        ESP_LOGI(TAG, "connected to ap SSID:%s password:%s",
                 EXAMPLE_ESP_WIFI_SSID, "**********");
        err = WIFI_ERR_NONE;
    } else if (bits & WIFI_FAIL_BIT) {
        ESP_LOGI(TAG, "Failed to connect to SSID:%s, password:%s",
                 EXAMPLE_ESP_WIFI_SSID, "**********");
    } else {
        ESP_LOGE(TAG, "UNEXPECTED EVENT");
    }

    /* The event will not be processed after unregister */
    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(
        IP_EVENT, IP_EVENT_STA_GOT_IP, instance_got_ip));
    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(
        WIFI_EVENT, ESP_EVENT_ANY_ID, instance_any_id));
    vEventGroupDelete(s_wifi_event_group);


    if( err == WIFI_ERR_NONE ) {
        ESP_LOGI(TAG, "Connecting to SNTP server pool.ntp.org");
        sntp_setoperatingmode(SNTP_OPMODE_POLL);
        sntp_setservername(0, "pool.ntp.org");
        sntp_init();
        while( sntp_get_sync_status() != SNTP_SYNC_STATUS_COMPLETED ) {
            vTaskDelay(1000);
        }
        time_t now;
        time(&now);
        struct tm* t = localtime(&now);
        ESP_LOGI(TAG, "Time acquired!. %s", asctime(t));
    }

    return err;
}

static esp_err_t
_http_event_handler(esp_http_client_event_t *evt)
{
    struct user_data *ud;
    ud = evt->user_data;
    switch (evt->event_id) {
    case HTTP_EVENT_ERROR:
        ESP_LOGI(TAG, "HTTP_EVENT_ERROR");
        break;
    case HTTP_EVENT_ON_CONNECTED:
        ESP_LOGI(TAG, "HTTP_EVENT_ON_CONNECTED");
        break;
    case HTTP_EVENT_HEADER_SENT:
        ESP_LOGI(TAG, "HTTP_EVENT_HEADER_SENT");
        break;
    case HTTP_EVENT_ON_HEADER:
        ESP_LOGI(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key,
                 evt->header_value);
        if(strcmp(evt->header_key, "application/json") == 0) {
            ud->type = CONTENT_TYPE_JSON;
        } else if( strcmp(evt->header_key, "application/cbor") == 0) {
            ud->type = CONTENT_TYPE_CBOR;
        } else {
            ud->type = CONTENT_TYPE_UNKNOWN;
        }
        break;
    case HTTP_EVENT_ON_DATA:
        ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA, len=%d : %d", evt->data_len,
                 ud->idx);

        /*
         *  Check for chunked encoding is added as the URL for chunked encoding
         * used in this example returns binary data. However, event handler can
         * also be used in case chunked encoding is used.
         */
        uint8_t *data     = evt->data;
        int      copy_len = evt->data_len;

        if (!esp_http_client_is_chunked_response(evt->client)) {
            if (ud->idx == 0 && ud->type == CONTENT_TYPE_CBOR) {
                data += 3; /* cbor header */
                copy_len -= 3;
            }
            // If user_data buffer is configured, copy the response into the
            // buffer
            copy_len = MIN(copy_len, (MAX_HTTP_OUTPUT_BUFFER - ud->idx));
            if (copy_len) {
                memcpy(ud->buffer + ud->idx, data, copy_len);
            }
            ud->idx += copy_len;
        } else {
            ESP_LOGI(TAG, "CHUNKED, len=%d : %d", evt->data_len, ud->idx);
            copy_len = MIN(copy_len, (MAX_HTTP_OUTPUT_BUFFER - ud->idx));
            if (copy_len) {
                memcpy(ud->buffer + ud->idx, data, copy_len);
            }
            ud->idx += copy_len;
        }

        break;
    case HTTP_EVENT_ON_FINISH:
        ud = evt->user_data;
        ESP_LOGI(TAG, "HTTP_EVENT_ON_FINISH");
        ud->buffer[ud->idx] = 0;
        ud->idx = 0;

        // if (output_buffer != NULL) {
        //     // Response is accumulated in output_buffer. Uncomment the below
        //     line to print the accumulated response
        //     // ESP_LOG_BUFFER_HEX(TAG, output_buffer, output_len);
        //     free(output_buffer);
        //     output_buffer = NULL;
        // }
        // output_len = 0;
        break;
    case HTTP_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
        int       mbedtls_err = 0;
        esp_err_t err         = esp_tls_get_and_clear_last_error(
            (esp_tls_error_handle_t)evt->data, &mbedtls_err, NULL);
        if (err != 0) {
            ESP_LOGI(TAG, "Last esp error code: 0x%x", err);
            ESP_LOGI(TAG, "Last mbedtls failure: 0x%x", mbedtls_err);
        }
        // if (output_buffer != NULL) {
        //     free(output_buffer);
        //     output_buffer = NULL;
        // }
        // output_len = 0;
        break;
        // case HTTP_EVENT_REDIRECT:
        //     ESP_LOGI(TAG, "HTTP_EVENT_REDIRECT");
        //     esp_http_client_set_header(evt->client, "From",
        //     "user@example.com"); esp_http_client_set_header(evt->client,
        //     "Accept", "text/html");
        //     esp_http_client_set_redirection(evt->client);
        //     break;
    }
    return ESP_OK;
}

esp_err_t
priv_wifi_get_image(uint8_t *buf)
{
    struct user_data ud = {
        .buffer = buf,
        .idx    = 0,
    };

    esp_http_client_config_t cfg = {
        .host                  = "192.168.1.71",
        .port                  = 8080,
        .path                  = "/cbor",
        .query                 = NULL,
        .event_handler         = _http_event_handler,
        .user_data             = &ud,
        .disable_auto_redirect = false,
    };
    esp_http_client_handle_t client = esp_http_client_init(&cfg);

    esp_err_t err = esp_http_client_perform(client);

    if (err != ESP_OK) {
        ESP_LOGI(TAG, "HTTP Get %d:  %d", err,
                 esp_http_client_get_status_code(client));
    }

    return err;
}

void
priv_wifi_stop(void)
{
    esp_wifi_stop();
}

esp_err_t
priv_wifi_get_open_weather_json(char *buf)
{
    struct user_data ud = {
        .buffer = (uint8_t*) buf,
        .idx    = 0,
    };

    esp_http_client_config_t cfg = {
        .host                  = "api.openweathermap.org",
        .port                  = 80,
        .path                  = "/data/2.5/weather?q=Mannheim&appid=a61e7d34591d8be524721f97def4fb41&units=metric",
        .query                 = NULL,
        .event_handler         = _http_event_handler,
        .user_data             = &ud,
        .disable_auto_redirect = false,
    };
    esp_http_client_handle_t client = esp_http_client_init(&cfg);

    esp_err_t err = esp_http_client_perform(client);

    if (err != ESP_OK) {
        ESP_LOGI(TAG, "HTTP Get %d:  %d", err,
                 esp_http_client_get_status_code(client));
    }

    return err;
}

esp_err_t
priv_wifi_get_open_meteo(char *buf)
{
    setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);
    tzset();
    time_t     now = time(NULL);
    struct tm *t   = localtime(&now);
    char path[400];
    char sdate[20];
    char edate[20];

    strftime(sdate, sizeof(sdate) - 1, "%Y-%m-%d", t);
    t->tm_mday += 1;
    strftime(edate, sizeof(sdate) - 1, "%Y-%m-%d", t);

    sprintf(path, "/v1/dwd-icon?latitude=48.78"
        "&longitude=9.18"
        "&hourly=temperature_2m,precipitation,weathercode"
        "&daily=sunrise,sunset,weathercode&timezone=Europe/Berlin"
        "&current_weather=true"
        "&timeformat=unixtime"
        "&start_date=%s"
        "&end_date=%s", sdate, edate );

    struct user_data ud = {
        .buffer = (uint8_t*) buf,
        .idx    = 0,
    };

    ESP_LOGI(TAG, "Getting Weather from: http://api.open-meteo.com%s\n", path);

    esp_http_client_config_t cfg = {
        .host                  = "api.open-meteo.com",
        .port                  = 80,
        .path                  = path,
        .query                 = NULL,
        .event_handler         = _http_event_handler,
        .user_data             = &ud,
        .disable_auto_redirect = false,
    };
    esp_http_client_handle_t client = esp_http_client_init(&cfg);

    esp_err_t err = esp_http_client_perform(client);

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "HTTP Get %d:  %d", err,
                 esp_http_client_get_status_code(client));
    }

    ESP_LOGI(TAG, "Response: %s", buf);
    return err;
}