#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __strchr (const char* str, int c)
    _IMPLEMENT_STRCHR(char, str, c);

char* strchr (const char* str, int c)
    _WEAK_ALIAS_OF("__strchr");

#ifdef __cplusplus
}
#endif

