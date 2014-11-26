#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t __wcslen (const wchar_t* str)
    _IMPLEMENT_STRLEN(wchar_t, str)

size_t wcslen (const wchar_t* str)
    _WEAK_ALIAS_OF("__wcslen");

#ifdef __cplusplus
}
#endif

