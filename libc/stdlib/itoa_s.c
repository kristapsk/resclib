#include "../intern.h"
#include "stdimpl.h"
#define _RESCLIB_SOURCE
#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif

errno_t ___itoa_s (int value, char* dest, size_t dest_nbytes, int radix)
{
    _IMPLEMENT_ITOA_S(int, value, char, dest, dest_nbytes, radix, abs, strrev)
}

errno_t _itoa_s (int value, char* dest, size_t dest_nbytes, int radix) \
    _WEAK_ALIAS_OF("___itoa_s");

#ifdef __cplusplus
}
#endif
