#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __isprint (int c)
{
    return ((c != 0x7F) && (((unsigned)c - 0x20) < 0x5F));
}

int isprint (int c) \
    _WEAK_ALIAS_OF("__isprint");

#ifdef __cplusplus
}
#endif
