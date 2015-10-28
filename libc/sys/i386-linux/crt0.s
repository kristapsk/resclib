use32
extern main 
global _start, _Exit

_start:
    mov     ebp, esp
    push    dword [ebp]
    push    dword [ebp+4]
    call    main
_Exit:
    mov     eax, 1              ; sys_exit
    mov     ebx, [esp+4]
    int     80h

