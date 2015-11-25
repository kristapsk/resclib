#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __isdigit (int c)
{
    return ((unsigned)c - '0') < 10;
}

int isdigit (int c) \
    _WEAK_ALIAS_OF("__isdigit");

#ifdef __cplusplus
}
#endif
