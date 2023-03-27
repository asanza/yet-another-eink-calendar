#ifndef EB3C3EE2_AD6C_4DED_A285_80DBAFE2A6FD
#define EB3C3EE2_AD6C_4DED_A285_80DBAFE2A6FD

#include <stdbool.h>
#include <stdint.h>
#include <weather.h>

void priv_epaper_init( void );
void priv_epaper_draw(unsigned char* b, unsigned char* r);
void
priv_epaper_sleep(void);
void
priv_epaper_draw_fgui(uint8_t* rbuf, uint8_t* bbuf);

void
priv_epaper_draw_calendar(char* json, uint8_t* bbuf, uint8_t* rbuf, bool ok);

void priv_epaper_draw_weather(const struct wmo_weather* w);

#endif /* EB3C3EE2_AD6C_4DED_A285_80DBAFE2A6FD */
