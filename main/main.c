/* WiFi station Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <string.h>
#include "esp_log.h"
#include "esp_system.h"
#include <nvs_flash.h>
#include <driver/gpio.h>
#include "priv_epaper.h"
#include "priv_wifi.h"
#include "esp_sleep.h"
#include "driver/rtc_io.h"
#include "no-wifi.c"
#include <weather.h>
#include <weather-json.h>
#include <stdint.h>
#include <sys/time.h>

#define TIME_MS2US(s) ((s) * 1000ULL)

static const char *TAG = "main";

#define LED_PIN GPIO_NUM_2

#define DEEP_SLEP_TIME_MS (3600 * 1000ULL)


static uint32_t get_sleep_time( void ) {
    static RTC_DATA_ATTR struct timeval sleep_enter_time;
    struct timeval now;
    int sleep_time_ms;
    gettimeofday(&now, NULL);

    sleep_time_ms = now.tv_sec - sleep_enter_time.tv_sec *1000 + 
        now.tv_usec - sleep_enter_time.tv_usec;
    return sleep_time_ms;
}

void app_main(void)
{
    switch(esp_sleep_get_wakeup_cause()) {
        case ESP_SLEEP_WAKEUP_TIMER:
            ESP_LOGI(TAG, "Waking up from deep sleep after %lu ms!.", get_sleep_time());
            break;
        default:
        break;
    }

	//Initialize NVS
	esp_err_t ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES ||
	    ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

    gpio_config_t gpioconf = {
        .pin_bit_mask = BIT(LED_PIN),
        .mode = GPIO_MODE_DEF_OUTPUT,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };

    gpio_config(&gpioconf);

    /* allocate buffers for the epaper */
    uint8_t* rbuf = calloc(1, 100 * 480);
    uint8_t* bbuf = calloc(1, 100 * 480);

    assert(rbuf);
    assert(bbuf);

    ESP_LOGI(TAG, "INIT EPAPER");
    priv_epaper_init();

  	ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
	if( priv_wifi_init() != WIFI_ERR_NONE ) {
        ESP_LOGE(TAG, "Could not connect!");
        memcpy(bbuf, no_wifi, sizeof(no_wifi));
        goto exit;
    }

    /* these buffers are big, so we reuse them to get the weather data */
    ret = priv_wifi_get_open_meteo((char*)bbuf);
    if( ret != WIFI_ERR_NONE ) {
        memcpy(bbuf, no_wifi, sizeof(no_wifi));
        goto exit;
    }

    struct wmo_weather* weather;
    weather = wmo_get_weather_from_json(bbuf, 100 * 480);

    priv_epaper_draw_calendar((char*) bbuf, bbuf, rbuf, ret == ESP_OK);
    priv_epaper_draw_weather(weather);



    // ret = priv_wifi_get_image(bbuf);

    // if( ret != ESP_OK ) {
    //     /* we coudn't connect to the image server, so we raster our own. */
    //     priv_epaper_draw_fgui(rbuf, bbuf);
    // }


exit:
    priv_epaper_draw(bbuf, rbuf);
    priv_epaper_sleep();

    /* configure deep sleep wakeup. Wakeup each hour */
    priv_wifi_stop();
    rtc_gpio_isolate(GPIO_NUM_12);
    ESP_LOGI(TAG, "Going to deep sleep. See ya!");
    ret = esp_sleep_enable_timer_wakeup(TIME_MS2US(DEEP_SLEP_TIME_MS));
    ESP_ERROR_CHECK(ret);

    esp_deep_sleep_start();
}