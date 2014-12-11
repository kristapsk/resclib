#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

void __bcopy (const void* ptr1, void* ptr2, size_t nbytes)
{
    __memmove(ptr2, ptr1, nbytes);
}

void bcopy (const void* ptr1, void* ptr2, size_t nbytes)
    _WEAK_ALIAS_OF("__bcopy");

#ifdef __cplusplus
}
#endif
