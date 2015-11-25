#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __isalnum (int c)
{
    return (__isalpha(c) || __isdigit(c));
}

int isalnum (int c) \
    _WEAK_ALIAS_OF("__isalnum");

#ifdef __cplusplus
}
#endif
