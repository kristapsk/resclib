.global __getpid

__getpid:
    mov     %r7, $20
    swi     $0
    bx      lr

