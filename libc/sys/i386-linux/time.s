use32
global __time

; time_t time (time_t* timer);
__time:
    mov     eax, 13
    mov     ebx, [esp+4]
    int     80h
    ret

