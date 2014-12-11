#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* __wcspbrk (wchar_t* str1, const wchar_t* str2)
    _IMPLEMENT_STRPBRK(wchar_t, str1, str2, wcschr)

wchar_t* wcspbrk (wchar_t* str1, const wchar_t* str2)
    _WEAK_ALIAS_OF("__wcspbrk");

#ifdef __cplusplus
}
#endif

