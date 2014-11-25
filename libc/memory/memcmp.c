#include "../intern.h"
#include <memory.h>

#ifdef __cplusplus
extern "C" {
#endif

int __memcmp (const void* str1, const void* str2, size_t nbytes)
{
    const unsigned char* c_str1 = (const unsigned char*)str1;
    const unsigned char* c_str2 = (const unsigned char*)str2;
    while (nbytes--) {
        if (*c_str1 != *c_str2) {
            return *c_str1 - *c_str2;
        }
        c_str1++;
        c_str2++;
    }
    return 0;
}

int memcmp (const void* str1, const void* str2, size_t nbytes) \
    _WEAK_ALIAS_OF("__memcmp");

#ifdef __cplusplus
}
#endif

