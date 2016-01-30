use64
global __read

; ssize_t read (int fd, void* buf, size_t nbytes)
__read:
    xor     rax, rax
    syscall
    ret

