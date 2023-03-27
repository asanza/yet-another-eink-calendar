/*
 * Copyright (c) 2023 Diego Asanza <f.asanza@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "epaper.h"
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include "esp_log.h"

static const char *TAG = "EPAPER";

// Display resolution
#define EPD_7IN5B_V2_WIDTH  800
#define EPD_7IN5B_V2_HEIGHT 480

#define EPD_WIDTH                                                              \
    ((EPD_7IN5B_V2_WIDTH % 8 == 0) ? (EPD_7IN5B_V2_WIDTH / 8) :                \
                                     (EPD_7IN5B_V2_WIDTH / 8 + 1))

#define EPD_HEIGH EPD_7IN5B_V2_HEIGHT

#define EPD_LEN (EPD_WIDTH * EPD_HEIGH)

#define CMD_PSR  0X00
#define CMD_PWR  0x01
#define CMD_PON  0x04
#define CMD_DTM1 0x10
#define CMD_DRF  0x12
#define CMD_DTM2 0x13
#define CMD_TRES 0x61
#define CMD_FLG  0x71

/* panel settings */
#define PSR_REG   (1 << 5)
#define PSR_KWR   (1 << 4)
#define PSR_UD    (1 << 3)
#define PSR_SHL   (1 << 2)
#define PSR_SHD_N (1 << 1)
#define PSR_RST_N (1 << 0)

/* power on settings */
#define PWR_BD_EN (1 << 4)
#define PWR_VSR_E (1 << 2)
#define PWR_VS_E  (1 << 1)
#define PWR_VG_E  (1 << 0)

#define PWR_VG_LVL_9V  (0x00)
#define PWR_VG_LVL_10V (0x00)
#define PWR_VG_LVL_11V (0x00)
#define PWR_VG_LVL_12V (0x00)
#define PWR_VG_LVL_17V (0x00)
#define PWR_VG_LVL_18V (0x00)
#define PWR_VG_LVL_19V (0x00)
#define PWR_VG_LVL_20V (0x00)

#define VDx_LVL_2_4V (0x00)

#define PWR_VCOM_SLEW (1 << 4)
#define PWR_VPP_EN    (1 << 7)

#define COLOR_BLACK 0x01
#define COLOR_RED   0x02

static void
epd_reset(const struct epd *drv)
{
    drv->reset(1);
    drv->delay_ms(200);
    drv->reset(0);
    drv->delay_ms(2);
    drv->reset(1);
    drv->delay_ms(200);
}

static void
epd_write_cmd(const struct epd *drv, uint8_t cmd)
{
    drv->set_dc(0);
    drv->write(&cmd, 1);
}

static void
epd_write_data(const struct epd *drv, uint8_t data)
{
    drv->set_dc(1);
    drv->write(&data, 1);
}

static void
epd_write_buf(const struct epd *drv, uint8_t *buf, int len)
{
    drv->set_dc(1);
    drv->write(buf, len);
}

static void
epd_wait_idle(const struct epd *drv)
{
    unsigned char busy;
    do {
        epd_write_cmd(drv, CMD_FLG);
        busy = drv->get_busy();
        busy = !(busy & 0x01);
    } while (busy);
    drv->delay_ms(200);
}

static void
epd_turn_on(const struct epd *drv)
{
    epd_write_cmd(drv, CMD_DRF);
    drv->delay_ms(200);
    epd_wait_idle(drv);
}

