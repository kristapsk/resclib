.extern main
.global _start, _Exit

@ http://stackoverflow.com/a/1803693/2704037
_start:
    sub     lr, lr, lr
    ldr     r0, [sp]
    add     r1, sp, #4
    bl      main

_Exit:
    mov     %r7, $1
    swi     $0

