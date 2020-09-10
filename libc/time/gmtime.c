#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

struct tm* __gmtime (const time_t* timer)
{
    static struct tm t;
    return __gmtime_r(timer, &t);
}

struct tm* gmtime (const time_t* timer)
    _WEAK_ALIAS_OF("__gmtime");

#ifdef __cplusplus
}
#endif
