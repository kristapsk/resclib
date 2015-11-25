#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __tolower (int c)
{
    if (__isalpha(c)) {
        return (c | 0x20);
    }
    else {
        return c;
    }
}

int tolower (int c) \
    _WEAK_ALIAS_OF("__tolower");

#ifdef __cplusplus
}
#endif
