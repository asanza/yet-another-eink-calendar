#include "weather.h"
#define NT_FLURRIES_16X16_WIDTH 16 
#define NT_FLURRIES_16X16_HEIGHT 16 
const struct icon icon_nt_flurries_16x16 = {
    .w = NT_FLURRIES_16X16_WIDTH,
    .h = NT_FLURRIES_16X16_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0x1f, 0xfe, 0x0f, 0xf0, 0xe7, 0xe7, 0xf7, 0xcf, 0xf3, 
        0x9f, 0xf1, 0x9f, 0xfd, 0x9f, 0xfd, 0xc0, 0x81, 0xe4, 0xa7, 0xfa, 0x5f, 
        0xfa, 0x4f, 0xfd, 0xbf, 0xfc, 0xbf, 0xff, 0xff, 
    }
};
