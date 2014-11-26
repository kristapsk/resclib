#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __strcat (char* dest, const char* src)
    _IMPLEMENT_STRCAT(char, dest, src)

char* strcat (char* dest, const char* src)
    _WEAK_ALIAS_OF("__strcat");

#ifdef __cplusplus
}
#endif

