/*
    FemtoGUI

    fgui_line.c:
        Line functions

    copyright:
              Copyright (c) 2006-2008 Bastiaan van Kesteren <bastiaanvankesteren@gmail.com>

              This program comes with ABSOLUTELY NO WARRANTY; for details see the file LICENSE.
              This program is free software; you can redistribute it and/or modify it under the terms
              of the GNU General Public License as published by the Free Software Foundation; either
              version 2 of the License, or (at your option) any later version.

    remarks:

*/
#include "fgui.h"
#include "fgui_config.h"
#include <stdlib.h>

#define FGUI_CODE
#include "fgui_helper.h"

static void fgui_line_low(fgui_t fgui, const unsigned int x0, const unsigned int y0, const unsigned int x1, const unsigned int y1)
{
    int deltax, deltay, yincrement;
    int error;
    unsigned int x,y;

    deltax = x1 - x0;
    deltay = y1 - y0;

    if (deltay < 0) {
        yincrement = -1;
        deltay = -deltay;
    }
    else {
        yincrement = 1;
    }

    error = 2 * deltay - deltax;
    y=y0;
    for(x=x0;x<=x1;x++) {
        fgui_pixelon(fgui, x,y);
        if(error > 0) {
            y += yincrement;
            error -= 2 * deltax;
        }
        error += 2 * deltay;
    }
}

static void fgui_line_high(fgui_t fgui, const unsigned int x0, const unsigned int y0, const unsigned int x1, const unsigned int y1)
{
    int deltax, deltay, xincrement;
    int error;
    unsigned int x,y;

    deltax = x1 - x0;
    deltay = y1 - y0;

    if (deltax < 0) {
        xincrement = -1;
        deltax = -deltax;
    }
    else {
        xincrement = 1;
    }

    error = 2 * deltax - deltay;
    x=x0;
    for(y=y0;y<=y1;y++) {
        fgui_pixelon(fgui, x,y);
        if(error > 0) {
            x += xincrement;
            error -= 2 * deltay;
        }
        error += 2 * deltax;
    }
}

#ifdef __SDCC
int abs(int j)
{
	return (j < 0) ? -j : j;
}
#endif

void fgui_line(fgui_t fgui, const unsigned int x0, const unsigned int y0, const unsigned int x1, const unsigned int y1)
/*
  Draw a line from x0,y0 to x1,y1. For straight (horizontal or vertical) lines,
  use fgui_lineh/fgui_linev; those are faster.

  This follows the Bresenham algorithm. See http://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html for the theory,
  and wikipedia (http://en.wikipedia.org/wiki/Bresenham's_line_algorithm) for the pseudo-code which is implemented here.
*/
{
    if(abs(y1-y0) < abs(x1-x0)) {
        if(x0 > x1) {
            fgui_line_low(fgui, x1,y1,x0,y0);
        }
        else {
            fgui_line_low(fgui, x0,y0,x1,y1);
        }
    }
    else {
        if(y0 > y1) {
            fgui_line_high(fgui, x1,y1,x0,y0);
        }
        else {
            fgui_line_high(fgui, x0,y0,x1,y1);
        }
    }
}

void fgui_lineh(fgui_t fgui, const unsigned int x, const unsigned int y, unsigned int l)
/*
  Draw a horizontal line starting at location x,y with length l
*/
{
    unsigned int i;
    unsigned char bitmask;

    /* Sanity check */
    if(x > fgui->width || y > fgui->height) {
        return;
    }
    if(x + l > fgui->width) {
        l = fgui->width - x;
    }

    /* Draw all the whole byte parts of the line.. */
    for(i=bitstobytesup(x);i<bitstobytesdown(x+l);i++) {
        fgui->fb[y*fgui->bytew + i] = fgui->fgcolor;
    }
    /* ..then the leftover bits at the beginning of the line.. */
    if(x%8) { 
        if(x%8 + l < 8) {
            bitmask = (0xFF >> x%8) & (0xFF<<(8-((x%8)+l)));
        }
        else {
            bitmask=0xFF;
        }

        if(fgui->fgcolor == FGUI_BLACK) {
            fgui->fb[y*fgui->bytew + bitstobytesdown(x)] |= (fgui->fgcolor>>(x%8))&bitmask;
        }
        else {
            fgui->fb[y*fgui->bytew + bitstobytesdown(x)] &= ~(fgui->fgcolor>>(x%8))&bitmask;
        }
    }
    /* ..and finally, leftover bits at the end of the line */
    if((x+l)%8 && (x%8 == 0 || (x%8)+l>8)) {
        if(fgui->fgcolor == FGUI_BLACK) {
            fgui->fb[y*fgui->bytew + bitstobytesdown(x+l)] |= (fgui->fgcolor<<(8-((x+l)%8)))&0xFF;
        }
        else {
            fgui->fb[y*fgui->bytew + bitstobytesdown(x+l)] &= ~(fgui->fgcolor<<(8-((x+l)%8)))&0xFF;
        }
    }
}

void fgui_linev(fgui_t fgui, const unsigned int x, const unsigned int y, unsigned int l)
/*
  Draw a vertical line starting at location x,y with length l
*/
{
    unsigned char b;
    unsigned int yn;

    /* Sanity check */
    if(x > fgui->width || y > fgui->height) {
        return;
    }
    if(y + l > fgui->height) {
        l = fgui->height - y;
    }

    b=1<<(7-(x%8));

    if(fgui->fgcolor == FGUI_BLACK) {
        for(yn=y;yn<(y+l);yn++) {
            fgui->fb[yn*fgui->bytew + bitstobytesdown(x)] |= b;
        }
    }
    else {
        for(yn=y;yn<(y+l);yn++) {
            fgui->fb[yn*fgui->bytew + bitstobytesdown(x)] &= ~b;
        }
    }
}

