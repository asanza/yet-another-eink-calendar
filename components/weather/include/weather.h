#ifndef DA60435C_BD09_4BC7_91F9_EAF7E94802A9
#define DA60435C_BD09_4BC7_91F9_EAF7E94802A9

#include <stdint.h>
#include <stdbool.h>

struct icon {
    uint16_t w;
    uint16_t h;
    uint8_t  data[];
}__attribute__((packed));

enum wmo_icon_size {
    WMO_ICON_SIZE_16x16,
    WMO_ICON_SIZE_32x32,
    WMO_ICON_SIZE_64x64,
    WMO_ICON_SIZE_128x128,
};

struct wmo_current_weather {
    bool is_day;
    unsigned long wno_code;
    unsigned long timestamp;
    float temp;
    float windspeed;
    float winddirection;
};

struct wmo_daily_forecast {
    unsigned long sunrise[2];
    unsigned long sunset[2];
    unsigned long wno_code[2];
    float max_temp_2m[2];
    float min_temp_2m[2];
    float precipitation_probability_mean[2];
};

struct wmo_hourly_forecast {
    bool is_day[5];
    unsigned long wmo_code[5];
    float temperature_2m[5];
    float precipitation[5];
    unsigned long timestamp[5];
};

struct wmo_weather {
    struct wmo_current_weather current;
    struct wmo_hourly_forecast hourly;
    struct wmo_daily_forecast  daily;
};

int
wmo_perform_request();

int
wmo_code_from_str(const char *code_str);

const struct icon *
wmo_icon_from_code(int code, bool day, enum wmo_icon_size);

const char* 
wmo_description_from_code(int code);

#endif /* DA60435C_BD09_4BC7_91F9_EAF7E94802A9 */
