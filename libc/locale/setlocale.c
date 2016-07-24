#include <locale.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __setlocale (int category, const char* locale)
{
    if (
            (__strcmp(locale, "C") == 0) || (__strcmp(locale, "POSIX") == 0) ||
            (__strcmp(locale, "") == 0)
    ) {
        return "C"; // fake, we don't support other locales yet
    }
    else {
        return NULL;
    }
}

char* setlocale (int category, const char* locale)
    _WEAK_ALIAS_OF("__setlocale");

#ifdef __cplusplus
}
#endif
