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

#if defined CONFIG_7_5_INCH_BICOLOR_EPAPER_DRIVER

static const char *TAG = "EPAPER";

#define EPD_WIDTH 800
#define EPD_HEIGH 480

#define EPD_LEN (EPD_WIDTH * EPD_HEIGH / 8)

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
        busy = drv->get_busy();
        busy = !(busy & 0x01);
    } while (busy);
    drv->delay_ms(200);
}

static void
epd_turn_on(const struct epd *drv)
{
    epd_write_cmd(drv, 0x12);
    epd_wait_idle(drv);
}

static void
epd_set_window(const struct epd* drv, int x1, int y1, int x2, int y2)
{
        epd_write_cmd(drv, 0x50);                            
        epd_write_data(drv, 0xA9);                               
        epd_write_data(drv, 0x07);                               
        epd_write_cmd(drv, 0x91);                            
        epd_write_cmd(drv, 0x90);                            
        epd_write_data(drv, (x1 >> 8) & 0xFF); /* x1 / 256 */    
        epd_write_data(drv, x1 & 0xFF);        /* x1 % 256 */    
        epd_write_data(drv, (x2 >> 8) & 0xFF); /* x2 / 256 */    
        epd_write_data(drv, (x2 & 0xFF) - 1);  /* x2 % 256 - 1 */
        epd_write_data(drv, (y1 >> 8) & 0xFF); /* y1 / 256 */    
        epd_write_data(drv, y1 & 0xFF);        /* y1 % 256 */    
        epd_write_data(drv, (y2 >> 8) & 0xFF); /* y2 / 256 */    
        epd_write_data(drv, (y2 & 0xFF) - 1);  /* y2 % 256 - 1 */
        epd_write_data(drv, 0x01);                               
}

void
ep_init(const struct epd *drv)
{
    ESP_LOGI(TAG, "Initializing EPAPER");
    epd_reset(drv);

    epd_write_cmd(drv, 0x01);
    epd_write_data(drv, 0x07);
    epd_write_data(drv, 0x07);
    epd_write_data(drv, 0x3f);
    epd_write_data(drv, 0x3f);

    

    epd_write_cmd(drv, 0x06);
    epd_write_data(drv, 0x17);
    epd_write_data(drv, 0x17);
    epd_write_data(drv, 0x28);
    epd_write_data(drv, 0x17);

    epd_write_cmd(drv, 0x04);
    drv->delay_ms(100);
    epd_wait_idle(drv);

    epd_write_cmd(drv, 0x00);
    epd_write_data(drv, 0x1F);

    epd_write_cmd(drv, 0x61);
    epd_write_data(drv, EPD_WIDTH >> 8); // source 800
    epd_write_data(drv, EPD_WIDTH & 0xFF);
    epd_write_data(drv, EPD_HEIGH >> 8); // gate 480
    epd_write_data(drv, EPD_HEIGH & 0xFF);

    epd_write_cmd(drv, 0X15);
    epd_write_data(drv, 0x00);

    epd_write_cmd(drv, 0X50); // VCOM AND DATA INTERVAL SETTING
    epd_write_data(drv, 0x10);
    epd_write_data(drv, 0x07);

    epd_write_cmd(drv, 0X60); // TCON SETTING
    epd_write_data(drv, 0x22);
}

void
ep_clear(const struct epd *drv)
{
    ESP_LOGI(TAG, "Clearing Epaper");
    epd_write_cmd(drv, 0x13);
    for (int i = 0; i < EPD_LEN; i++) {
        epd_write_data(drv, 0x00);
    }
    ESP_LOGI(TAG, "Cleared");
    epd_turn_on(drv);
    ESP_LOGI(TAG, "Turned On");
}

static void
idraw(const struct epd *p, const uint8_t *buf, int len)
{
    assert(len <= EPD_LEN);
    ESP_LOGI(TAG, "Drawing buffer: %d", len);
    epd_set_window(p, 0, 0, 800, 480);
    epd_write_cmd(p, 0x13);
    for(int i = 0; i < len; i++){
        epd_write_data(p, buf[i]);
    }
}

void
ep_draw(const struct epd *p, const uint8_t *buf,  int len)
{
    if( buf != NULL ) {
        idraw(p, buf, len);
    } 
    epd_turn_on(p);
}

void
ep_sleep(const struct epd *drv)
{
    epd_write_cmd(drv, 0X50);
    epd_write_data(drv, 0xf7);   
    epd_write_cmd(drv, 0x02);
    epd_wait_idle(drv);
    epd_write_cmd(drv, 0x07);
    epd_write_data(drv, 0xA5);   
}

int
ep_get_size(const struct epd *drv, int *w, int *h)
{
    (void) drv;
    *w = EPD_WIDTH;
    *h = EPD_HEIGH;
    return EPD_LEN;
}

void
ep_wakeup(const struct epd *drv)
{
    drv->reset(0);
    drv->delay_ms(10);
    drv->reset(1);
    drv->delay_ms(10);

    epd_write_cmd(drv, 0x04);
    drv->delay_ms(100);
    epd_wait_idle(drv);
    epd_write_cmd(drv, 0xE0);
    epd_write_data(drv, 0x02);
    epd_write_cmd(drv, 0xE5);
    epd_write_data(drv, 0x6E);
}

#endif