#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t __wcsspn (const wchar_t* str1, const wchar_t* str2)
    _IMPLEMENT_STRSPN(wchar_t, str1, str2, wcschr)

size_t wcsspn (const wchar_t* str1, const wchar_t* str2)
    _WEAK_ALIAS_OF("__wcsspn");

#ifdef __cplusplus
}
#endif

