#include <stdarg.h>
#include <stdio.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __fprintf (FILE* stream, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    int res = __vfprintf(stream, format, args);
    va_end(args);
    return res;
}

int fprintf (FILE* stream, const char* format, ...)
    _WEAK_ALIAS_OF("__fprintf");

#ifdef __cplusplus
}
#endif
