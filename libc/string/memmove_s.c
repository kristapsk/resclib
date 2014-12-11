#include "strimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

errno_t __memmove_s (void* dest, size_t dest_nbytes, const void* src, size_t num)
    _IMPLEMENT_MEMMOVE_S(memmove, dest, dest_nbytes, src, num);

errno_t memmove_s (void* dest, size_t dest_nbytes, const void* src, size_t num) 
    _WEAK_ALIAS_OF("__memmove_s");

#ifdef __cplusplus
}
#endif
