#include "memimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

errno_t __memcpy_s (void* dest, size_t dest_nbytes, const void* src, size_t num)
    _IMPLEMENT_MEMCPY_S(memcpy, dest, dest_nbytes, src, num);

errno_t memcpy_s (void* dest, size_t dest_nbytes, const void* src, size_t num) 
    _WEAK_ALIAS_OF("__memcpy_s");

#ifdef __cplusplus
}
#endif
