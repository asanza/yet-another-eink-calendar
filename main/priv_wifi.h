#ifndef C0315991_644E_4335_894D_77015D47EC95
#define C0315991_644E_4335_894D_77015D47EC95

enum wifi_error {
    WIFI_ERR_NONE,
    WIFI_ERR_UNAVAILABLE,
};

enum wifi_error
priv_wifi_init( void );

esp_err_t
priv_wifi_get_image(unsigned char* v);

esp_err_t
priv_wifi_get_open_weather_json(char *response_buffer);

esp_err_t
priv_wifi_get_open_meteo(char *response_buffer);


void
priv_wifi_stop( void );

#endif /* C0315991_644E_4335_894D_77015D47EC95 */
