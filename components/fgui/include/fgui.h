/*
    FemtoGUI

    fgui->h:
       Main include file

    copyright:
              Copyright (c) 2006-2008 Bastiaan van Kesteren <bastiaanvankesteren@gmail.com>

              This program comes with ABSOLUTELY NO WARRANTY; for details see the file LICENSE.
              This program is free software; you can redistribute it and/or modify it under the terms
              of the GNU General Public License as published by the Free Software Foundation; either
              version 2 of the License, or (at your option) any later version.

*/
#ifndef FGUI_H
#define FGUI_H

#include "fgui_font.h"

typedef struct fgui* fgui_t;

#define FGUI_VERSION "0.5"

#define FGUI_BLACK    0xFF
#define FGUI_RED      0xAA
#define FGUI_WHITE    0x00

struct fgui_icon {
    uint16_t width;
    uint16_t height;
    uint8_t data[];
}__attribute__((packed));

typedef void (*draw_buf_fn)(const void* ctx, unsigned char* black, unsigned char* red, int len);

/* General functions */
fgui_t fgui_init(int width, int height, draw_buf_fn draw, const void* ctx, uint8_t* rbuf, uint8_t* bbuf);
void fgui_clear(fgui_t f);
void fgui_clearregion(fgui_t f, int x, int y, unsigned int w, unsigned int h);
void fgui_fillregion(fgui_t f, int x, int y, unsigned int w, unsigned int h);
char fgui_refresh(fgui_t f);
void fgui_set_fgcolor(fgui_t f, const unsigned char newcolor);
void fgui_set_bgcolor(fgui_t f, const unsigned char newcolor);
unsigned char fgui_get_fgcolor(fgui_t f);
unsigned char fgui_get_fbcolor(fgui_t f);

/* Pixel functions */
void fgui_pixelon(fgui_t f, const unsigned int x, const unsigned int y);
void fgui_pixeloff(fgui_t f, const unsigned int x, const unsigned int y);
void fgui_pixel(fgui_t f, const unsigned int x, const unsigned int y, const unsigned char value);

/* Line functions */
void fgui_line(fgui_t f, const unsigned int x0, const unsigned int y0, const unsigned int x1, const unsigned int y1);
void fgui_lineh(fgui_t f, const unsigned int x, const unsigned int y, unsigned int l);
void fgui_linev(fgui_t f, const unsigned int x, const unsigned int y, unsigned int l);

/* Sprite functions */
void fgui_sprite(fgui_t fgui, const int x, const int y, const unsigned char *sprite);
int fgui_spritewidth(const unsigned char *sprite);
int fgui_spriteheight(const unsigned char *sprite);

/* Text functions */
void fgui_setfont(fgui_t fgui, fgui_font_t font);
unsigned char fgui_charheight(fgui_t fgui);
unsigned char fgui_charwidth(fgui_t fgui);
unsigned int fgui_strlen(fgui_t fgui, const char *s);
void fgui_char(fgui_t fgui, const int x, const int y, const char c);
void fgui_text(fgui_t fgui, int x, const int y, const char *str);

void fgui_subimage(fgui_t fgui, const int x, const int y, const struct fgui_icon* icn);


#endif /* FGUI_H */
