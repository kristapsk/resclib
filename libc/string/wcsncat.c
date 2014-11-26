#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* __wcsncat (wchar_t* dest, const wchar_t* src, size_t num)
    _IMPLEMENT_STRNCAT(wchar_t, dest, src, num)

wchar_t* wcsncat (wchar_t* dest, const wchar_t* src, size_t num)
    _WEAK_ALIAS_OF("__wcsncat");

#ifdef __cplusplus
}
#endif

