#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __isxdigit (int c)
{
    return (__isdigit(c) || ((unsigned)(c | 0x20) - 'a') < 6);
}

int isxdigit (int c) \
    _WEAK_ALIAS_OF("__isxdigit");

#ifdef __cplusplus
}
#endif
