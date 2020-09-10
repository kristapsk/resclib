#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __asctime_r (const struct tm* timeptr, char* buf)
{
    static const char wday_name[][4] = {
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
    };
    static const char mon_name[][4] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    if (
        (buf == NULL) || (timeptr == NULL) ||
        (timeptr->tm_sec > 61) ||
        (timeptr->tm_min > 59) ||
        (timeptr->tm_hour > 23) ||
        (timeptr->tm_mday > 31) ||
        (timeptr->tm_mon > 11) ||
        (timeptr->tm_year < -1900) || (timeptr->tm_year > 8099) ||
        (timeptr->tm_wday > 6)
    ) {
        return NULL;
    }

    __snprintf(buf, 26, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
        wday_name[timeptr->tm_wday],
        mon_name[timeptr->tm_mon],
        timeptr->tm_mday, timeptr->tm_hour,
        timeptr->tm_min, timeptr->tm_sec,
        timeptr->tm_year + 1900);

    return buf;
}

char* asctime_r (const struct tm* timeptr, char* buf)
    _WEAK_ALIAS_OF("__asctime_r");

#ifdef __cplusplus
}
#endif
