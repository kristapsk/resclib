#include <stdio.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __snprintf (char* buf, size_t buf_nbytes, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    int res = __vsnprintf(buf, buf_nbytes, format, args);
    va_end(args);
    return res;
}

int snprintf (char* buf, size_t buf_nbytes, const char* format, ...)
    _WEAK_ALIAS_OF("__snprintf");

#ifdef __cplusplus
}
#endif
