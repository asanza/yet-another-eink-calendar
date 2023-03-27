#include "weather.h"
#define NT_CLOUDY_64X64_WIDTH 64 
#define NT_CLOUDY_64X64_HEIGHT 64 
const struct icon icon_nt_cloudy_64x64 = {
    .w = NT_CLOUDY_64X64_WIDTH,
    .h = NT_CLOUDY_64X64_HEIGHT,
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
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xf8, 0x0e, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
        0x7f, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xe1, 0xff, 0xf0, 0xff, 0xff, 
        0xff, 0xff, 0xe0, 0x03, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0x80, 0x07, 
        0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x07, 0xff, 0xfe, 0x3f, 0xff, 
        0xff, 0xfe, 0x0f, 0xcf, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xfe, 0x3f, 0xff, 
        0xff, 0xff, 0x1f, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0x1f, 0xff, 
        0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xf8, 0x7f, 0xff, 
        0xff, 0xff, 0x1f, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0x1f, 0xff, 
        0xff, 0xf0, 0x7f, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xe0, 0x7f, 0xff, 
        0xff, 0xff, 0x07, 0xff, 0xff, 0xc0, 0x7f, 0xff, 0xff, 0xfe, 0x01, 0xff, 
        0xff, 0x87, 0xff, 0xff, 0xff, 0xfe, 0x00, 0xff, 0xff, 0x0f, 0xff, 0xff, 
        0xff, 0xff, 0xf0, 0x7f, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 
        0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xfe, 0x3f, 0xff, 0xff, 
        0xff, 0xff, 0xfe, 0x1f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 
        0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfc, 0x3f, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x0f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 
        0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfe, 0x3f, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x1f, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1f, 
        0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0x83, 0xff, 0xff, 
        0xff, 0xff, 0xf8, 0x7f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
        0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x00, 0x00, 
        0x00, 0x00, 0x03, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    }
};
