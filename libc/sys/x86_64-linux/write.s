use64
global __write

; ssize_t write (int fd, const void* buf, size_t nbytes)
__write:
    mov     eax, 1
    syscall
    ret

