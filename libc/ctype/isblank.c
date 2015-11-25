#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __isblank (int c)
{
    return (c == ' ' || c == '\t');
}

int isblank (int c) \
    _WEAK_ALIAS_OF("__isblank");

#ifdef __cplusplus
}
#endif
