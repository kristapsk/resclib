#include "memimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

void* __wmemchr (const wchar_t* str, wchar_t c, size_t num)
    _IMPLEMENT_MEMCHR(wchar_t, str, c, num);

void* wmemchr (const wchar_t* str, wchar_t c, size_t num)
    _WEAK_ALIAS_OF("__wmemchr");

#ifdef __cplusplus
}
#endif

