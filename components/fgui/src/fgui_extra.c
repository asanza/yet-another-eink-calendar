/*
    FemtoGUI

    fgui_extra.c:
        Extra's

    copyright:
              Copyright (c) 2020 Bastiaan van Kesteren <bastiaanvankesteren@gmail.com>

              This program comes with ABSOLUTELY NO WARRANTY; for details see the file LICENSE.
              This program is free software; you can redistribute it and/or modify it under the terms
              of the GNU General Public License as published by the Free Software Foundation; either
              version 2 of the License, or (at your option) any later version.

    remarks:

*/
#include "fgui_config.h"
#include "fgui_extra.h"
#include "fgui.h"

#define FGUI_CODE
#include "fgui_helper.h"


void fgui_setprintbuffer(fgui_t fgui, char* buffer, int bufferlength)
/*
  Set buffer (and length) to be used by fgui_print and fgui_printline
*/
{
    fgui->printbuf = buffer;
    fgui->printbuflen = bufferlength;
}

char fgui_print(fgui_t fgui, int x, int y, char *fmt, ...)
/*
  Print text (printf format) at given x/y location.
  Returns 1 on success, false otherwise
*/
{
    if(fgui->printbuf && fgui->printbuflen) {
        va_list argpointer;
        va_start(argpointer, fmt);

        FGUI_VSNPRINTF(fgui->printbuf, fgui->printbuflen, fmt, argpointer);
        fgui_text(fgui, x, y, fgui->printbuf);

        va_end(argpointer);

        return 1;
    }
    return 0;
}

char fgui_printline(fgui_t fgui, int y, fgui_linealignment_t alignment, char invert, char *fmt, ...)
/*
  Print a line of text at x/y location 0/y. This'll clear the whole line before printing the text!
  Returns 1 on success, false otherwise
*/
{
    int x;

    if(fgui->printbuf && fgui->printbuflen) {
        /* Get text-string */
        va_list argpointer;
        va_start(argpointer, fmt);

        FGUI_VSNPRINTF(fgui->printbuf, fgui->printbuflen, fmt, argpointer);

        va_end(argpointer);

        /* Determine x location */
        switch(alignment) {
            case fgui_left:
                x=0;
                break;
            case fgui_center:
                x = fgui_strlen(fgui, fgui->printbuf);
                if(x>fgui->width) {
                    x=0-((x-fgui->width)/2);
                }
                else {
                    x = (fgui->width/2) - (x/2);
                }
                break;
            case fgui_right:
                x = fgui_strlen(fgui, fgui->printbuf);
                if(x>fgui->width) {
                    x=0-(x-fgui->width);
                }
                else {
                    x = fgui->width - x;
                }
                break;
            default:
                return 0;
        }

        /* Print text on screen */
        if(invert) {
            fgui->fgcolor = ~fgui->fgcolor;
        }
        fgui_clearregion(fgui, 0, y, fgui->width, fgui_charheight(fgui));
        fgui_text(fgui, x, y, fgui->printbuf);
        if(invert) {
            fgui->fgcolor = ~fgui->fgcolor;
        }

        return 1;
    }
    return 0;
}

int fgui_printblock(fgui_t fgui, int y, char *text, unsigned int start, char showscrollbar)
/*
  Print a block of text (text[start]) starting at x/y location 0/y.
  When 'showscrollbar' > 0 a scrollbar is drawn at the right side of the screen.
  Index of the next char to print is returned.
*/
{
    unsigned int i,x,w;

    if(showscrollbar) {
        w = fgui->width - 3;

        /* 'items' argument is round up; for x/y, rounding up is done using (x + y - 1) / y */
        fgui_scrollbar(fgui, w, y, fgui->height-y, (strlen(text) + fgui_blocklength(fgui, y, showscrollbar) - 1) / fgui_blocklength(fgui, y, showscrollbar),
                                           start / fgui_blocklength(fgui, y, showscrollbar));
    }
    else {
        w = fgui->width;
    }

    x=0;
    i = start;
    while(text[i]) {
        fgui_char(fgui, x,y,text[i]);
        x+=fgui_charwidth(fgui);
        if(x+fgui_charwidth(fgui) > w) {
            y+=fgui_charheight(fgui);
            if(y+fgui_charheight(fgui) > fgui->height) {
                i++;
                break;
            }
            x=0;
        }
        i++;
    }
    return i;
}

