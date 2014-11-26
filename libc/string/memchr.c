#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

void* __memchr (const void* str, int c, size_t nbytes)
    _IMPLEMENT_MEMCHR(unsigned char, str, c, nbytes);

void* memchr (const void* str, int c, size_t nbytes)
    _WEAK_ALIAS_OF("__memchr");

#ifdef __cplusplus
}
#endif

