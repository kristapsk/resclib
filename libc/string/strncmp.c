#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

int __strncmp (const char* str1, const char* str2, size_t num)
    _IMPLEMENT_STRNCMP(unsigned char, str1, str2, num)

int strncmp (const char* str1, const char* str2, size_t num)
    _WEAK_ALIAS_OF("__strncmp");

#ifdef __cplusplus
}
#endif

