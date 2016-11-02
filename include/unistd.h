#ifndef _UNISTD_H
#define _UNISTD_H

#include <_pid_t.h>
#include <_size_t.h>
#include <_ssize_t.h>

#define STDIN_FILENO    (0)
#define STDOUT_FILENO   (1)
#define STDERR_FILENO   (2)

#ifdef __cplusplus
extern "C" {
#endif

pid_t getpid (void);
ssize_t read (int fd, void* buf, size_t nbytes);
ssize_t write (int fd, const void* buf, size_t nbytes);

#ifdef __cplusplus
}
#endif

#endif
