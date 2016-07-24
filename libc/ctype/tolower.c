#include "../intern.h"
#include <ctype.h>

#ifdef __cplusplus
extern "C" {
#endif

int __tolower (int c)
{
    return (__isalpha(c) ? _tolower(c) : c);
}

int tolower (int c) \
    _WEAK_ALIAS_OF("__tolower");

#ifdef __cplusplus
}
#endif
