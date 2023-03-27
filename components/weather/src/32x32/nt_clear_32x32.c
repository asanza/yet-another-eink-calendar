#include "weather.h"
#define NT_CLEAR_32X32_WIDTH 32 
#define NT_CLEAR_32X32_HEIGHT 32 
const struct icon icon_nt_clear_32x32 = {
    .w = NT_CLEAR_32X32_WIDTH,
    .h = NT_CLEAR_32X32_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 
        0xff, 0xe0, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0x0c, 0xff, 0xff, 
        0xff, 0x3c, 0xff, 0xff, 0xfe, 0x3c, 0xff, 0xff, 0xfc, 0x7c, 0xff, 0xff, 
        0xfc, 0xfc, 0xff, 0xff, 0xfc, 0xfe, 0x7f, 0xff, 0xf8, 0xfe, 0x3f, 0xff, 
        0xf8, 0xff, 0x1f, 0xff, 0xf8, 0xff, 0x87, 0xff, 0xf8, 0xff, 0xc0, 0x3f, 
        0xfc, 0xff, 0xf0, 0x3f, 0xfc, 0xff, 0xfe, 0x3f, 0xfc, 0x7f, 0xfe, 0x3f, 
        0xfe, 0x3f, 0xfe, 0x7f, 0xff, 0x1f, 0xfc, 0x7f, 0xff, 0x0f, 0xf0, 0xff, 
        0xff, 0xc1, 0x81, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xfc, 0x3f, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    }
};
