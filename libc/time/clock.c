#include <time.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

clock_t __clock (void)
{
    return (clock_t)-1;
}

clock_t clock (void)
    _WEAK_ALIAS_OF("__clock");

#ifdef __cplusplus
}
#endif
