use32
global __write

; ssize_t write (int fd, const void* buf, size_t nbytes);
__write:
    mov     eax, 4
    mov     ebx, [esp+4]
    mov     ecx, [esp+8]
    mov     edx, [esp+12]
    int     80h
    ret

