#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __ispunct (int c)
{
    return __isgraph(c) && !__isalnum(c);
}

int ispunct (int c) \
    _WEAK_ALIAS_OF("__ispunct");

#ifdef __cplusplus
}
#endif
