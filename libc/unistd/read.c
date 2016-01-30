#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

extern ssize_t __read (int fd, void* buf, size_t nbytes);

#pragma weak read
ssize_t read (int fd, void* buf, size_t nbytes)
{
    return __read(fd, buf, nbytes);
}

#ifdef __cplusplus
}
#endif
