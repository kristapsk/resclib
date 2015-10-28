use64
extern main 
global _start, _Exit

_start:
    call    main
    mov     rdi, rax
    ; passthrough
_Exit:
    mov     eax, 60
    syscall

