#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

int __wcscmp (const wchar_t* str1, const wchar_t* str2)
    _IMPLEMENT_STRCMP(wchar_t, str1, str2)

int wcscmp (const wchar_t* str1, const wchar_t* str2)
    _WEAK_ALIAS_OF("__wcscmp");

#ifdef __cplusplus
}
#endif

