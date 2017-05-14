#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t __strcspn (const char* str1, const char* str2)
    _IMPLEMENT_STRCSPN(char, str1, str2, strchr)

size_t strcspn (const char* str1, const char* str2)
    _WEAK_ALIAS_OF("__strcspn");

#ifdef __cplusplus
}
#endif

