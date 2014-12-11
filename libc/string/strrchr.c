#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __strrchr (const char* str, int c)
    _IMPLEMENT_STRRCHR(char, str, c, strchr);

char* strrchr (const char* str, int c)
    _WEAK_ALIAS_OF("__strrchr");

#ifdef __cplusplus
}
#endif

