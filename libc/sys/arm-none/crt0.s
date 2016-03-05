.extern main
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
    bl      main

_Exit:
    wfi
    b       _Exit

