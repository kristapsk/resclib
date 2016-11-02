use64
global __getpid

; pid_t getpid (void);
__getpid:
    mov     eax, 39
    syscall
    ret

