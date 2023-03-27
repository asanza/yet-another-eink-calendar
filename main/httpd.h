#ifndef C5D2828A_8830_4AE6_859E_59D2E79D317A
#define C5D2828A_8830_4AE6_859E_59D2E79D317A

#include <esp_http_server.h>

httpd_handle_t start_webserver( void );

void stop_webserver(httpd_handle_t ws);

#endif /* C5D2828A_8830_4AE6_859E_59D2E79D317A */
