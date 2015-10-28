use64
global puts
extern __strlen

; syscall args: x86_64        rdi   rsi   rdx   r10   r8    r9    -

; int puts (const char* str)
puts:
    push    rdi
    call    __strlen
    mov     rdx, rax            ; arg 3 - buffer size
    mov     rdx, 14
    pop     rsi                 ; arg 2 - buffer (str)
    mov     eax, 1              ; sys_write
    mov     edi, 1              ; stdout
    syscall
    mov     eax, 1
;    lea     rsi, [linefeed]
    mov     rsi, linefeed
    mov     edx, 1
    mov     edi, 1
    syscall
    ret

linefeed    db 0Ah
