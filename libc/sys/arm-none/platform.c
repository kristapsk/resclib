// Implement board

#include <unistd.h>

#define SERIAL_BASE 0x16000000
#define SERIAL_FLAG_REGISTER 0x18
#define SERIAL_BUFFER_FULL (1 << 5)

ssize_t __read (int fd, void* buf, size_t nbytes)
{
    // Must be implemented
}

ssize_t __write (int fd, const void* buf, size_t nbytes)
{
    // Must be implemented
    const char* cbuf = (const char*)buf;
    size_t i;
    for (i = 0; i < nbytes; i++) {
        while (*(volatile unsigned long*)(SERIAL_BASE + SERIAL_FLAG_REGISTER) 
                                               & (SERIAL_BUFFER_FULL));
        *(volatile unsigned long*)SERIAL_BASE = *cbuf++;
    }
    return i;
}

