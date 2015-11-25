#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __islower (int c)
{
    return ((unsigned)c - 'a') < 26;
}

int islower (int c) \
    _WEAK_ALIAS_OF("__islower");

#ifdef __cplusplus
}
#endif
