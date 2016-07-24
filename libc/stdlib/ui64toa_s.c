#include "../intern.h"
#include "stdimpl.h"
#define _RESCLIB_SOURCE
#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif

errno_t ___ui64toa_s (unsigned __int64 value, char* dest,
    size_t dest_nbytes, int radix)
{
    _IMPLEMENT_UITOA_S(unsigned __int64, value, char, dest, dest_nbytes,
        radix, strrev)
}

errno_t _ui64toa_s (unsigned __int64 value, char* dest,
    size_t dest_nbytes, int radix) \
    _WEAK_ALIAS_OF("___ui64toa_s");

#ifdef __cplusplus
}
#endif
