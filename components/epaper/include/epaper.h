#ifndef C46706D4_A6EB_44B6_A745_E6777681AAA4
#define C46706D4_A6EB_44B6_A745_E6777681AAA4

#include <stdint.h>

struct epd {
    /* write a byte array into the spi interface */
    int (*write)(uint8_t *buf, int len);
    int (*reset)(int val);
    int (*set_dc)(int val);
    int (*get_busy)(void);
    void (*delay_ms)(int delay);
};

void
ep_init(const struct epd *drv);

void
ep_clear(const struct epd *p);

/* draw the red/white buffer */
void
ep_draw_rwbuffer(const struct epd *p, uint8_t* buf, int len);

/* draw the black/white buffer */
void
ep_draw_bwbuffer(const struct epd *p, uint8_t* buf, int len);

/* draw booth buffers at once */
void
ep_draw(const struct epd* p, uint8_t *blk, uint8_t* red, int len);

/**
 * @brief Return the size in bytes needed for the framebuffer
 * 
 * @param drv the driver
 * @param w horizontal resolution px
 * @param h vertical resolution in px
 * @return int return the size in bytes needed for the framebuffer.
 */
int
ep_get_size(const struct epd* drv, int* w, int*h);

void
ep_sleep(const struct epd* drv);

void
ep_wakeup(const struct epd* drv);

#endif /* C46706D4_A6EB_44B6_A745_E6777681AAA4 */
