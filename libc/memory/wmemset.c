#include "memimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* __wmemset (wchar_t* dest, wchar_t c, size_t num)
    _IMPLEMENT_MEMSET(wchar_t, dest, c, num);

wchar_t* wmemset (wchar_t* dest, wchar_t c, size_t num)
    _WEAK_ALIAS_OF("__wmemset");

#ifdef __cplusplus
}
#endif

