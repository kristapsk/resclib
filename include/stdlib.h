#ifndef _STDLIB_H
#define _STDLIB_H

#include <limits.h>
#include <stddef.h>

#define EXIT_SUCCESS    (0)
#define EXIT_FAILURE    (1)

#define __min(x,y) \
    ({ \
        typeof(x) __x = (x); \
        typeof(y) __y = (y); \
        (void)(&__x == &__y); \
        __x < __y ? __x : __y; \
    })
#define __max(x,y) \
    ({ \
        typeof(x) __x = (x); \
        typeof(y) __y = (y); \
        (void)(&__x == &__y); \
        __x > __y ? __x : __y; \
    })

#ifdef __cplusplus
extern "C" {
#endif

void _Exit (int status);

int abs (int x);
long labs (long x);
long long llabs (long long x);

int mblen (const char* pmb, size_t max);

#ifdef _RECLIB_SOURCE
    #include <___int.h>
    #include <_errno_t.h>
    
    errno_t _get_errno (int* pvalue);
    errno_t _set_errno (int value);

    errno_t _itoa_s (int value, char* dest, size_t dest_nbytes, int radix);
    errno_t _i64toa_s (__int64 value, char* dest,
        size_t dest_nbytes, int radix);
    errno_t _ui64toa_s (unsigned __int64 value, char* dest,
        size_t dest_nbytes, int radix);
#endif

#ifdef __cplusplus
}
#endif

#endif
