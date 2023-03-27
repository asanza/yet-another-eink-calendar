#include <unity.h>
#include <weather.h>
#include <weather-json.h>
#include <string.h>
#include <cJSON.h>

void
test_parser(void)
{
    const char *buf =
        "{\"latitude\": 48.78, \"longitude\": 9.18, \"generationtime_ms\": 0.35"
        "40515899658203, \"utc_offset_seconds\": 0, \"timezone\": \"GMT\", \"ti"
        "mezone_abbreviation\": \"GMT\", \"elevation\": 255.0, \"current_weathe"
        "r\": {\"temperature\": 7.7, \"windspeed\": 8.8, \"winddirection\": 109"
        ".0, \"weathercode\": 61, \"is_day\": 1, \"time\": 1682007300}, \"hourl"
        "y_units\": {\"time\": \"unixtime\", \"temperature_2m\": \"\u00b0C\", \""
        " precipitation\": \"mm\", \"weathercode\": \"wmo code\"}, \"hourly\": "
        "{\"time\": [1681948800, 1681952400, 1681956000, 1681959600, 1681963200"
        ", 1681966800, 1681970400, 1681974000, 1681977600, 1681981200, 16819848"
        "00, 1681988400, 1681992000, 1681995600, 1681999200, 1682002800, 168200"
        "6400, 1682010000, 1682013600, 1682017200, 1682020800, 1682024400, 1682"
        "028000, 1682031600, 1682035200, 1682038800, 1682042400, 1682046000, 16"
        "82049600, 1682053200, 1682056800, 1682060400, 1682064000, 1682067600, "
        "1682071200, 1682074800, 1682078400, 1682082000, 1682085600, 1682089200"
        ", 1682092800, 1682096400, 1682100000, 1682103600, 1682107200, 16821108"
        "00, 1682114400, 1682118000], \"temperature_2m\": [4.7, 4.0, 3.4, 2.9, "
        "2.3, 2.0, 2.6, 3.8, 5.4, 7.1, 7.2, 6.6, 7.7, 7.6, 7.7, 7.7, 7.7, 7.6, "
        "7.4, 7.2, 7.0, 6.6, 5.9, 5.2, 5.1, 4.9, 5.1, 5.2, 4.2, 4.6, 5.3, 5.7, "
        "7.2, 9.3, 12.3, 14.7, 15.4, 16.3, 16.6, 16.7, 16.5, 15.7, 14.6, 13.6, "
        "12.9, 12.3, 12.2, 11.5], \"precipitation\": [0.0, 0.0, 0.0, 0.0, 0.0, "
        "0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.6, 0.0, 0.1, 0.4, 0.0, 0.1, 0.0, "
        "0.1, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 1.1, 0.5, "
        "0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, "
        "0.0], \"weathercode\": [1, 0, 0, 0, 0, 0, 1, 3, 2, 3, 3, 61, 61, 61, 6"
        "1, 61, 61, 61, 3, 61, 3, 80, 3, 3, 3, 3, 3, 3, 3, 3, 61, 61, 80, 3, 3,"
        " 3, 3, 3, 2, 0, 2, 2, 3, 3, 3, 3, 3, 3]}}";

    struct wmo_weather *w = wmo_get_weather_from_json(buf, strlen(buf));

    TEST_ASSERT_NOT_EQUAL(NULL, w);
    TEST_ASSERT_EQUAL(true, w->current.is_day);
}