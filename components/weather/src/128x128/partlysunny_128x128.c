#include "weather.h"
#define PARTLYSUNNY_128X128_WIDTH 128 
#define PARTLYSUNNY_128X128_HEIGHT 128 
const struct icon icon_partlysunny_128x128 = {
    .w = PARTLYSUNNY_128X128_WIDTH,
    .h = PARTLYSUNNY_128X128_HEIGHT,
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
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x7f, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x7f, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xe0, 0x7f, 
        0xff, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0x0f, 0xff, 0xe0, 0x7f, 0xff, 0x83, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xf0, 0x7f, 0xff, 0x03, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xf8, 0xff, 
        0xfe, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
        0x01, 0xff, 0xff, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x07, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xff, 
        0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xc0, 0x7f, 0xf0, 0x7f, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0x80, 0x0f, 0xf0, 0x3f, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7e, 0x00, 0x03, 
        0xf8, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xf8, 0xf8, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x1f, 0xc0, 
        0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xc0, 0x7f, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x83, 0xff, 0xfe, 
        0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0x07, 0xff, 0xfe, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0f, 0xff, 0xff, 
        0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xfe, 0x0f, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xff, 0xff, 
        0x83, 0xe0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xfe, 0x1f, 0xff, 0xff, 0x83, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0x83, 0xc0, 0x03, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 
        0x83, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0x83, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0x80, 0x3f, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xfc, 
        0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
        0x00, 0x00, 0x3f, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x3f, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x07, 0xe0, 
        0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
        0x3f, 0x80, 0x03, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xf0, 0x03, 0xff, 0xf8, 0x01, 0xf1, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xfe, 0x00, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x1f, 
        0xff, 0xff, 0x00, 0x7f, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xf8, 0x00, 0x80, 0x7f, 0xff, 0xff, 0xc0, 0x7f, 0xf0, 0x3f, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xe0, 0x3f, 
        0xf0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x01, 0xff, 
        0xff, 0xff, 0xf0, 0x1f, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xf8, 0x0f, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf8, 0x0f, 
        0xfc, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x30, 0x07, 0xff, 
        0xff, 0xff, 0xfc, 0x0f, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
        0x03, 0xfe, 0x07, 0xff, 0xff, 0xff, 0xfc, 0x07, 0xff, 0x03, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xfe, 0x07, 
        0xff, 0x83, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xef, 0xff, 
        0xff, 0xff, 0xfe, 0x07, 0xff, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
        0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x7f, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xf8, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
        0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xfe, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x07, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 
        0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x78, 0x00, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0x00, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x07, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x3f, 0xff, 0xff, 
        0xff, 0xfc, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xf0, 0x1f, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xff, 
        0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xfc, 0x0f, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x07, 0xff, 0xff, 
        0xff, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xfe, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xff, 
        0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xfe, 0x07, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 
        0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xfc, 0x0f, 0xff, 0xff, 0xff, 0xfc, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xfe, 0x07, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 
        0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xe0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xff, 
        0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0x80, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
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
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    }
};
