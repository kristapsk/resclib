#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __isspace (int c)
{
    return (c == ' ' || ((unsigned)c - '\t') < 5);
}

int isspace (int c) \
    _WEAK_ALIAS_OF("__isspace");

#ifdef __cplusplus
}
#endif
