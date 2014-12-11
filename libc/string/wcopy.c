#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

void __wcopy (const wchar_t* ptr1, wchar_t* ptr2, size_t num)
{
    __wmemmove(ptr2, ptr1, num);
}

void wcopy (const wchar_t* ptr1, wchar_t* ptr2, size_t num)
    _WEAK_ALIAS_OF("__wcopy");

#ifdef __cplusplus
}
#endif
