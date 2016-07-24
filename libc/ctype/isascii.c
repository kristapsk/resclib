#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __isascii (int c)
{
    return (c == (c & 0x7F));
}

int isascii (int c) \
    _WEAK_ALIAS_OF("__isascii");

#ifdef __cplusplus
}
#endif
