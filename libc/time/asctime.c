#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __asctime (const struct tm* timeptr)
{
    static char buf[26];
    __asctime_s(buf, sizeof(buf), timeptr);
    return buf;
}

char asctime (const struct tm* timeptr)
    _WEAK_ALIAS_OF("__asctime");

#ifdef __cplusplus
}
#endif
