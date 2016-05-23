#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

int __strcmp (const char* str1, const char* str2)
    _IMPLEMENT_STRCMP(unsigned char, str1, str2)

int strcmp (const char* str1, const char* str2)
    _WEAK_ALIAS_OF("__strcmp");

#ifdef __cplusplus
}
#endif

