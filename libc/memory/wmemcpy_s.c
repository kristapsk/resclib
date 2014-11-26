#include "memimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

errno_t __wmemcpy_s (wchar_t* dest, size_t dest_num, const wchar_t* src, size_t num)
    _IMPLEMENT_MEMCPY_S(wmemcpy, dest, dest_num, src, num);

errno_t wmemcpy_s (wchar_t* dest, size_t dest_num, const wchar_t* src, size_t num) 
    _WEAK_ALIAS_OF("__wmemcpy_s");

#ifdef __cplusplus
}
#endif
