#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

int __wcsncmp (const wchar_t* str1, const wchar_t* str2, size_t num)
    _IMPLEMENT_STRNCMP(wchar_t, str1, str2, num)

int wcsncmp (const wchar_t* str1, const wchar_t* str2, size_t num)
    _WEAK_ALIAS_OF("__wcsncmp");

#ifdef __cplusplus
}
#endif

