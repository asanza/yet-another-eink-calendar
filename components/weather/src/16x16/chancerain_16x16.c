#include "weather.h"
#define CHANCERAIN_16X16_WIDTH 16 
#define CHANCERAIN_16X16_HEIGHT 16 
const struct icon icon_chancerain_16x16 = {
    .w = CHANCERAIN_16X16_WIDTH,
    .h = CHANCERAIN_16X16_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xfe, 0x0f, 0xf0, 0xc7, 0xe1, 0xe7, 0xe7, 0xf7, 
        0xcf, 0xf3, 0x9f, 0xf9, 0x9f, 0xfd, 0x8f, 0xf9, 0xc0, 0x03, 0xfd, 0x3f, 
        0xfa, 0x7f, 0xf0, 0x7f, 0xf0, 0xff, 0xff, 0xff, 
    }
};
