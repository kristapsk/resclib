#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __strstr (const char* haystack, const char* needle)
    _IMPLEMENT_STRSTR(char, haystack, needle, strlen, strchr, strncmp)

char* strstr (const char* haystack, const char* needle)
    _WEAK_ALIAS_OF("__strstr");

#ifdef __cplusplus
}
#endif

