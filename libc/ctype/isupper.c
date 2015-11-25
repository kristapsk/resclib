#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __isupper (int c)
{
    return ((unsigned)c - 'A') < 26;
}

int isupper (int c) \
    _WEAK_ALIAS_OF("__isupper");

#ifdef __cplusplus
}
#endif
