#include "weather.h"
#define SLEET_16X16_WIDTH 16 
#define SLEET_16X16_HEIGHT 16 
const struct icon icon_sleet_16x16 = {
    .w = SLEET_16X16_WIDTH,
    .h = SLEET_16X16_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xfe, 0x0f, 0xf0, 0xe7, 0xe1, 0xe7, 0xe7, 0xf7, 
        0xcf, 0xf3, 0x9f, 0xf9, 0x9f, 0xfd, 0x8c, 0x99, 0xc0, 0x03, 0xf8, 0x3f, 
        0xf8, 0x3f, 0xf2, 0x7f, 0xf0, 0x7f, 0xff, 0xff, 
    }
};
