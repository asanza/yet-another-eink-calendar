#include "weather.h"
#define NT_MOSTLYCLOUDY_32X32_WIDTH 32 
#define NT_MOSTLYCLOUDY_32X32_HEIGHT 32 
const struct icon icon_nt_mostlycloudy_32x32 = {
    .w = NT_MOSTLYCLOUDY_32X32_WIDTH,
    .h = NT_MOSTLYCLOUDY_32X32_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xf0, 0xff, 
        0xff, 0xff, 0xe2, 0xff, 0xff, 0xff, 0xe6, 0x7f, 0xff, 0xff, 0xee, 0x3f, 
        0xff, 0xff, 0xef, 0x0f, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xcf, 0xe7, 
        0xff, 0xfe, 0x03, 0xc7, 0xff, 0xfc, 0x70, 0xcf, 0xff, 0x80, 0xfc, 0xff, 
        0xff, 0x01, 0xfe, 0x7f, 0xfe, 0x3b, 0xfe, 0x7f, 0xfe, 0x7f, 0xff, 0x3f, 
        0xfe, 0x7f, 0xff, 0x3f, 0xf8, 0x7f, 0xff, 0x3f, 0xf0, 0xff, 0xfe, 0x0f, 
        0xf3, 0xff, 0xff, 0xc7, 0xe7, 0xff, 0xff, 0xe7, 0xe7, 0xff, 0xff, 0xf3, 
        0xe7, 0xff, 0xff, 0xf3, 0xe3, 0xff, 0xff, 0xe7, 0xf3, 0xff, 0xff, 0xc7, 
        0xf8, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    }
};
