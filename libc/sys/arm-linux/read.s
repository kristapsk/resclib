.global __read

__read:
    mov     %r7, $3
    swi     $0
    bx      lr

