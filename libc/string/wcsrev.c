#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* __wcsrev (wchar_t* str) \
    _IMPLEMENT_STRREV(wchar_t, str, wcslen);

wchar_t* wcsrev (wchar_t* str) \
    _WEAK_ALIAS_OF("__wcsrev");

#ifdef __cplusplus
}
#endif
