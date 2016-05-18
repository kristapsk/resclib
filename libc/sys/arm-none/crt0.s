.extern __libc_init
.global _start, _Exit

interrupt_vector_table:
    b .     @ Reset
    b .
    b .     @ SWI
    b .
    b .
    b .
    b .
    b .

.comm stack, 0x10000    @ Reserve 64k stack in the BSS
_start:
    ldr     sp, =stack+0x10000
    sub     r0, r0, r0  @ argc
    sub     r1, r1, r1  @ argv
    sub     r2, r2, r2  @ envp
    bl      __libc_init

_Exit:
    wfi
    b       _Exit

