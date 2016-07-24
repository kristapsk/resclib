#ifndef _STDLIB_H
#define _STDLIB_H

#include <limits.h>
#include <stddef.h>

#ifdef _RESCLIB_SOURCE
    #include <___int.h>
    #include <_errno_t.h>
#endif

#define EXIT_SUCCESS    (0)
#define EXIT_FAILURE    (1)

typedef struct {
    int quot;
    int rem;
} div_t;

typedef struct {
    long quot;
    long rem;
} ldiv_t;

#if (__STDC_VERSION__ >= 199901L)
    typedef struct {
        long long quot;
        long long rem;
    } lldiv_t;
#endif

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

#ifdef _RESCLIB_SOURCE

    #ifdef __cplusplus
        template <typename T, size_t N> inline size_t _countof
            (const T (&array)[N])
            { return N; }
    #else
        #define _countof(array) (sizeof(array) / sizeof(array[0]))
    #endif

#endif

#ifdef __cplusplus
extern "C" {
#endif

/*** String conversions ****************************************************/
#ifdef _RESCLIB_SOURCE
    errno_t _itoa_s (int value, char* dest, size_t dest_nbytes, int radix);
    errno_t _i64toa_s (__int64 value, char* dest,
        size_t dest_nbytes, int radix);
    errno_t _ui64toa_s (unsigned __int64 value, char* dest,
        size_t dest_nbytes, int radix);
#endif

/*** Environment ***********************************************************/
void _Exit (int status);

/*** Integer arithmetics ***************************************************/
int abs (int x);
div_t div (int numer, int denom);
long labs (long x);
ldiv_t ldiv (long numer, long denom);
long long llabs (long long x);
#if (__STDC_VERSION__ >= 199901L)
    lldiv_t lldiv (long long numer, long long denom);
#endif

/*** Multibyte characters **************************************************/
int mblen (const char* pmb, size_t max);

/*** Misc ******************************************************************/
#ifdef _RESCLIB_SOURCE
    errno_t _get_errno (int* pvalue);
    errno_t _set_errno (int value);
#endif

#ifdef __cplusplus
}
#endif

#endif
