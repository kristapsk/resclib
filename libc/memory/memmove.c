#include "../intern.h"
#include <memory.h>

#ifdef __cplusplus
extern "C" {
#endif

void* __memmove (void* dest, const void* source, size_t nbytes)
{
    char* c_dest = (char*)dest;
    const char* c_source = (const char*)source;
    if (c_source < c_dest) {
        while (nbytes--) {
            c_dest[nbytes] = c_source[nbytes];
        }
    }
    else {
        while (nbytes--) {
            *c_dest++ = *c_source++;
        }
    }
    return dest;
}

void* memmove (void* dest, const void* source, size_t nbytes) \
    _WEAK_ALIAS_OF("__memmove");

#ifdef __cplusplus
}
#endif

