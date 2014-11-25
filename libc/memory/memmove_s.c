#define _RECLIB_SOURCE
#include <errno.h>
#include <memory.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

errno_t __memmove_s (void* dest, size_t dest_nbytes, const void* src, size_t num)
{
    errno_t err = 0;
    if ((dest == NULL) || (src == NULL)) {
        err = EINVAL;
    }
    else if (dest_nbytes < num) {
        err = ERANGE;
    }
    if (err != 0) {
        _set_errno(err);
        return err;
    }
    
    __memmove(dest, src, num);
    return 0;
}

errno_t memmove_s (void* dest, size_t dest_nbytes, const void* src, size_t num) \
    _WEAK_ALIAS_OF("__memmove_s");

#ifdef __cplusplus
}
#endif
