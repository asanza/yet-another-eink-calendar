#include "weather.h"
#define NT_RAIN_16X16_WIDTH 16 
#define NT_RAIN_16X16_HEIGHT 16 
const struct icon icon_nt_rain_16x16 = {
    .w = NT_RAIN_16X16_WIDTH,
    .h = NT_RAIN_16X16_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0x1f, 0xfe, 0x0f, 0xf0, 0xe7, 0xe7, 0xf7, 0xcf, 0xf3, 
        0x9f, 0xf1, 0x9f, 0xfd, 0x9f, 0xbd, 0xc0, 0x01, 0xe0, 0x07, 0xf8, 0x3f, 
        0xf8, 0x3f, 0xf8, 0x7f, 0xfd, 0xff, 0xff, 0xff, 
    }
};
