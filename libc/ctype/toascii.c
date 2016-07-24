#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __toascii (int c)
{
    return (c & 0x7F);
}

int toascii (int c) \
    _WEAK_ALIAS_OF("__toascii");

#ifdef __cplusplus
}
#endif
