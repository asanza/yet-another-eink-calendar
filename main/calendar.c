#include "calendar.h"

bool
is_leap_year(int year)
{
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

int
month_days_count(int month, int year)
{
    int mdays;
    if (month == 2) {
        // February
        mdays = is_leap_year(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 ||
               month == 11) {
        // April, June, September, November
        mdays = 30;
    } else {
        // All other months
        mdays = 31;
    }
    return mdays;
}

int 
get_weekday(int day, int month, int year) {
    // Zeller's Congruence algorithm
    int q = day;  // Day of the month
    int m = month;
    int K = year % 100;  // Year of the century
    int J = year / 100;  // Century
    int h = (q + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    // Convert the result to the range [0, 6] (0 for Sunday, 1 for Monday, and so on)
    return (h + 5) % 7;
}