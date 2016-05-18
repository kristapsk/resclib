use64
extern __libc_init
global _start, _Exit

_start:
    call    __libc_init
    mov     rdi, rax
    ; passthrough
_Exit:
    mov     eax, 60
    syscall

