#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* __wcscpy (wchar_t* dest, const wchar_t* src)
    _IMPLEMENT_STRCPY(wchar_t, dest, src)

wchar_t* wcscpy (wchar_t* dest, const wchar_t* src)
    _WEAK_ALIAS_OF("__wcscpy");

#ifdef __cplusplus
}
#endif

