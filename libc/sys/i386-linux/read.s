use32
global __read

; ssize_t read (int fd, void* buf, size_t nbytes);
__read:
    mov     eax, 3
    mov     ebx, [esp+4]
    mov     ecx, [esp+8]
    mov     edx, [esp+12]
    int     80h
    ret

