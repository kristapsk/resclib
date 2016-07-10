#include <errno.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

errno_t __asctime_s (char* buf, size_t buf_nbytes, const struct tm* timeptr)
{
    static const char wday_name[][4] = {
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
    };
    static const char mon_name[][4] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    errno_t err = 0;
    if ((buf == NULL) || (buf_nbytes == 0)) {
        err = EINVAL;
    }
    else if (
        (buf_nbytes < 26) || (timeptr == NULL) ||
        (timeptr->tm_sec > 61) ||
        (timeptr->tm_min > 59) ||
        (timeptr->tm_hour > 23) ||
        (timeptr->tm_mday > 31) ||
        (timeptr->tm_mon > 11) ||
        (timeptr->tm_year < -1900) || (timeptr->tm_year > 8099) ||
        (timeptr->tm_wday > 6)
    ) {
        err = EINVAL;
        buf[0] = '\0';
    }
    if (err != 0) {
        ___set_errno(err);
        return err;
    }

    __snprintf(buf, buf_nbytes, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
        wday_name[timeptr->tm_wday],
        mon_name[timeptr->tm_mon],
        timeptr->tm_mday, timeptr->tm_hour,
        timeptr->tm_min, timeptr->tm_sec,
        timeptr->tm_year + 1900);

    return err;
}

errno_t asctime_s (char* buf, size_t buf_nbytes, const struct tm* timeptr)
    _WEAK_ALIAS_OF("__asctime_s");

#ifdef __cplusplus
}
#endif
