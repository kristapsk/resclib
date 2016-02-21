#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __strrev (char* str) \
    _IMPLEMENT_STRREV(char, str, strlen);

char* strrev (char* str) \
    _WEAK_ALIAS_OF("__strrev");

#ifdef __cplusplus
}
#endif
