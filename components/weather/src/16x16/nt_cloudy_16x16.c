#include "weather.h"
#define NT_CLOUDY_16X16_WIDTH 16 
#define NT_CLOUDY_16X16_HEIGHT 16 
const struct icon icon_nt_cloudy_16x16 = {
    .w = NT_CLOUDY_16X16_WIDTH,
    .h = NT_CLOUDY_16X16_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xfe, 0x0f, 0xf0, 0xe7, 
        0xe7, 0xf7, 0xef, 0xf7, 0xcf, 0xf3, 0x9f, 0xf9, 0x9f, 0xfd, 0xc8, 0x01, 
        0xe0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    }
};
