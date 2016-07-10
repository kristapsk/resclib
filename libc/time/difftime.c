#include <time.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

double __difftime (time_t end, time_t beginning)
{
    return (double)(end - beginning);
}

double difftime (time_t end, time_t beginning)
    _WEAK_ALIAS_OF("__difftime");

#ifdef __cplusplus
}
#endif