void
ep_init(const struct epd *drv)
{
    ESP_LOGI(TAG, "Initializing EPAPER");
    epd_reset(drv);

    epd_write_cmd(drv, CMD_PWR);
    epd_write_data(drv, PWR_VSR_E | PWR_VS_E | PWR_VG_E);
    epd_write_data(drv, PWR_VG_LVL_9V | PWR_VCOM_SLEW);
    epd_write_data(drv, VDx_LVL_2_4V);
    epd_write_data(drv, VDx_LVL_2_4V);

    epd_write_cmd(drv, CMD_PON);
    drv->delay_ms(100);
    epd_wait_idle(drv);

    epd_write_cmd(drv, CMD_PSR);
    epd_write_data(drv, PSR_UD | PSR_SHL | PSR_SHD_N | PSR_RST_N);

    epd_write_cmd(drv, CMD_TRES);
    epd_write_data(drv, 0x03); // source 800
    epd_write_data(drv, 0x20);
    epd_write_data(drv, 0x01); // gate 480
    epd_write_data(drv, 0xE0);

    epd_write_cmd(drv, 0X15);
    epd_write_data(drv, 0x00);

    epd_write_cmd(drv, 0X50); // VCOM AND DATA INTERVAL SETTING
    epd_write_data(drv, 0x11);
    epd_write_data(drv, 0x07);

    epd_write_cmd(drv, 0X60); // TCON SETTING
    epd_write_data(drv, 0x22);

    epd_write_cmd(drv, 0x65); // Resolution setting
    epd_write_data(drv, 0x00);
    epd_write_data(drv, 0x00); // 800*480
    epd_write_data(drv, 0x00);
    epd_write_data(drv, 0x00);
}

void
ep_clear(const struct epd *drv)
{
    ESP_LOGI(TAG, "Clearing Epaper");
    epd_write_cmd(drv, CMD_DTM1);
    for (int i = 0; i < EPD_LEN; i++) {
        epd_write_data(drv, 0xFF);
    }

    epd_write_cmd(drv, CMD_DTM2);
    for (int i = 0; i < EPD_LEN; i++) {
        epd_write_data(drv, 0x00);
    }

    epd_turn_on(drv);
}

static void
idraw(const struct epd *p, int color, uint8_t *buf, int len)
{
    assert(len == EPD_LEN);
    if (color == COLOR_BLACK) {
        epd_write_cmd(p, CMD_DTM1);
        for (uint32_t j = 0; j < EPD_HEIGH; j++) {
            for (uint32_t i = 0; i < EPD_WIDTH; i++) {
                epd_write_data(p, buf[i + j * EPD_WIDTH]);
            }
        }
    } else if (color == COLOR_RED) {
        epd_write_cmd(p, CMD_DTM2);
        for (uint32_t j = 0; j < EPD_HEIGH; j++) {
            for (uint32_t i = 0; i < EPD_WIDTH; i++) {
                epd_write_data(p, buf[i + j * EPD_WIDTH]);
            }
        }
    }
}

void
ep_draw(const struct epd *p, uint8_t *blk, uint8_t *red, int len)
{
    if( blk != NULL ) {
        idraw(p, COLOR_BLACK, blk, len);
    } 
    if( red != NULL ) {
        idraw(p, COLOR_RED, red, len);
    }
    epd_turn_on(p);
}

void
ep_draw_bwbuffer(const struct epd *ep, uint8_t *buf, int len)
{
    ESP_LOGI(TAG, "Drawing black buffer");
    idraw(ep, COLOR_BLACK, buf, len);
    epd_turn_on(ep);
}

void
ep_draw_rwbuffer(const struct epd *ep, uint8_t *buf, int len)
{
    ESP_LOGI(TAG, "Drawing Red buffer");
    idraw(ep, COLOR_RED, buf, len);
    epd_turn_on(ep);
}

void
ep_sleep(const struct epd *drv)
{
    epd_write_cmd(drv, 0X02); // power off
    epd_wait_idle(drv);
    epd_write_cmd(drv, 0X07); // deep sleep
    epd_write_data(drv, 0xA5);
}

int
ep_get_size(const struct epd *drv, int *w, int *h)
{
    *w = EPD_7IN5B_V2_WIDTH;
    *h = EPD_7IN5B_V2_HEIGHT;
    return EPD_LEN;
}

void
ep_wakeup(const struct epd *drv)
{
    epd_write_cmd(drv, CMD_PWR);
    epd_write_data(drv, PWR_VSR_E | PWR_VS_E | PWR_VG_E);
    epd_write_data(drv, PWR_VG_LVL_9V | PWR_VCOM_SLEW);
    epd_write_data(drv, VDx_LVL_2_4V);
    epd_write_data(drv, VDx_LVL_2_4V);
    epd_write_cmd(drv, CMD_PON); // power off
    drv->delay_ms(100);
    epd_wait_idle(drv);
}