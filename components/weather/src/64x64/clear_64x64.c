#include "weather.h"
#define CLEAR_64X64_WIDTH 64 
#define CLEAR_64X64_HEIGHT 64 
const struct icon icon_clear_64x64 = {
    .w = CLEAR_64X64_WIDTH,
    .h = CLEAR_64X64_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
        0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
        0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xfc, 0xff, 0xff, 
        0xff, 0xff, 0xc7, 0xfe, 0x3f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0x83, 0xff, 
        0xff, 0xf0, 0x7f, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xff, 0xe0, 0xff, 0xff, 
        0xff, 0xff, 0xe0, 0xff, 0xff, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 
        0x07, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xe0, 0x01, 0xe7, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 
        0xf0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfc, 0x3f, 0xff, 0xff, 
        0xff, 0xff, 0xfe, 0x1f, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 
        0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0x0f, 0xff, 0xff, 
        0xff, 0xff, 0xfc, 0x7f, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xf0, 0x1c, 0x7f, 
        0xff, 0x8e, 0x07, 0xff, 0xff, 0xe0, 0x0c, 0x7f, 0xff, 0x8c, 0x03, 0xff, 
        0xff, 0xe0, 0x1c, 0x7f, 0xff, 0x8c, 0x03, 0xff, 0xff, 0xfb, 0xbc, 0x7f, 
        0xff, 0x8f, 0x6f, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0x8f, 0xff, 0xff, 
        0xff, 0xff, 0xfc, 0x3f, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 
        0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xfe, 0x1f, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x0f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x83, 
        0xf0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xf9, 0xe0, 0x01, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf8, 
        0x07, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xe1, 0xff, 0xff, 
        0xff, 0xff, 0xc1, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 
        0x3f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0x87, 0xfe, 0x3f, 0xfc, 0x7f, 0xff, 
        0xff, 0xff, 0xcf, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
        0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
        0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    }
};
