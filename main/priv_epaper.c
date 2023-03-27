/*
 * Copyright (c) 2023 Diego Asanza <f.asanza@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
#include <epaper.h>
#include <driver/gpio.h>
#include <driver/spi_master.h>
#include "priv_epaper.h"
#include "fgui.h"
#include "fgui_font.h"
#include "calendar.h"
#include "esp_log.h"
#include <time.h>
#include <jsmn.h>
#include <string.h>
#include "weather.h"
#include "priv_weather_widget.h"

#define BUSY_PIN  GPIO_NUM_25
#define RESET_PIN GPIO_NUM_26
#define DC_PIN    GPIO_NUM_27
#define CS_PIN    GPIO_NUM_15
#define MOSI_PIN  GPIO_NUM_14
#define CLK_PIN   GPIO_NUM_13

#define MAX_TRANSFER_SIZE 4096

static spi_device_handle_t spi;

static fgui_t fgui;

struct weather {
    const char* weather_code;
    const char* temp;
    const char* is_day;
};

static void
delay_ms(int ms)
{
    vTaskDelay(pdMS_TO_TICKS(ms));
}

static int
get_busy(void)
{
    return gpio_get_level(BUSY_PIN);
}

static int
write_spi(uint8_t *buf, int len)
{
    int size;
    if (len >= MAX_TRANSFER_SIZE) {
        size = MAX_TRANSFER_SIZE;
    } else {
        size = len;
    }

    spi_transaction_t t = {
        .flags     = 0,
        .tx_buffer = buf,
        .length    = size * 8,
    };

    uint32_t rval = spi_device_polling_transmit(spi, &t);
    ESP_ERROR_CHECK(rval);

    return size;
}

static int
set_dc(int val)
{
    return gpio_set_level(DC_PIN, val);
}

static int
reset(int val)
{
    return gpio_set_level(RESET_PIN, val);
}

static const struct epd epd = { .delay_ms = delay_ms,
                                .get_busy = get_busy,
                                .write    = write_spi,
                                .set_dc   = set_dc,
                                .reset    = reset };

int
screen_init(void)
{
    return 1;
}

static void
draw_fn(const void *ctx, unsigned char *fb, unsigned char *fr, int len)
{
    ep_draw(ctx, fb, fr, len);
}

void
priv_epaper_init( void )
{
    esp_err_t     ret;
    gpio_config_t cfg = {
        .mode         = GPIO_MODE_OUTPUT,
        .pin_bit_mask = BIT(DC_PIN) | BIT(RESET_PIN),
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en   = GPIO_PULLUP_DISABLE,
        .intr_type    = GPIO_INTR_DISABLE,
    };

    ret = gpio_config(&cfg);
    ESP_ERROR_CHECK(ret);

    cfg.pin_bit_mask = BIT(BUSY_PIN);
    cfg.mode         = GPIO_MODE_INPUT;
    cfg.pull_down_en = GPIO_PULLDOWN_ENABLE;
    ret              = gpio_config(&cfg);
    ESP_ERROR_CHECK(ret);

    gpio_set_level(CS_PIN, 1);

    spi_bus_config_t spi_bus = { 0 };
    spi_bus.mosi_io_num      = MOSI_PIN;
    spi_bus.sclk_io_num      = CLK_PIN;
    spi_bus.miso_io_num      = -1;
    spi_bus.quadhd_io_num    = -1;
    spi_bus.quadwp_io_num    = -1;
    spi_bus.max_transfer_sz  = MAX_TRANSFER_SIZE;
    spi_bus.flags            = 0;

    spi_device_interface_config_t spi_dev = { 0 };
    spi_dev.mode                          = 0;
    spi_dev.duty_cycle_pos                = 0;
    spi_dev.clock_speed_hz                = 8000000;
    spi_dev.spics_io_num                  = CS_PIN;
    spi_dev.flags                         = SPI_DEVICE_HALFDUPLEX;
    spi_dev.queue_size                    = 1;
    spi_dev.pre_cb                        = NULL;
    spi_dev.post_cb                       = NULL;

    ret = spi_bus_initialize(SPI3_HOST, &spi_bus, SPI_DMA_CH_AUTO);
    ESP_ERROR_CHECK(ret);

    ret = spi_bus_add_device(SPI3_HOST, &spi_dev, &spi);
    ESP_ERROR_CHECK(ret);

    ep_init(&epd);
    int x, y;
    ep_get_size(&epd, &x, &y);
}

const char* weekdays[] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "So"};

void draw_calendar(uint8_t *bbuf, uint8_t* rbuf)
{
    const int width = 350;
    const int height = 350;
    const int x0 = 0, y0 = 80;
    const int xpad = 10;
    const int ypad = 10;

    uint8_t rh = height / 7;
    uint8_t cw = width / 7;

    int year_now;
    int month_now;

    char       text[100];

    time_t     now = time(NULL);
    struct tm *t   = localtime(&now);

    strftime(text, sizeof(text) - 1, "%B %Y", t);

    fgui_setfont(fgui, &font_UbuntuMono_R_24X42);
    fgui_text(fgui, 30, 20, text);
    fgui_setfont(fgui, &font_UbuntuMono_R_16X28);

    /* draws grid and header */
    for( int i = 0; i < 7; i++ ) {
        // fgui_line(fgui, x0, y0 + rh * i, x0 + width, y0 + rh * i);
        // fgui_line(fgui, x0 + cw * i, y0, x0 + cw * i, y0 + height);
        fgui_text(fgui, x0 + i * cw + xpad, y0 + ypad, weekdays[i]);
    }

    // fgui_line(fgui, x0 + width, y0, x0 + width, y0 + height);
    // fgui_line(fgui, x0, y0 + height, x0 + width, y0 + height);

    /* draws this month calendar */
    month_now = t->tm_mon + 1;
    year_now = t->tm_year + 1900;

    int dcount = month_days_count(month_now, year_now);
    int dweek = get_weekday(1, month_now, year_now);
    int idx = 0 - dweek;
    for( int j = 1; j < 7; j++) {
        for( int i = 0; i < 7; i++) {
            if( idx++ < 0 ) {
                continue;
            }
            if( idx > dcount ) {
                break;
            }

            if( idx == t->tm_mday ) {
                fgui_fillregion(fgui, x0 + cw * i, y0 + rh * j, cw, rh);
                fgui_set_bgcolor(fgui, FGUI_BLACK);
                fgui_set_fgcolor(fgui, FGUI_WHITE);
            } else {
                fgui_set_bgcolor(fgui, FGUI_WHITE);
                fgui_set_fgcolor(fgui, FGUI_BLACK);
            }

            sprintf(text, "%2d", idx);
            fgui_text(fgui, xpad + x0 + cw * i, ypad + y0 + j * rh, text);
        }
    }

    sprintf(text, "Last Updated: %02d:%02d", t->tm_hour, t->tm_min);
    fgui_setfont(fgui, &FONT_12X20);
    fgui_text(fgui, 20, 450, text);
}

#define ARRAY_SIZE(x) ((sizeof(x)/sizeof(x[0])))

struct whelp {
    const char* code;
    const char* icon;
    const char* description;
};

void priv_epaper_draw_weather(const struct wmo_weather* w)
{
    draw_weather_widget(fgui, w);
}

void
priv_epaper_draw_calendar(char* json, uint8_t* bbuf, uint8_t* rbuf, bool ok)
{
    fgui = fgui_init(800, 480, draw_fn, &epd, rbuf, bbuf);
    fgui_clear(fgui);
    draw_calendar(bbuf, rbuf);
}


void
priv_epaper_draw(uint8_t *buf, uint8_t *rbuf)
{
    ep_clear(&epd);
    ep_draw(&epd, buf, rbuf, 480 * 100);
}

void
priv_epaper_sleep(void)
{
    ep_sleep(&epd);
}