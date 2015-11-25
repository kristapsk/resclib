#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __toupper (int c)
{
    if (__isalpha(c)) {
        return (c & ~0x20);
    }
    else {
        return c;
    }
}

int toupper (int c) \
    _WEAK_ALIAS_OF("__toupper");

#ifdef __cplusplus
}
#endif
