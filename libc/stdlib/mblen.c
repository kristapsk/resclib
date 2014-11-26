#include "../intern.h"
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

// Based on utf8_mblen() from
//  http://svn.r-project.org/R/trunk/src/extra/win_iconv/win_iconv.c

int __mblen (const char* pmb, size_t max)
{
    if (pmb == NULL) {
        return 0;
    }
    else if ((*pmb == '\0') || (max == 0)) {
        return 0;
    }

    int len = 0;
    if (*pmb < 0x80) {
        len = 1;
    }
    else if ((*pmb & 0xE0) == 0xC0) {
        len = 2;
    }
    else if ((*pmb & 0xF0) == 0xE0) {
        len = 3;
    }
    else if ((*pmb & 0xF8) == 0xF0) {
        len = 4;
    }
    else if ((*pmb & 0xFC) == 0xF8) {
        len = 5;
    }
    else if ((*pmb & 0xFE) == 0xFC) {
        len = 6;
    }

    if ((len == 0) || (len > max)) {
        return -1;
    }
    else {
        return len;
    }
}

int mblen (const char* pmb, size_t max) \
    _WEAK_ALIAS_OF("__mblen");

#ifdef __cplusplus
}
#endif

