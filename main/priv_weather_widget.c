/*
 * Copyright (c) 2023 Diego Asanza <f.asanza@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "priv_weather_widget.h"
#include <time.h>
#include <stdbool.h>
#include <weather.h>
#include <stdio.h>

static struct tm 
get_time(int timestamp)
{
    setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);
    tzset();
    time_t now = timestamp;
    return *localtime(&now);
}

static void 
draw_hourly( fgui_t fgui, const struct wmo_hourly_forecast *w, int idx,  int xpos, int ypos) 
{
    struct tm t;
    char text[20];

    t = get_time(w->timestamp[idx]);
    struct fgui_icon* icn = (struct fgui_icon *)wmo_icon_from_code(w->wmo_code[idx], w->is_day[idx], WMO_ICON_SIZE_64x64);
    xpos -= icn->width / 2;
    fgui_subimage(fgui, xpos, ypos, icn);

    fgui_setfont(fgui, &FONT_12X20);
    sprintf(text, "%.1f%cC", w->temperature_2m[idx], 167);
    fgui_text(fgui, xpos, ypos + 70, text);
    fgui_setfont(fgui, &FONT_10X16);
    sprintf(text, "%02d:%02d", t.tm_hour, t.tm_min);
    fgui_text(fgui, xpos, ypos + 90, text);
}

void
draw_weather_widget(fgui_t fgui, const struct wmo_weather *w)
{
    const int   x0 = 580;
    const int   y0 = 10;
    char        text[100];
    const char *c;

    int  code   = w->current.wno_code;
    bool is_day = w->current.is_day;
    struct tm t;

    const struct fgui_icon *icn = (struct fgui_icon *)wmo_icon_from_code(
        code, is_day, WMO_ICON_SIZE_128x128);

    fgui_subimage(fgui, x0 - icn->width / 2, y0 + 50, icn);
    fgui_setfont(fgui, &font_UbuntuMono_R_31X64);
    fgui_text(fgui, x0 - fgui_strlen(fgui, "Mannheim") / 2, y0, "Mannheim");

    fgui_setfont(fgui, &font_UbuntuMono_R_31X64);
    sprintf(text, "%.1f%cC", w->current.temp, 186);
    fgui_text(fgui, x0 - fgui_strlen(fgui, text) / 2, y0 + 180, text);

    fgui_setfont(fgui, &font_UbuntuMono_R_16X28);
    c = wmo_description_from_code(code);
    fgui_text(fgui, x0 - fgui_strlen(fgui, c) / 2, y0 + 260, c);

    draw_hourly(fgui, &w->hourly, 0, x0 - 130, y0 + 300);
    draw_hourly(fgui, &w->hourly, 1, x0 - 45, y0 + 300);
    draw_hourly(fgui, &w->hourly, 2, x0 + 45, y0 + 300);
    draw_hourly(fgui, &w->hourly, 3, x0 + 130, y0 + 300);

    fgui_setfont(fgui, &FONT_12X20);
    t = get_time(w->daily.sunrise[0]);
    sprintf(text, "sunrise: %02d:%02d", t.tm_hour, t.tm_min);
    fgui_text(fgui, x0 - 165, y0 + 420, text);
    t = get_time(w->daily.sunset[0]);
    sprintf(text, "sunset : %02d:%02d", t.tm_hour, t.tm_min);
    fgui_text(fgui, x0 - 165, y0 + 440, text);
}
