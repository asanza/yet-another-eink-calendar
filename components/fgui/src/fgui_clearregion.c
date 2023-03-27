/*
    FemtoGUI

    fgui_clearregion.c:
        clearregion function

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

#define FGUI_CODE
#include "fgui_helper.h"

void
fgui_clearregion(fgui_t fgui, int x, int y, unsigned int w, unsigned int h)
/*
  Clear a region of the framebuffer at location x,y, with width 'w' and height
  'h'
*/
{
    unsigned int  cw, ch, bytestart;
    unsigned char bitmask;
    unsigned int  pos;

    /* Sanity check */
    if (x > fgui->width || y > fgui->height) {
        return;
    }
    if (x < 0) {
        x = 0;
    }
    if (y < 0) {
        y = 0;
    }
    if (x + w > fgui->width) {
        w = fgui->width - x;
    }
    if (y + h > fgui->height) {
        h = fgui->height - y;
    }

    if (x % 8 > 0) {
        /* Region is not byte-aligned with the framebuffer, bitshifting is
         * needed to get the first part */
        bitmask = (FGUI_BLACK >> (x % 8));
        if (fgui->bgcolor == FGUI_BLACK) {
            for (ch = 0; ch < h; ch++) {
                pos = ((y + ch) * fgui->bytew) + bitstobytesdown(x);
                fgui->fb[pos] &= ~bitmask;
                fgui->fr[pos] &= ~bitmask;
            }
        } else if( fgui->bgcolor == FGUI_RED ) {
            for (ch = 0; ch < h; ch++) {
                pos = ((y + ch) * fgui->bytew) + bitstobytesdown(x);
                fgui->fb[pos] |= bitmask;
                fgui->fr[pos] |= bitmask;
            }
        } else {
            for (ch = 0; ch < h; ch++) {
                pos = ((y + ch) * fgui->bytew) + bitstobytesdown(x);
                fgui->fb[pos] |= bitmask;
                fgui->fb[pos] &= ~bitmask;
            }
        }
    }

    /* OK, now copy all complete bytes */
    for (ch = 0; ch < h; ch++) {
        for (cw = bitstobytesup(x); cw < bitstobytesdown(x + w); cw++) {
            pos = ((y + ch) * fgui->bytew) + cw;
            if( fgui->bgcolor == FGUI_BLACK ) {
                fgui->fb[pos] = 0x00;
                fgui->fr[pos] = 0x00;
            } else if( fgui->bgcolor == FGUI_RED ) {
                fgui->fb[pos] = 0xFF;
                fgui->fr[pos] = 0xFF;
            } else {
                fgui->fb[pos] = 0xFF;
                fgui->fr[pos] = 0x00;
            }
        }
    }

    /* Right now all whole bytes of the region are cleared;
       if there are some bits left, we clear them here */
    if ((x + w) % 8) {
        bytestart = bitstobytesdown(x + w);
        bitmask   = FGUI_BLACK << (8 - ((x + w) % 8));
        if (fgui->bgcolor == FGUI_BLACK) {
            for (ch = 0; ch < h; ch++) {
                pos = ((y + ch) * fgui->bytew) + bytestart;
                fgui->fb[pos] &= ~bitmask;
                fgui->fr[pos] &= ~bitmask;
            }
        } else if( fgui->bgcolor == FGUI_RED) {
            for (ch = 0; ch < h; ch++) {
                pos = ((y + ch) * fgui->bytew) + bytestart;
                fgui->fr[pos] |= bitmask;
                fgui->fb[pos] |= bitmask;
            }
        } else {
            for (ch = 0; ch < h; ch++) {
                pos = ((y + ch) * fgui->bytew) + bytestart;
                fgui->fb[pos] &= ~bitmask;
                fgui->fr[pos] |= bitmask;
            }
        }
    }
}

void
fgui_fillregion(fgui_t fgui, int x, int y, unsigned int w, unsigned int h)
/*
  Fill a region of the framebuffer at location x,y, with width 'w' and height
  'h'
*/
{
    uint8_t temp = fgui->bgcolor;
    fgui->bgcolor = fgui->fgcolor;

    fgui_clearregion(fgui, x, y, w, h);

    fgui->bgcolor = temp;
}