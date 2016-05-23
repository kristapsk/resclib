#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

int __stricmp (const char* str1, const char* str2)
    _IMPLEMENT_STRICMP(unsigned char, str1, str2, __tolower)

int _stricmp (const char* str1, const char* str2)
    _WEAK_ALIAS_OF("__stricmp");
int strcasecmp (const char* str1, const char* str2)
    _WEAK_ALIAS_OF("__stricmp");

#ifdef __cplusplus
}
#endif

