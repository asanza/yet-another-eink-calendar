#include "weather.h"
#define NT_MOSTLYCLOUDY_16X16_WIDTH 16 
#define NT_MOSTLYCLOUDY_16X16_HEIGHT 16 
const struct icon icon_nt_mostlycloudy_16x16 = {
    .w = NT_MOSTLYCLOUDY_16X16_WIDTH,
    .h = NT_MOSTLYCLOUDY_16X16_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0x87, 0xff, 0xb3, 0xff, 0xb9, 
        0xfe, 0x0b, 0xf0, 0xe7, 0xe7, 0xe7, 0xe7, 0xf7, 0x8f, 0xf3, 0x9f, 0xf9, 
        0x9f, 0xf9, 0xc0, 0x01, 0xe0, 0x03, 0xff, 0xff, 
    }
};
