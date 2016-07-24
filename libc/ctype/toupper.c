#include "../intern.h"
#include <ctype.h>

#ifdef __cplusplus
extern "C" {
#endif

int __toupper (int c)
{
    return (__isalpha(c) ? _toupper(c) : c);
}

int toupper (int c) \
    _WEAK_ALIAS_OF("__toupper");

#ifdef __cplusplus
}
#endif
