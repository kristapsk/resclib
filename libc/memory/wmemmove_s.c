#include "memimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

errno_t __wmemmove_s (wchar_t* dest, size_t dest_num, const wchar_t* src, size_t num)
    _IMPLEMENT_MEMMOVE_S(wmemmove, dest, dest_num, src, num);

errno_t wmemmove_s (wchar_t* dest, size_t dest_num, const wchar_t* src, size_t num) 
    _WEAK_ALIAS_OF("__wmemmove_s");

#ifdef __cplusplus
}
#endif
