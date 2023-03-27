#ifndef E54A8B84_E37D_432D_9956_DB076556EC04
#define E54A8B84_E37D_432D_9956_DB076556EC04

#include <weather.h>

struct wmo_weather *
wmo_get_weather_from_json(const uint8_t* buf, int len);


#endif /* E54A8B84_E37D_432D_9956_DB076556EC04 */
