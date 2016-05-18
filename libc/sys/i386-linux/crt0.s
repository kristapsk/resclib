use32
extern __libc_init 
global _start, _Exit

_start:
    mov     ebp, esp
    push    dword [ebp]         ; argc
    push    dword [ebp+4]       ; argv
    push    dword [ebp+8]       ; envp
    call    __libc_init
_Exit:
    mov     eax, 1              ; sys_exit
    mov     ebx, [esp+4]
    int     80h

