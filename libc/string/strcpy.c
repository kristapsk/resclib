#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __strcpy (char* dest, const char* src)
    _IMPLEMENT_STRCPY(char, dest, src)

char* strcpy (char* dest, const char* src)
    _WEAK_ALIAS_OF("__strcpy");

#ifdef __cplusplus
}
#endif

