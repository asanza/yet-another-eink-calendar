#include <weather.h>
#include <cJSON.h>
#include <string.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <esp_log.h>

#define TAG "wjson"

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

struct wmo_weather *
wmo_get_weather_from_json(const uint8_t *buf, int len)
{
    struct wmo_weather* w = NULL;
    cJSON *json = cJSON_ParseWithLength((const char*)buf, len);
    const cJSON *cw;
    cJSON *tmp, *el, *t;
    int idx = 0; 

    if( json == NULL) {
        printf("Error Parsing Json: \n");
        goto exit;
    }

    cw = cJSON_GetObjectItem(json, "current_weather");

    if( cw == NULL ) {
        printf("No current weather\n");
        goto exit;
    }

    w = calloc(1, sizeof(struct wmo_weather));
    tmp = cJSON_GetObjectItem(cw, "is_day");
    w->current.is_day = cJSON_GetNumberValue(tmp);
    tmp = cJSON_GetObjectItem(cw, "temperature");
    w->current.temp = cJSON_GetNumberValue(tmp);
    tmp = cJSON_GetObjectItem(cw, "weathercode");
    w->current.wno_code = cJSON_GetNumberValue(tmp);

    cw = cJSON_GetObjectItem(json, "hourly");
    
    if( cw == NULL ) {
        printf("No hourly\n");
        goto exit;
    }

    int now = time(NULL) + 1800;

    tmp = cJSON_GetObjectItem(cw, "time");

    for(int i = 0; i < cJSON_GetArraySize(tmp); i++)
    {
        el = cJSON_GetArrayItem(tmp, i);
        if( el->valueint > now ) {
            w->hourly.timestamp[idx] = el->valueint;
            t = cJSON_GetObjectItem(cw, "temperature_2m");
            el = cJSON_GetArrayItem(t, i);
            w->hourly.temperature_2m[idx] = el->valuedouble;
            t = cJSON_GetObjectItem(cw, "weathercode");
            el = cJSON_GetArrayItem(t, i);
            w->hourly.wmo_code[idx] = el->valueint;
            t = cJSON_GetObjectItem(cw, "precipitation");
            el = cJSON_GetArrayItem(t, i);
            w->hourly.precipitation[idx] = el->valuedouble;

            if( idx++ >= ARRAY_SIZE(w->hourly.timestamp) - 1){
                break;
            }
        }
    }

    cw = cJSON_GetObjectItem(json, "daily");
    tmp = cJSON_GetObjectItem(cw, "sunrise");

    for( int i = 0; i < cJSON_GetArraySize(tmp); i++) {
        el = cJSON_GetArrayItem(tmp, i);
        w->daily.sunrise[i] = el->valueint;
        t = cJSON_GetObjectItem(cw, "sunset");
        el = cJSON_GetArrayItem(t, i);
        w->daily.sunset[i] = el->valueint;
    }

exit:
    cJSON_Delete(json);
    return w;
}

