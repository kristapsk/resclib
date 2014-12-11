#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t __strlen (const char* str)
    _IMPLEMENT_STRLEN(char, str)

size_t strlen (const char* str)
    _WEAK_ALIAS_OF("__strlen");

#ifdef __cplusplus
}
#endif

