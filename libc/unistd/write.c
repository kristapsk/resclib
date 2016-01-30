#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

extern ssize_t __write (int fd, const void* buf, size_t nbytes);

#pragma weak write
ssize_t write (int fd, const void* buf, size_t nbytes)
{
    return __write(fd, buf, nbytes);
}

#ifdef __cplusplus
}
#endif
