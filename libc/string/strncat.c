#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __strncat (char* dest, const char* src, size_t num)
    _IMPLEMENT_STRNCAT(char, dest, src, num)

char* strncat (char* dest, const char* src, size_t num)
    _WEAK_ALIAS_OF("__strncat");

#ifdef __cplusplus
}
#endif

