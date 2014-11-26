#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

int __memcmp (const void* str1, const void* str2, size_t nbytes)
    _IMPLEMENT_MEMCMP(unsigned char, str1, str2, nbytes);

int memcmp (const void* str1, const void* str2, size_t nbytes) 
    _WEAK_ALIAS_OF("__memcmp");

#ifdef __cplusplus
}
#endif

