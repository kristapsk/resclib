#include <stdarg.h>
#include <stdio.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __sprintf (char* buf, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    int res = __vsprintf(buf, format, args);
    va_end(args);
    return res;
}

int sprintf (char* buf, const char* format, ...)
    _WEAK_ALIAS_OF("__sprintf");

#ifdef __cplusplus
}
#endif
