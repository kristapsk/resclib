#define _RECLIB_SOURCE
#include <stdlib.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

static __thread int _errno = 0;

int* __errno_location (void)
{
    return &_errno;
}

errno_t ___set_errno (int value)
{
    _errno = value;
    return 0;
}

errno_t _set_errno (int value) \
    _WEAK_ALIAS_OF("___set_errno");

#ifdef __cplusplus
}
#endif
