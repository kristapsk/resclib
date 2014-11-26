#include "memimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

void* __memmove (void* dest, const void* source, size_t nbytes)
    _IMPLEMENT_MEMMOVE(unsigned char, dest, source, nbytes, memcpy);

void* memmove (void* dest, const void* source, size_t nbytes)
    _WEAK_ALIAS_OF("__memmove");

#ifdef __cplusplus
}
#endif

