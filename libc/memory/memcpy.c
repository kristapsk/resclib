#include "../intern.h"
#include <memory.h>

#ifdef __cplusplus
extern "C" {
#endif

void* __memcpy (void* dest, const void* source, size_t nbytes)
{
    char* c_dest = (char*)dest;
    const char* c_source = (const char*)source;
    while (nbytes--) {
        *c_dest++ = *c_source++;
    }
    return dest;
}

void* memcpy (void* dest, const void* source, size_t nbytes) \
    _WEAK_ALIAS_OF("__memcpy");

#ifdef __cplusplus
}
#endif

