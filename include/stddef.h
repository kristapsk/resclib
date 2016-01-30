#ifndef _STDDEF_H
#define _STDDEF_H

#include <___int.h>
#include <_null.h>
#include <_size_t.h>

typedef signed long ptrdiff_t;

#ifndef __cplusplus
    typedef unsigned __int32 wchar_t;
#endif

#define offsetof(type,member) (size_t)&(((type*)0)->member)

#if (__STDC_VERSION__ >= 201112L) || (__cplusplus >= 201103L)
    typedef long double max_align_t;
#endif

#ifdef __cplusplus
namespace std
{
    using ::ptrdiff_t;
    using ::size_t;
    #if __cplusplus >= 201103L
        using ::max_align_t;
        typedef decltype(nullptr) nullptr_t;
    #endif
}
#endif

#endif
