#include "weather.h"
#define NT_SUNNY_64X64_WIDTH 64 
#define NT_SUNNY_64X64_HEIGHT 64 
const struct icon icon_nt_sunny_64x64 = {
    .w = NT_SUNNY_64X64_WIDTH,
    .h = NT_SUNNY_64X64_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x01, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xe0, 0x21, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xe1, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x83, 0xe1, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0x07, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0f, 0xe1, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xe1, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xfc, 0x3f, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 0xf0, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x7f, 0xf0, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xf0, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xf8, 
        0x7f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xff, 
        0xff, 0xe1, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xfc, 
        0x1f, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0xff, 
        0xff, 0xe1, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 
        0x01, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xff, 
        0xff, 0xe1, 0xff, 0xff, 0xe0, 0x1f, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 
        0xf0, 0x01, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 0xf8, 0x00, 0x07, 0xff, 
        0xff, 0xe1, 0xff, 0xff, 0xfe, 0x00, 0x07, 0xff, 0xff, 0xf0, 0xff, 0xff, 
        0xff, 0x80, 0x07, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 
        0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xf8, 0x7f, 0xff, 
        0xff, 0xfe, 0x0f, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0xfe, 0x1f, 0xff, 
        0xff, 0xfc, 0x3f, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xfc, 0x1f, 0xff, 
        0xff, 0xf8, 0x3f, 0xff, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0xf0, 0x7f, 0xff, 
        0xff, 0xff, 0x07, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x83, 0xff, 
        0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0x01, 0xff, 0xff, 
        0xff, 0xff, 0xe0, 0x3f, 0xfc, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 
        0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
        0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    }
};
