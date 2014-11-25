#include "../intern.h"
#include <memory.h>

#ifdef __cplusplus
extern "C" {
#endif

void* __memset (void* dest, int c, size_t nbytes)
{
    unsigned char* c_dest = (unsigned char*)dest;
    while (nbytes--) {
        *c_dest++ = (unsigned char)c;
    }
    return dest;
}

void* memset (void* dest, int c, size_t nbytes) \
    _WEAK_ALIAS_OF("__memset");

#ifdef __cplusplus
}
#endif

