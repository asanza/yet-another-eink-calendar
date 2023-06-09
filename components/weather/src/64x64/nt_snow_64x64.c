#include "weather.h"
#define NT_SNOW_64X64_WIDTH 64 
#define NT_SNOW_64X64_HEIGHT 64 
const struct icon icon_nt_snow_64x64 = {
    .w = NT_SNOW_64X64_WIDTH,
    .h = NT_SNOW_64X64_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x33, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xef, 0x31, 0x23, 0x7d, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x38, 
        0x06, 0x39, 0xff, 0xff, 0xff, 0xff, 0xe3, 0x3c, 0x0e, 0x31, 0xff, 0xff, 
        0xff, 0xff, 0xf1, 0x3e, 0x1e, 0x23, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 
        0x3e, 0x07, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0x3e, 0x0f, 0xff, 0xff, 
        0xff, 0xff, 0xc0, 0x3f, 0x3e, 0x01, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x1f, 
        0x3e, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x3c, 0x7f, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xc7, 0x38, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xe3, 
        0x31, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0x8f, 0xf1, 0x23, 0xfc, 0x7f, 0xff, 
        0xff, 0xff, 0xc7, 0xf8, 0x07, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xfc, 
        0x0f, 0xf1, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 
        0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xe3, 0xfc, 
        0x0f, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xf8, 0x07, 0xf8, 0xff, 0xff, 
        0xff, 0xff, 0x8f, 0xf1, 0x23, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0x9f, 0xe3, 
        0x31, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x38, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xe1, 0x0f, 0x3c, 0x63, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x1f, 
        0x3e, 0x01, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x3f, 0x3e, 0x01, 0xff, 0xff, 
        0xff, 0xff, 0xfc, 0x3f, 0x3e, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 
        0x3e, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf1, 0x3e, 0x1e, 0x23, 0xff, 0xff, 
        0xff, 0xff, 0xc3, 0x3c, 0x0e, 0x31, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x38, 
        0x06, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0x23, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xf3, 0x33, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    }
};
