/*
    FemtoGUI

    fgui_text.c:
        Text functions

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

#define FGUI_CODE
#include "fgui_helper.h"

/*
  Select the font to use. Must be called before using any of the other text
  functions.
  'newfont' must point to a valid font array. Elements in the array are:
   0    char width in bits (pixels)
   1    char height in bits (pixels)
   2-n  The actual pixel data
*/
void
fgui_setfont(fgui_t fgui, fgui_font_t newfont)
{
    fgui->font = newfont;
}

unsigned char
fgui_charheight(fgui_t fgui)
/*
  Height of active font, in pixels
*/
{
    return fgui->font->char_height;
}

unsigned char
fgui_charwidth(fgui_t fgui)
/*
  Width of a single character from the active font, in pixels
*/
{
    return fgui->font->char_width;
}

unsigned int
fgui_strlen(fgui_t fgui, const char *s)
/*
  Get length of given string, in pixels
*/
{
    int length = 0;

    while (*s) {
        s++;
        length++;
    }

    return length * fgui->font->char_width;
}

/*
  Place a single character at given location
*/
void
fgui_char(fgui_t fgui, const int x, const int y, const char ch)
{
    uint16_t index, xo, actual_char_width, c, yo = y;
    uint8_t  b;
    uint16_t bt = ch;
    uint16_t bn = fgui->font->char_width;
    if (!bn)
        return;
    bn >>= 3;
    if (fgui->font->char_width % 8){
        bn++;
    }
    actual_char_width =
        (fgui->font->widths ? fgui->font->widths[bt - fgui->font->start_char] : fgui->font->char_width);
    index = (bt - fgui->font->start_char) * fgui->font->char_height * bn;
    for (int j = 0; j < fgui->font->char_height; j++) {
        xo = x;
        c  = actual_char_width;
        for (int i = 0; i < bn; i++) {
            b = fgui->font->p[index++];
            for (int k = 0; (k < 8) && c; k++) {
                if (b & 0x01) {
                    fgui_pixelon(fgui, xo, yo);
                } else {
                    fgui_pixeloff(fgui, xo, yo);
                }
                b >>= 1;
                xo++;
                c--;
            }
        }
        yo++;
    }
}

void
fgui_text(fgui_t fgui, int x, const int y, const char *str)
/*
  Place a NULL terminated string at the given location
*/
{
    while (*str) {
        fgui_char(fgui, x, y, *str);
        x += fgui->font->char_width;
        str++;
    }
}
