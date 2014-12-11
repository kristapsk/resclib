#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

void __wzero (wchar_t* dest, size_t num)
{
    __wmemset(dest, 0, num);
}

void wzero (wchar_t* dest, size_t num)
    _WEAK_ALIAS_OF("__wzero");

#ifdef __cplusplus
}
#endif

