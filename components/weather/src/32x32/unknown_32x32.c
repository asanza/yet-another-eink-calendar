#include "weather.h"
#define UNKNOWN_32X32_WIDTH 32 
#define UNKNOWN_32X32_HEIGHT 32 
const struct icon icon_unknown_32x32 = {
    .w = UNKNOWN_32X32_WIDTH,
    .h = UNKNOWN_32X32_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xfe, 0x01, 0xff, 
        0xff, 0xfc, 0x70, 0xff, 0xff, 0x81, 0xfc, 0x7f, 0xff, 0x01, 0xfe, 0x7f, 
        0xfe, 0x3a, 0x1f, 0x3f, 0xfe, 0x7c, 0x0f, 0x3f, 0xfe, 0xfc, 0xcf, 0x3f, 
        0xf8, 0xfc, 0xcf, 0x3f, 0xf0, 0xff, 0x9e, 0x0f, 0xf3, 0xff, 0x3f, 0xc7, 
        0xe7, 0xff, 0x3f, 0xe7, 0xe7, 0xff, 0x3f, 0xf3, 0xe7, 0xff, 0xff, 0xf3, 
        0xe7, 0xff, 0x3f, 0xf3, 0xf3, 0xff, 0x7f, 0xe7, 0xf8, 0x00, 0x80, 0x07, 
        0xfc, 0x00, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    }
};