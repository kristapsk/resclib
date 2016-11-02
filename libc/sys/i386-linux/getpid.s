use32
global __getpid

; pid_t getpid (void);
__getpid:
    mov     eax, 20
    int     80h
    ret

