.global __time

__time:
    mov     %r7, $13
    swi     $0
    bx      lr

