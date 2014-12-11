#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __strncpy (char* dest, const char* src, size_t num)
    _IMPLEMENT_STRNCPY(char, dest, src, num)

char* strncpy (char* dest, const char* src, size_t num)
    _WEAK_ALIAS_OF("__strncpy");

#ifdef __cplusplus
}
#endif

