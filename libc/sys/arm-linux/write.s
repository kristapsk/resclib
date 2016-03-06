.global __write

__write:
    mov     %r7, $4
    swi     $0
    bx      lr

