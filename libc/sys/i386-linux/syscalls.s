use32
global puts
extern __strlen

; syscall args: i386          ebx   ecx   edx   esi   edi   ebp
; syscall args: x86_64        rdi   rsi   rdx   r10   r8    r9    -

; int puts (const char* str)
puts:
    push    ebp
    mov     ebp, esp
    push    ebx
    push    dword [ebp+8]
    call    __strlen
    add     esp, 4
    mov     edx, eax            ; buffer size
    mov     eax, 4              ; sys_write
    mov     ebx, 1              ; stdout
    mov     ecx, [ebp+8]        ; buffer (str)
    int     80h
    mov     eax, 4
    mov     ecx, linefeed
    mov     ebx, 1
    mov     edx, ebx
    int     80h
    pop     ebx
    pop     ebp
    ret

linefeed    db 0Ah
