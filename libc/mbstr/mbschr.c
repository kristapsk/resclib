#include <mbstr.h>
#include <stdlib.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __mbschr (char* str, mbchar_t c)
{
    if (c < 0x80) {
        return __strchr(str, c);
    }
    else {
        char buf[sizeof(mbchar_t)+1];
        *((mbchar_t*)buf) = c;
        buf[__min(sizeof(mbchar_t),(size_t)MBMAXLEN)] = '\0';
        return __strstr(str, buf);
    }
}

char* mbschr (char* str, mbchar_t c) \
    _WEAK_ALIAS_OF("__mbschr");

#ifdef __cplusplus
}
#endif
