#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* __wcsrchr (const wchar_t* str, wchar_t c)
    _IMPLEMENT_STRRCHR(wchar_t, str, c, wcschr);

wchar_t* wcsrchr (const wchar_t* str, wchar_t c)
    _WEAK_ALIAS_OF("__wcsrchr");

#ifdef __cplusplus
}
#endif

