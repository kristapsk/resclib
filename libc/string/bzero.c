#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

void __bzero (void* dest, size_t nbytes)
{
    __memset(dest, 0, nbytes);
}

void bzero (void* dest, size_t nbytes) \
    _WEAK_ALIAS_OF("__bzero");

#ifdef __cplusplus
}
#endif

