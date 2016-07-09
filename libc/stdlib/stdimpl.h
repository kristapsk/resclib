#ifndef __STDIMPL_H
#define __STDIMPL_H

#include "../intern.h"
#include <limits.h>
#include <stdlib.h>

// This is a well known bithack for abs() to avoid branching.
// http://graphics.stanford.edu/~seander/bithacks.html#IntegerAbs
#define _IMPLEMENT_ABS(type, x) \
{ \
    type mask = x >> (sizeof(type) * CHAR_BIT - 1); \
    return (x + mask) ^ mask; \
} 

#define _IMPLEMENT_DIV(type, numer, denom) \
{ \
    type res; \
    res.quot = numer / denom; \
    res.rem = numer % denom; \
    return res; \
}

#define _IMPLEMENT_UITOA_S_BASE(itype, value, otype, dest, dest_nbytes, radix) \
    const otype convtable[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; \
    if (dest == NULL || dest_nbytes <= 1 || radix < 2 || radix > 36) { \
        ___set_errno(EINVAL); \
        return EINVAL; \
    } \
    otype* out = dest; \
    do { \
        if (dest_nbytes <= 1) { \
            ___set_errno(EINVAL); \
            return EINVAL; \
        } \
        itype tmp = value / radix; \
        *out++ = convtable[value - (tmp * radix)]; \
        value = tmp; \
        dest_nbytes--; \
    } while (value);

#define _IMPLEMENT_UITOA_S(itype, value, otype, dest, dest_nbytes, radix, strrev) \
    _IMPLEMENT_UITOA_S_BASE(itype, value, otype, dest, dest_nbytes, radix) \
    *out = '\0'; \
    __ ## strrev(dest); \
    return 0;

#define _IMPLEMENT_ITOA_S(itype, svalue, otype, dest, dest_nbytes, radix, abs, strrev) \
    itype uvalue = __ ## abs(svalue); \
    _IMPLEMENT_UITOA_S_BASE(itype, uvalue, otype, dest, dest_nbytes, radix) \
    if (svalue < 0) { \
        if (dest_nbytes > 1) { \
            *out++ = '-'; \
        } \
        else { \
            ___set_errno(EINVAL); \
            return EINVAL; \
        } \
    } \
    *out = '\0'; \
    __ ## strrev(dest); \
    return 0;

#endif
