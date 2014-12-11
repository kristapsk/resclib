#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* __wcsstr (const wchar_t* haystack, const wchar_t* needle)
    _IMPLEMENT_STRSTR(wchar_t, haystack, needle, wcslen, wcschr, wcsncmp)

wchar_t* wcsstr (const wchar_t* haystack, const wchar_t* needle)
    _WEAK_ALIAS_OF("__wcsstr");

#ifdef __cplusplus
}
#endif

