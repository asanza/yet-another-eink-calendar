#include "weather.h"
#define NT_PARTLYCLOUDY_16X16_WIDTH 16 
#define NT_PARTLYCLOUDY_16X16_HEIGHT 16 
const struct icon icon_nt_partlycloudy_16x16 = {
    .w = NT_PARTLYCLOUDY_16X16_WIDTH,
    .h = NT_PARTLYCLOUDY_16X16_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xfe, 0x5f, 0xfe, 0xdf, 0xfe, 0xcf, 
        0xfe, 0xe1, 0xfe, 0x79, 0xf0, 0x33, 0xe3, 0x87, 0xcf, 0x9f, 0xcf, 0x8f, 
        0x9f, 0xef, 0xc0, 0x0f, 0xe0, 0x1f, 0xff, 0xff, 
    }
};
