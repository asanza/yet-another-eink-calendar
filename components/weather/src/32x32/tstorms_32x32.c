#include "weather.h"
#define TSTORMS_32X32_WIDTH 32 
#define TSTORMS_32X32_HEIGHT 32 
const struct icon icon_tstorms_32x32 = {
    .w = TSTORMS_32X32_WIDTH,
    .h = TSTORMS_32X32_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0x03, 0xff, 0xff, 0xfe, 0x01, 0xff, 0xff, 0xec, 0xf8, 0xff, 
        0xff, 0x81, 0xfe, 0x7f, 0xff, 0x13, 0xfe, 0x7f, 0xfe, 0x7f, 0xff, 0x3f, 
        0xfe, 0x7f, 0xff, 0x3f, 0xfc, 0xff, 0xff, 0x3f, 0xf8, 0xff, 0xff, 0x1f, 
        0xf1, 0xff, 0xfe, 0x0f, 0xe3, 0xff, 0xff, 0xe7, 0xe7, 0xff, 0xff, 0xf3, 
        0xe7, 0xff, 0x9f, 0xf3, 0xe7, 0xff, 0x9f, 0xf3, 0xe3, 0xff, 0x3f, 0xe3, 
        0xf1, 0xfe, 0x7f, 0xc7, 0xf8, 0x0e, 0x78, 0x0f, 0xfc, 0x0c, 0xc8, 0x1f, 
        0xff, 0xf8, 0x0f, 0xff, 0xfe, 0x4f, 0x9b, 0x3f, 0xfe, 0x4f, 0x33, 0x3f, 
        0xfc, 0x9e, 0x32, 0x7f, 0xfc, 0x9e, 0x64, 0x7f, 0xfd, 0xbc, 0xe6, 0xff, 
        0xff, 0xfc, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    }
};
