#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* __wcschr (const wchar_t* str, wchar_t c)
    _IMPLEMENT_STRCHR(wchar_t, str, c);

wchar_t* wcschr (const wchar_t* str, wchar_t c)
    _WEAK_ALIAS_OF("__wcschr");

#ifdef __cplusplus
}
#endif

