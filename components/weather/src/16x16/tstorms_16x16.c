#include "weather.h"
#define TSTORMS_16X16_WIDTH 16 
#define TSTORMS_16X16_HEIGHT 16 
const struct icon icon_tstorms_16x16 = {
    .w = TSTORMS_16X16_WIDTH,
    .h = TSTORMS_16X16_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0x1f, 0xfc, 0x0f, 0xf0, 0xe7, 0xe7, 0xf7, 0xcf, 0xf3, 
        0x9f, 0xf1, 0x9f, 0xbd, 0x9f, 0x3d, 0xc2, 0x61, 0xe2, 0x27, 0xe3, 0x17, 
        0xe2, 0x47, 0xfe, 0xff, 0xfc, 0xff, 0xff, 0xff, 
    }
};
