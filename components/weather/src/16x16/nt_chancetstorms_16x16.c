#include "weather.h"
#define NT_CHANCETSTORMS_16X16_WIDTH 16 
#define NT_CHANCETSTORMS_16X16_HEIGHT 16 
const struct icon icon_nt_chancetstorms_16x16 = {
    .w = NT_CHANCETSTORMS_16X16_WIDTH,
    .h = NT_CHANCETSTORMS_16X16_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0x1f, 0xfe, 0x0f, 0xf0, 0xe7, 0xe7, 0xf7, 0xcf, 0xf3, 
        0x9f, 0xf1, 0x9f, 0x3d, 0x9f, 0x3d, 0xc2, 0x61, 0xe0, 0x27, 0xff, 0x3f, 
        0xfe, 0x7f, 0xfc, 0xff, 0xfc, 0xff, 0xff, 0xff, 
    }
};
