#include "../intern.h"
#include <errno.h>
#include <memory.h>
#include <stddef.h>

#define _IMPLEMENT_MEMCHR(type, str, c, num) \
{ \
    const type* c_str = (const type*)str; \
    type ch = (type)c; \
    while (num--) { \
        if (*c_str == ch) { \
            return (type*)c_str; \
        } \
        c_str++; \
    } \
    return NULL; \
}

#define _IMPLEMENT_MEMCMP(type, ptr1, ptr2, num) \
{ \
    const type* c_str1 = (const type*)ptr1; \
    const type* c_str2 = (const type*)ptr2; \
    while (num--) { \
        if (*c_str1 != *c_str2) { \
            return *c_str1 - *c_str2; \
        } \
        c_str1++; \
        c_str2++; \
    } \
    return 0; \
}

#define _IMPLEMENT_MEMCPY(type, dest, src, num) \
{ \
    type* c_dest = (type*)dest; \
    const type* c_source = (const type*)source; \
    while (num--) { \
        *c_dest++ = *c_source++; \
    } \
    return dest; \
}

#define _IMPLEMENT_MEMMOVE(type, dest, src, num, memcpy) \
{ \
    type* c_dest = (type*)dest; \
    const type* c_source = (const type*)source; \
    if ((c_source < c_dest) && (c_dest < c_source + num)) { \
        while (num--) { \
            c_dest[num] = c_source[num]; \
        } \
    } \
    else { \
        return __ ## memcpy(dest, src, num); \
    } \
    return dest; \
} 

#define _IMPLEMENT_MEMSET(type, dest, c, num) \
{ \
    type* c_dest = (type*)dest; \
    while (num--) { \
        *c_dest++ = (type)c; \
    } \
    return dest; \
}

#define _IMPLEMENT_PARAMETER_CHECK_S(dest, dest_size, src, num) \
    errno_t err = 0; \
    if ((dest == NULL) || (src == NULL)) { \
        err = EINVAL; \
    } \
    else if (dest_size < num) { \
        err = ERANGE; \
    } \
    if (err != 0) { \
        _set_errno(err); \
        return err; \
    } \

#define _IMPLEMENT_MEMCPY_S(memcpy, dest, dest_size, src, num) \
{ \
    _IMPLEMENT_PARAMETER_CHECK_S(dest, dest_size, src, num); \
    __ ## memcpy(dest, src, num); \
    return 0; \
}

#define _IMPLEMENT_MEMMOVE_S(memmove, dest, dest_size, src, num) \
{ \
    _IMPLEMENT_PARAMETER_CHECK_S(dest, dest_size, src, num); \
    __ ## memmove(dest, src, num); \
    return 0; \
}

