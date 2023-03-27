#include "weather-icons.h"
#include "weather.h"
#include <string.h>

#define ARRAY_SIZE(x) ((sizeof(x) / sizeof(x[0])))

int
wmo_code_from_str(const char *code_str)
{
    char *end;
    int   code = strtol(code_str, &end, 10);
    if (code >= 0 && code < 100)
        return code;
    return code;
}

static const struct icon *
icon_from_table(int code, const struct open_weather_icon *table, int len)
{
    for (int i = 0; i < len; i++) {
        if (code == table[i].code) {
            return table[i].icon;
        }
    }
    return table[len - 1].icon;
}

static const char *
description_from_table(int code, const struct open_weather_icon *table, int len)
{
    for (int i = 0; i < len; i++) {
        if (code == table[i].code) {
            return table[i].description;
        }
    }
    return table[len - 1].description;
}

const struct open_weather_icon *
get_icon_table(int *len, bool day, enum wmo_icon_size sz)
{
    const struct open_weather_icon *table;
    if (day) {
        switch (sz) {
        case WMO_ICON_SIZE_16x16:
            table = day_weather_icons_16x16;
            *len  = ARRAY_SIZE(day_weather_icons_16x16);
            break;
        case WMO_ICON_SIZE_32x32:
            table = day_weather_icons_32x32;
            *len  = ARRAY_SIZE(day_weather_icons_32x32);
            break;
        case WMO_ICON_SIZE_64x64:
            table = day_weather_icons_64x64;
            *len  = ARRAY_SIZE(day_weather_icons_64x64);
            break;
        default:
            table = day_weather_icons_128x128;
            *len  = ARRAY_SIZE(day_weather_icons_128x128);
            break;
        }
    } else {
        switch (sz) {
        case WMO_ICON_SIZE_16x16:
            table = night_weather_icons_16x16;
            *len  = ARRAY_SIZE(day_weather_icons_16x16);
            break;
        case WMO_ICON_SIZE_32x32:
            table = night_weather_icons_32x32;
            *len  = ARRAY_SIZE(day_weather_icons_32x32);
            break;
        case WMO_ICON_SIZE_64x64:
            table = night_weather_icons_64x64;
            *len  = ARRAY_SIZE(day_weather_icons_64x64);
            break;
        default:
            table = night_weather_icons_128x128;
            *len = ARRAY_SIZE(day_weather_icons_128x128);
            break;
        }
    }
    return table;
}

const struct icon *
wmo_icon_from_code(int code, bool day, enum wmo_icon_size size)
{
    const struct open_weather_icon *table;
    int                             len;
    table = get_icon_table(&len, day, size);
    return icon_from_table(code, table, len);
}

const char *
wmo_description_from_code(int code)
{
    const struct open_weather_icon *table;
    int                             len;
    table = get_icon_table(&len, true, WMO_ICON_SIZE_128x128);
    return description_from_table(code, table, len);
}
