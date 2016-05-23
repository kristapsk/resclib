#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

int __strnicmp (const char* str1, const char* str2, size_t num)
    _IMPLEMENT_STRNICMP(unsigned char, str1, str2, num, __tolower)

int _strnicmp (const char* str1, const char* str2, size_t num)
    _WEAK_ALIAS_OF("__strnicmp");
int strncasecmp (const char* str1, const char* str2, size_t num)
    _WEAK_ALIAS_OF("__strnicmp");

#ifdef __cplusplus
}
#endif

