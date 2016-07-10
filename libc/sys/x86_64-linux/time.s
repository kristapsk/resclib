use64
global __time

; time_t time (time_t* timer);
__time:
    mov     eax, 201
    syscall
    ret

