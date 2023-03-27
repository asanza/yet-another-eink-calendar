/*
    FemtoGUI

    fgui_helper.h:
        Internal helper include file

    copyright:
              Copyright (c) 2006-2008 Bastiaan van Kesteren <bastiaanvankesteren@gmail.com>

              This program comes with ABSOLUTELY NO WARRANTY; for details see the file LICENSE.
              This program is free software; you can redistribute it and/or modify it under the terms
              of the GNU General Public License as published by the Free Software Foundation; either
              version 2 of the License, or (at your option) any later version.

    remarks:
        Don't include this file in your application code
*/
#ifndef FGUI_HELPER_H
#define FGUI_HELPER_H

#ifndef FGUI_CODE
#error Do not include this file!
#endif

#include "fgui_font.h"
#include "fgui.h"

struct fgui{

    /* Foreground color */
    unsigned char fgcolor;
    /* Background color */
    unsigned char bgcolor;

    /* Points to the black framebuffer */
    unsigned char *fb;
    /* the red framebuffer */
    unsigned char *fr;
    /* the buffer length in bytes */
    int buflen;

    draw_buf_fn draw_fn;
    const void *usr_ctx;

    /* the screen width in bytes, with 1 bit per pixel. */
    int bytew;
    /* screen width in pixels */
    int width;
    /* screen width in pixels */
    int height;

    char *printbuf;
    int printbuflen;

    fgui_font_t font; 
};

unsigned int bitstobytesup(const unsigned int bits);
unsigned int bitstobytesdown(const unsigned int bits);
void copypixeldata(fgui_t fgui, int x, int y, const unsigned char *pixeldata, int w, int h, unsigned int bytew, unsigned char fgcolor);

#endif /* FGUI_HELPER_H */