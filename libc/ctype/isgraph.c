#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __isgraph (int c)
{
    return ((c != 0x7F) && (((unsigned)c - 0x21) < 0x5E));
}

int isgraph (int c) \
    _WEAK_ALIAS_OF("__isgraph");

#ifdef __cplusplus
}
#endif
