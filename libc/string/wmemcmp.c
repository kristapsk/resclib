#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

int __wmemcmp (const wchar_t* str1, const wchar_t* str2, size_t num)
    _IMPLEMENT_MEMCMP(wchar_t, str1, str2, num);

int wmemcmp (const wchar_t* str1, const wchar_t* str2, size_t num) 
    _WEAK_ALIAS_OF("__wmemcmp");

#ifdef __cplusplus
}
#endif

