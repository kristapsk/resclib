#include "memimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

void* __memset (void* dest, int c, size_t nbytes)
    _IMPLEMENT_MEMSET(unsigned char, dest, c, nbytes);

void* memset (void* dest, int c, size_t nbytes)
    _WEAK_ALIAS_OF("__memset");

#ifdef __cplusplus
}
#endif

