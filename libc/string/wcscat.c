#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* __wcscat (wchar_t* dest, const wchar_t* src)
    _IMPLEMENT_STRCAT(wchar_t, dest, src)

wchar_t* wcscat (wchar_t* dest, const wchar_t* src)
    _WEAK_ALIAS_OF("__wcscat");

#ifdef __cplusplus
}
#endif

