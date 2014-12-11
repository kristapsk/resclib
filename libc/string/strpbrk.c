#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __strpbrk (char* str1, const char* str2)
    _IMPLEMENT_STRPBRK(char, str1, str2, strchr)

char* strpbrk (char* str1, const char* str2)
    _WEAK_ALIAS_OF("__strpbrk");

#ifdef __cplusplus
}
#endif

