#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

void* __memcpy (void* dest, const void* source, size_t nbytes)
    _IMPLEMENT_MEMCPY(unsigned char, dest, source, nbytes);

void* memcpy (void* dest, const void* source, size_t nbytes) 
    _WEAK_ALIAS_OF("__memcpy");

#ifdef __cplusplus
}
#endif

