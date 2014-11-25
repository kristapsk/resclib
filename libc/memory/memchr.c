#include "../intern.h"
#include <memory.h>

#ifdef __cplusplus
extern "C" {
#endif

void* __memchr (const void* str, int c, size_t nbytes)
{
    const unsigned char* c_str = (const unsigned char*)str;
    unsigned char ch = (unsigned char)c;
    while (nbytes--) {
        if (*c_str == ch) {
            return (void*)c_str;
        }
        c_str++;
    }
    return NULL;
}

void* memchr (const void* str, int c, size_t nbytes) \
    _WEAK_ALIAS_OF("__memchr");

#ifdef __cplusplus
}
#endif

