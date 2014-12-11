#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t __strspn (const char* str1, const char* str2)
    _IMPLEMENT_STRSPN(char, str1, str2, strchr)

size_t strspn (const char* str1, const char* str2)
    _WEAK_ALIAS_OF("__strspn");

#ifdef __cplusplus
}
#endif

