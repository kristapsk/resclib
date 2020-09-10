#ifndef _TIME_H
#define _TIME_H

#include <_clock_t.h>
#include <_null.h>
#include <_size_t.h>
#include <_time_t.h>

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

#ifdef __cplusplus
extern "C" {
#endif

/*** Time manipulation *****************************************************/
clock_t clock (void);
double difftime (time_t end, time_t beginning);
time_t time (time_t* timer);

/*** Conversion ************************************************************/
#ifndef _RESCLIB_SOURCE
    // unsafe
    char* asctime (const struct tm* timeptr);
    struct tm* gmtime (const time_t* timer);
#endif

#if defined(_RESCLIB_SOURCE) || defined(_XOPEN_SOURCE) || defined (_POSIX_SOURCE) || (_POSIX_C_SOURCE >= 1)
    char* asctime_r (const struct tm* timeptr, char* buf);
    struct tm* gmtime_r (const time_t* timer, struct tm* result);
#endif

/*** Macro constants *******************************************************/
#define CLOCKS_PER_SEC  (time_t)(1000000)
#define CLK_TCK         (time_t)(1000000)

#ifdef __cplusplus
}
#endif

#endif
