#include <stdio.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __vprintf (const char* format, va_list args)
{
    return __vfprintf(stdout, format, args);
}

int vprintf (const char* format, va_list args)
    _WEAK_ALIAS_OF("__vprintf");

#ifdef __cplusplus
}
#endif
