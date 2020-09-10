#include <errno.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
// Tomohiko Sakamoto's algorithm
static inline int dayofweek (int year, int month, int day)
{
    static const char t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    int y = year - (month < 3);
    return (y + y / 4 - y / 100 + y / 400 + t[month - 1] + day) % 7;
}
*/

struct tm* __gmtime_r (const time_t* timer, struct tm* result)
{
    static const char daysinmonth[] = {
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    // -12219292800 is Oct 15, 1582 00:00:00 - start of Gregorian calendar
    if ((timer == NULL) || (result == NULL) || (*timer < -12219292800)) {
        ___set_errno(EOVERFLOW);
        return NULL;
    }

    // Getting seconds, minutes and hours are simple
    lldiv_t tmp = __lldiv(*timer, 60);
    result->tm_sec = tmp.rem;
    tmp = __lldiv(tmp.quot, 60);
    result->tm_min = tmp.rem;
    tmp = __lldiv(tmp.quot, 24);
    result->tm_hour = tmp.rem;

    // Now we have number of days since Jan 1 1970 in tmp.quot.
    // We convert it to Lilian date by adding number of days between
    // October 15, 1582 and January 1, 1970.
    int lilian_date = tmp.quot + 141428;

    // Get year and yearday from Lilian date
    // Formulas from "Computer processing of dates outside the twentieth
    //   century" By B. G. Ohms, IBM Systems Journal, vol 25 no 2, 1986.
    // https://groups.google.com/forum/#!topic/comp.lang.cobol/GbEvJ9M4tKw
    int cld = (lilian_date + 139444) * 100 / 3652425;
    int nnn = cld + lilian_date + 139444 - (cld >> 2);
    div_t work = __div(nnn * 100, 36525);
    if (work.rem == 0) {
        work.quot--;
    }
    int day_in_year = nnn - (work.quot * 36525 / 100);
    int year = work.quot + 1201;
    result->tm_yday = day_in_year;
    result->tm_year = year - 1900;
    // Get day of week from Lilian date
    result->tm_wday = (lilian_date + 4) % 7;

    // Hack for non leap years after Feb 28 for month calculation
    if ((day_in_year >= 59) && ((year & 3) || (!(year % 25) && (year & 15)))) {
        day_in_year++;
    }
    // Count month and calculate mday
    int month = 0;
    while (day_in_year >= daysinmonth[month]) {
        day_in_year -= daysinmonth[month];
        month++;
    }
    result->tm_mon = month;
    result->tm_mday = day_in_year;

    // we are UTC, so no DST
    result->tm_isdst = 0;

    return result;
}

struct tm* gmtime_r (const time_t* timer, struct tm* result)
    _WEAK_ALIAS_OF("__gmtime_r");

#ifdef __cplusplus
}
#endif
