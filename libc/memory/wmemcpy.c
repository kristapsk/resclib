#include "memimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* __wmemcpy (wchar_t* dest, const wchar_t* source, size_t num)
    _IMPLEMENT_MEMCPY(wchar_t, dest, source, num);

wchar_t* wmemcpy (wchar_t* dest, const wchar_t* source, size_t num) 
    _WEAK_ALIAS_OF("__wmemcpy");

#ifdef __cplusplus
}
#endif

