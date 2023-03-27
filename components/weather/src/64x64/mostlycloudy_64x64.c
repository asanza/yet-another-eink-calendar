#include "weather.h"
#define MOSTLYCLOUDY_64X64_WIDTH 64 
#define MOSTLYCLOUDY_64X64_HEIGHT 64 
const struct icon icon_mostlycloudy_64x64 = {
    .w = MOSTLYCLOUDY_64X64_WIDTH,
    .h = MOSTLYCLOUDY_64X64_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0x3f, 0xc7, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xfe, 
        0x1f, 0xcf, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xe1, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xc6, 0x01, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xec, 0x00, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xf8, 0x78, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xf0, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xff, 0x1f, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xe3, 0xff, 0x98, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 0x98, 0x1f, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x98, 0x1f, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x03, 0xff, 0x3f, 0xff, 
        0xff, 0xff, 0xff, 0xf8, 0x00, 0x7e, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xe0, 
        0x00, 0x3c, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xf8, 0x1c, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x83, 0xff, 0x0f, 0xcf, 0xff, 0xff, 0xff, 0xc0, 0x07, 
        0xff, 0x87, 0xc7, 0xff, 0xff, 0xff, 0x00, 0x0f, 0xff, 0xc3, 0xc3, 0xff, 
        0xff, 0xfe, 0x00, 0x1f, 0xff, 0xe3, 0xe1, 0xff, 0xff, 0xfc, 0x1f, 0x3f, 
        0xff, 0xe1, 0xf1, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xf1, 0xfb, 0xff, 
        0xff, 0xf8, 0x7f, 0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 
        0xff, 0xf1, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 
        0xff, 0xf8, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 
        0xff, 0xf0, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xe0, 0x3f, 0xff, 
        0xff, 0x83, 0xff, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0x0f, 0xff, 0xff, 
        0xff, 0xee, 0x0f, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 
        0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xfe, 0x3f, 0xff, 0xff, 
        0xff, 0xff, 0xe3, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 
        0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xfc, 0x3f, 0xff, 0xff, 
        0xff, 0xff, 0xe3, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 
        0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xff, 
        0xff, 0xff, 0xc3, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 
        0xff, 0x83, 0xff, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xff, 0xc0, 0x00, 0x00, 
        0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 
        0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    }
};
