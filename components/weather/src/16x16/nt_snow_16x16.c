#include "weather.h"
#define NT_SNOW_16X16_WIDTH 16 
#define NT_SNOW_16X16_HEIGHT 16 
const struct icon icon_nt_snow_16x16 = {
    .w = NT_SNOW_16X16_WIDTH,
    .h = NT_SNOW_16X16_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf2, 0x2f, 0xf1, 0x4f, 
        0xf9, 0xcf, 0xf6, 0x27, 0xe0, 0x03, 0xf4, 0x2f, 0xf9, 0x4f, 0xf2, 0x0f, 
        0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    }
};