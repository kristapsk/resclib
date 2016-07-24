#include "../intern.h"
#include "stdimpl.h"
#define _RESCLIB_SOURCE
#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif

errno_t ___i64toa_s (__int64 value, char* dest, size_t dest_nbytes, int radix)
{
    _IMPLEMENT_ITOA_S(__int64, value, char, dest, dest_nbytes, radix, llabs, strrev)
}

errno_t _i64toa_s (__int64 value, char* dest, size_t dest_nbytes, int radix) \
    _WEAK_ALIAS_OF("___i64toa_s");

#ifdef __cplusplus
}
#endif
