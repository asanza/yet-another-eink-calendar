/*
    FemtoGUI

    fgui->c:
        Main code

    copyright:
              Copyright (c) 2006-2008 Bastiaan van Kesteren
   <bastiaanvankesteren@gmail.com>

              This program comes with ABSOLUTELY NO WARRANTY; for details see
   the file LICENSE. This program is free software; you can redistribute it
   and/or modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the License,
   or (at your option) any later version.

    remarks:

*/
#include "fgui.h"
#include "fgui_config.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define FGUI_CODE
#include "fgui_helper.h"

struct fgui *fgui;

/*
  Set console parameters and initialise the screen by calling screen_init().
  Returncode is the result of screen_init(), which should be '1' on success
*/
struct fgui *
fgui_init(int width, int height, draw_buf_fn drawbuf, const void *ctx, uint8_t *rbuf, uint8_t* bbuf)
{
    assert(width > 0 && height > 0);
    fgui         = malloc(sizeof(struct fgui));
    fgui->bytew  = ((width + 8 - 1) / 8);
    fgui->buflen = fgui->bytew * height;
    if( bbuf == NULL ) {
        fgui->fb     = malloc(fgui->buflen);
    } else {
        fgui->fb = bbuf;
    }

    if( rbuf == NULL ) {
        fgui->fr     = malloc(fgui->buflen);
    } else {
        fgui->fr = rbuf;
    }
    
    assert(fgui->fb);
    assert(fgui->fr);

    fgui->draw_fn = drawbuf;
    fgui->usr_ctx = ctx;

    fgui->fgcolor = FGUI_BLACK;
    fgui->bgcolor = FGUI_WHITE;
    fgui->width   = width;
    fgui->height  = height;
    fgui->font    = NULL;
    return fgui;
}

/*
  Clear framebuffer.
*/
void
fgui_clear(fgui_t f)
{
    /* clear the buffer */
    if (f->bgcolor == FGUI_RED) {
        memset(f->fb, 0xFF, fgui->buflen);
        memset(f->fr, 0xFF, fgui->buflen);
    } else if (f->bgcolor == FGUI_BLACK) {
        memset(f->fb, 0x00, fgui->buflen);
        memset(f->fr, 0x00, fgui->buflen);
    } else {
        memset(f->fb, 0xFF, fgui->buflen);
        memset(f->fr, 0x00, fgui->buflen);
    }
}

char
fgui_refresh(fgui_t fgui)
/*
  Update screen (as in, write contents of buffer to the screen).
  Returncode is the result of screen_update(), which should be '1' on success
*/
{
    if (fgui->draw_fn != NULL) {
        fgui->draw_fn(fgui->usr_ctx, fgui->fb, fgui->fr, fgui->buflen);
    }

    return 0;
}

void
fgui_set_fgcolor(fgui_t fgui, const unsigned char newcolor)
/*
  Set the foregroundcolor to use
*/
{
    if (newcolor == FGUI_BLACK || newcolor == FGUI_WHITE ||
        newcolor == FGUI_RED) {
        fgui->fgcolor = newcolor;
    }
}

void
fgui_set_bgcolor(fgui_t fgui, const unsigned char newcolor)
/*
  Set the backgroundcolor to use
*/
{
    if (newcolor == FGUI_BLACK || newcolor == FGUI_WHITE ||
        newcolor == FGUI_RED) {
        fgui->bgcolor = newcolor;
    }
}

unsigned char
fgui_get_fgcolor(fgui_t fgui)
/*
  Return the current foregroundcolor
*/
{
    return fgui->fgcolor;
}

unsigned char
fgui_get_fbcolor(fgui_t fgui)
{
    return fgui->fgcolor;
}

/*
  Pixel functions
*/

void
fgui_pixelon(fgui_t fgui, const unsigned int x, const unsigned int y)
/*
  Turn pixel at location x,y on (foreground color)
*/
{
    fgui_pixel(fgui, x, y, fgui->fgcolor);
}

void
fgui_pixeloff(fgui_t fgui, const unsigned int x, const unsigned int y)
/*
  Turn pixel at location x,y off (background color)
*/
{
    fgui_pixel(fgui, x, y, fgui->bgcolor);
}

/*
  Set pixel at location x,y on (value == FGUI_BLACK) or off (value ==
  FGUI_WHITE)
*/
void
fgui_pixel(fgui_t fgui, const unsigned int x, const unsigned int y,
           const unsigned char value)
{
    uint32_t pos = y * fgui->bytew + bitstobytesdown(x);
    uint32_t bitmask = 1 << (7 - (x % 8));

    if (x < fgui->width && y < fgui->height) {
        if (value == FGUI_BLACK) {
            fgui->fb[pos] &= ~(bitmask);
            fgui->fr[pos] &= ~(bitmask);
        } else if (value == FGUI_RED) {
            fgui->fr[pos] |= bitmask;
            fgui->fb[pos] |= (bitmask);
        } else if (value == FGUI_WHITE) {
            fgui->fb[pos] |= (bitmask);
            fgui->fr[pos] &= ~(bitmask);
        }
    }
}
