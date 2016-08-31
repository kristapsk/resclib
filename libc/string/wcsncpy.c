#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* __wcsncpy (wchar_t* dest, const wchar_t* src, size_t num)
    _IMPLEMENT_STRNCPY(wchar_t, dest, src, num, wzero)

wchar_t* wcsncpy (wchar_t* dest, const wchar_t* src, size_t num)
    _WEAK_ALIAS_OF("__wcsncpy");

#ifdef __cplusplus
}
#endif

