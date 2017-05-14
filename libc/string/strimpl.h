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
        ___set_errno(err); \
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

#define _IMPLEMENT_STRCHR(type, str, c) \
{ \
    while ((*str != 0) && (*str != c)) { \
        str++; \
    } \
    return ((*str == c) ? (type*)str : NULL); \
}

#define _IMPLEMENT_STRRCHR(type, str, c, strchr) \
{ \
    const type* last = NULL; \
    if (c == 0) { \
        return __ ## strchr(str, c); \
    } \
    while ((str = __ ## strchr(str, c)) != NULL) { \
        last = str; \
        str++; \
    } \
    return (type*)last; \
}

#define _IMPLEMENT_STRPBRK(type, str1, str2, strchr) \
{ \
    const type* c_str1 = (const type*)str1; \
    for (; *c_str1 != 0; c_str1++) { \
        if (__ ## strchr(str2, *c_str1) != NULL) { \
            return (type*)c_str1; \
        } \
    } \
    return NULL; \
}

#define _IMPLEMENT_STRCSPN(type, str1, str2, strchr) \
{ \
    const type* c_str1 = (const type*)str1; \
    while (*str1) { \
        if (__ ## strchr(str2, *str1)) { \
            break; \
        } \
        str1++; \
    } \
    return (size_t)(str1 - c_str1); \
}

#define _IMPLEMENT_STRSPN(type, str1, str2, strchr) \
{ \
    const type* c_str1 = (const type*)str1; \
    while (*str1) { \
        if (__ ## strchr(str2, *str1) == NULL) { \
            break; \
        } \
        str1++; \
    } \
    return (size_t)(str1 - c_str1); \
}

#define _IMPLEMENT_STRCMP_HEAD(type, str1, str2) \
{

#define _IMPLEMENT_STRCMP_TAIL(type, str1, str2) \
        if (*str1 == 0) { \
            return 0; \
        } \
        str1++; \
        str2++; \
    } \
    return (*(const type*)str1 - *(const type*)str2); \
}    

#define _IMPLEMENT_STRCMP(type, str1, str2) \
    _IMPLEMENT_STRCMP_HEAD(type, str1, str2) \
    while (*str1 == *str2) { \
    _IMPLEMENT_STRCMP_TAIL(type, str1, str2) 

#define _IMPLEMENT_STRICMP(type, str1, str2, tolower) \
    _IMPLEMENT_STRCMP_HEAD(type, str1, str2) \
    while (tolower(*str1) == tolower(*str2)) { \
    _IMPLEMENT_STRCMP_TAIL(type, str1, str2) 

#define _IMPLEMENT_STRNCMP_HEAD(type, str1, str2, num) \
{ \
    if (num == 0) { \
        return 0; \
    }

#define _IMPLEMENT_STRNCMP_TAIL(type, str1, str2, num) \
        num--; \
        if ((num == 0) || (*str1 == 0)) { \
            return 0; \
        } \
        str1++; \
        str2++; \
    } \
    return (*(const type*)str1 - *(const type*)str2); \
}

#define _IMPLEMENT_STRNCMP(type, str1, str2, num) \
    _IMPLEMENT_STRNCMP_HEAD(type, str1, str2, num) \
    while (*str1 == *str2) { \
    _IMPLEMENT_STRNCMP_TAIL(type, str1, str2, num)

#define _IMPLEMENT_STRNICMP(type, str1, str2, num, tolower) \
    _IMPLEMENT_STRNCMP_HEAD(type, str1, str2, num) \
    while (tolower(*str1) == tolower(*str2)) { \
    _IMPLEMENT_STRNCMP_TAIL(type, str1, str2, num)

#define _IMPLEMENT_STRCPY(type, dest, src) \
{ \
    type* ldest = dest; \
    while ((*ldest++ = *src++) != 0); \
    return dest; \
}

#define _IMPLEMENT_STRNCPY(type, dest, src, num, bzero) \
{ \
    type* ldest = dest; \
    while (num-- > 0) { \
        if ((*ldest++ = *src++) == 0) { \
            __ ## bzero(ldest, num); \
            break; \
        } \
    } \
    return dest; \
}

#define _IMPLEMENT_STRLEN(type, str) \
{ \
    const type* ptr = str; \
    while (*ptr != 0) { \
        ptr++; \
    } \
    return (size_t)(ptr - str); \
}

#define _IMPLEMENT_STRCAT(type, dest, src) \
{ \
    type* ldest = dest; \
    while (*ldest != 0) { \
        ldest++; \
    } \
    while ((*ldest = *src++) != 0) { \
        ldest++; \
    } \
    *ldest = 0; \
    return dest; \
}

#define _IMPLEMENT_STRNCAT(type, dest, src, num) \
{ \
    type* ldest = dest; \
    while (*ldest != 0) { \
        ldest++; \
    } \
    while ((num != 0) && ((*ldest = *src++) != 0)) { \
        num--; \
        ldest++; \
    } \
    *ldest = 0; \
    return dest; \
}

#define _IMPLEMENT_STRSTR(type, haystack, needle, strlen, strchr, strncmp) \
{ \
    if (*needle == 0) { \
        return (type*)haystack; \
    } \
    size_t needlelen = __ ## strlen(needle); \
    for (; (haystack = __ ## strchr(haystack, *needle)) != NULL; haystack++) { \
        if (__ ## strncmp(haystack, needle, needlelen) == 0) { \
            return (type*)haystack; \
        } \
    } \
    return NULL; \
}

#define _IMPLEMENT_STRREV(type, str, strlen) \
{ \
    size_t len = __ ## strlen(str); \
    size_t halflen = len >> 1; \
    size_t i; \
    for (i = 0; i < halflen; i++) { \
        type tmp = str[i]; \
        str[i] = str[len - i - 1]; \
        str[len - i - 1] = tmp; \
    } \
    return str; \
}

