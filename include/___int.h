#ifndef ____INT
#define ____INT

#include <_portab.h>

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

#define _CHAR_BIT 8
#define _SCHAR_MIN -128
#define _SCHAR_MAX 127
#define _UCHAR_MAX 255
#if ('\x80' < 0)
    #define _CHAR_MIN -128
    #define _CHAR_MAX 127
#else
    #define _CHAR_MIN 0
    #define _CHAR_MAX 255
#endif
#define _SHRT_MIN (-_SHRT_MAX-1)
#define _SHRT_MAX 32767
#define _USHRT_MAX ((unsigned short)65535U)

#define _INT_MIN (-_INT_MAX-1)
#define _INT_MAX 2147483647
#define _UINT_MAX 4294967295U

#define _LLONG_MIN (-_LLONG_MAX-1)
#define _LLONG_MAX 9223372036854775807LL
#define _ULLONG_MAX 18446744073709551615ULL

#if (__WORDSIZE == 64)
    #define _LONG_MIN _LLONG_MIN
    #define _LONG_MAX _LLONG_MAX
    #define _ULONG_MAX _ULLONG_MAX
#else
    #define _LONG_MIN _INT_MIN
    #define _LONG_MAX _INT_MAX
    #define _ULONG_MAX _UINT_MAX
#endif

#define _INT8_MIN _SCHAR_MIN
#define _INT8_MAX _SCHAR_MAX
#define _UINT8_MAX _UCHAR_MAX
#define _INT16_MIN _SHRT_MIN
#define _INT16_MAX _SHRT_MAX
#define _UINT16_MAX _USHRT_MAX
#define _INT32_MIN _INT_MIN
#define _INT32_MAX _INT_MAX
#define _UINT32_MAX _UINT_MAX
#define _INT64_MIN _LLONG_MIN
#define _INT64_MAX _LLONG_MAX
#define _UINT64_MAX _ULLONG_MAX

#define _INT8_C(x) x
#define _UINT8_C(x) x ## U
#define _INT16_C(x) x
#define _UINT16_C(x) x ## U
#define _INT32_C(x) x ## L
#define _UINT32_C(x) x ## UL
#define _INT64_C(x) x ## LL
#define _UINT64_C(x) x ## ULL

#endif
