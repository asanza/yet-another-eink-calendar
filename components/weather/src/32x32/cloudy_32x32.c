#include "weather.h"
#define CLOUDY_32X32_WIDTH 32 
#define CLOUDY_32X32_HEIGHT 32 
const struct icon icon_cloudy_32x32 = {
    .w = CLOUDY_32X32_WIDTH,
    .h = CLOUDY_32X32_HEIGHT,
    .data = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xfe, 0x03, 0xff, 
        0xff, 0xfc, 0x30, 0xff, 0xff, 0x80, 0xfc, 0x7f, 0xff, 0x01, 0xfe, 0x7f, 
        0xfe, 0x3b, 0xff, 0x3f, 0xfe, 0x7f, 0xff, 0x3f, 0xfe, 0xff, 0xff, 0x3f, 
        0xfc, 0x7f, 0xff, 0x3f, 0xf0, 0xff, 0xfe, 0x0f, 0xf3, 0xff, 0xff, 0xc7, 
        0xe7, 0xff, 0xff, 0xe7, 0xe7, 0xff, 0xff, 0xf3, 0xe7, 0xff, 0xff, 0xf3, 
        0xe7, 0xff, 0xff, 0xf3, 0xf3, 0xff, 0xff, 0xe7, 0xf0, 0x00, 0x00, 0x07, 
        0xfc, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    }
};
