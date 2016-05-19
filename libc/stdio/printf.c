#include <stdarg.h>
#include <stdio.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __printf (const char* format, ...)
{
    va_list args;
    va_start(args, format);
    int res = __vfprintf(stdout, format, args);
    va_end(args);
    return res;
}

int printf (const char* format, ...)
    _WEAK_ALIAS_OF("__printf");

#ifdef __cplusplus
}
#endif
