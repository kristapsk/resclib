#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t __wcscspn (const wchar_t* str1, const wchar_t* str2)
    _IMPLEMENT_STRCSPN(wchar_t, str1, str2, wcschr)

size_t wcscspn (const wchar_t* str1, const wchar_t* str2)
    _WEAK_ALIAS_OF("__wcscspn");

#ifdef __cplusplus
}
#endif