int fgui_blocklength(fgui_t fgui, int y, char showscrollbar)
/*
  Returns no. of chars that'll fit in one block
*/
{
    if(showscrollbar) {
        return ((fgui->height-y)/fgui_charheight(fgui)) * ((fgui->width - 3) / fgui_charwidth(fgui));
    }
    else {
        return ((fgui->height-y)/fgui_charheight(fgui)) * (fgui->width / fgui_charwidth(fgui));
    }
}

int fgui_linetoy(fgui_t fgui, unsigned int line)
/*
  Convert given y location to a line location, using the active font
*/
{
    return line*fgui_charheight(fgui);
}

int fgui_lines(fgui_t fgui)
/*
  No. of text-lines that'll fit on the display, using the active font
*/
{
    return fgui->height/fgui_charheight(fgui);
}

char fgui_progressbar(fgui_t fgui, int x, int y, int w, int h, unsigned char progress, char showText)
/*
  Draw a horizontal progress bar at given x/y location of w*h pixels.
  Returns 1 on success, false otherwise
*/
{
    int i;

    if(h > 4 && w > 4) {
        /* Box */
        fgui_lineh(fgui, x, y, w);
        fgui_linev(fgui, x, y, h);
        fgui_lineh(fgui, x, y + h - 1, w);
        fgui_linev(fgui, x + w - 1, y, h);

        /* Bar */
        if(progress > 100) {
            progress = 100;
        }
        fgui_clearregion(fgui, x+2, y+2, w-4, h-4);
        for(i=0;i<h-4;i++) {
            fgui_lineh(fgui, x+2, y+2+i, progress * ((w-4)/100.0));
        }

        /* Text, if there's enough room */
        if(showText && h-4 > fgui_charheight(fgui) && w-4 > fgui_charwidth(fgui) * 3) {
            fgui_print(fgui, x + (w/2) - fgui_charwidth(fgui), y + (h/2)  - (fgui_charheight(fgui)/2), "%d%%", progress);
        }

        return 1;
    }
    return 0;
}

char fgui_scrollbar(fgui_t fgui, int x, int y, int h, unsigned int items, unsigned int location)
/*
  Draw a vertical scroll bar bar at given x/y location with given height and a width of 3 pixels.
  Returns 1 on success, false otherwise
*/
{
    double indicatorlength;

    if(h > 6) {
        /* Top terminator (/\) */
        fgui_pixel(fgui, x+1, y, FGUI_BLACK);
        fgui_lineh(fgui, x, y+1, 3);

        /* Vertical line */
        fgui_linev(fgui, x+1, y+3, h-6);

        /* Bottom terminator (\/) */
        fgui_lineh(fgui, x, y+h-2, 3);
        fgui_pixel(fgui, x+1, y+h-1, FGUI_BLACK);

        /* Location indicator */
        if(location >= items-1) {
            location = items-1;
        }

        /* 'indicatorlength' is round up; for x/y, rounding up is done using (x + y - 1) / y */
        indicatorlength = ((h-6.0) + items - 1)/items;
        fgui_linev(fgui, x,     y + 3 + (location * (h-6.0)/items), indicatorlength);
        fgui_linev(fgui, x + 2, y + 3 + (location * (h-6.0)/items), indicatorlength);

        return 1;
    }
    return 0;
}

char fgui_busyindicator(fgui_t fgui, int x, int y, int w, int h, int tick)
/*
  Draw busy indicator at given x/y location of w*h pixels.
  Returns > 0 on success, 0 otherwise. On successive calls, use the return-value of the previous call for the 'tick' argument
*/
{
    int i;
    int dotspacing = ((w+3-1)/3.0);

    if(tick < 1) {
        tick = 1;
    }
    else if(tick > 3) {
        tick = 2;
    }

    if(h > 2 && w > 5) {
        for(i=0;i<3;i++) {
            if(i == tick-1) {
                /* Filled dot */
                fgui_fillregion(fgui, x + (i*dotspacing), y, w/3, h);
            }
            else {
                /* Empty dot */
                fgui_clearregion(fgui, x + (i*dotspacing), y, w/3, h);
                fgui_lineh(fgui, x + (i*dotspacing), y, w/3);
                fgui_linev(fgui, x + (i*dotspacing), y, h);
                fgui_lineh(fgui, x + (i*dotspacing), y + h - 1, w/3);
                fgui_linev(fgui, x + (i*dotspacing) + (w/3) - 1, y, h);
            }
        }

        tick++;
        if(tick > 3) {
            tick = 1;
        }
        return tick;
    }
    return 0;
}