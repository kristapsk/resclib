#ifndef _WCHAR_H
#define _WCHAR_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* wmemchr (const wchar_t* str, wchar_t c, size_t num);
int wmemcmp (const wchar_t* str1, const wchar_t* str2, size_t num);
wchar_t* wmemcpy (wchar_t* dest, const wchar_t* source, size_t num);
wchar_t* wmemmove (wchar_t* dest, const wchar_t* source, size_t num);
wchar_t* wmemset (wchar_t* dest, wchar_t c, size_t num);

#if (__STDC_VERSION__ >= 201112L)
    #include <_errno_t.h>
    errno_t wmemcpy_s
        (wchar_t* dest, size_t dest_num, const wchar_t* src, size_t num);
    errno_t wmemmove_s
        (wchar_t* dest, size_t dest_num, const wchar_t* src, size_t num);
#endif

#ifdef __cplusplus
}
#endif

#endif
