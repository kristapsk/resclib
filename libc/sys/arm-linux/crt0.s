.extern __libc_init
.global _start, _Exit

@ http://stackoverflow.com/a/1803693/2704037
_start:
    sub     lr, lr, lr
    ldr     r0, [sp]            @ argc
    add     r1, sp, #4          @ argv
    add     r2, r1, r0, lsl #2  @ envp
    bl      __libc_init

_Exit:
    mov     %r7, $1
    swi     $0

