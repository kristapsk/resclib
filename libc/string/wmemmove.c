#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* __wmemmove (wchar_t* dest, const wchar_t* source, size_t num)
    _IMPLEMENT_MEMMOVE(wchar_t, dest, source, num, wmemcpy);

wchar_t* wmemmove (wchar_t* dest, const wchar_t* source, size_t num)
    _WEAK_ALIAS_OF("__wmemmove");

#ifdef __cplusplus
}
#endif

