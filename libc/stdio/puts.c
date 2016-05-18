#include <stdio.h>
#include <unistd.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __puts (const char* str)
{
    int res = __fputs(str, stdout);
    if (res >= 0) {
        res = __fputc('\n', stdout);
    }
    return res;
}

int puts (const char* str)
    _WEAK_ALIAS_OF("__puts");

#ifdef __cplusplus
}
#endif
