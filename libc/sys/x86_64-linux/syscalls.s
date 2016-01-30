use64

global __putchar
global __puts
global __read
global __write

extern __strlen

%define EOF -1

; syscall args: x86_64        rdi   rsi   rdx   r10   r8    r9    -

; int puts (const char* str)
__puts:
    push    rdi
    call    __strlen
    mov     rdx, rax            ; arg 3 - buffer size
    pop     rsi                 ; arg 2 - buffer (str)
    mov     eax, 1              ; sys_write
    mov     edi, 1              ; stdout
    syscall
    cmp     rax, EOF
    je      __putchar.err
    mov     edi, 0Ah
    ; fall through to putchar()

; int putchar (int character)
__putchar:
    mov     eax, 1
    mov     [rsp-8], rdi
    lea     rsi, [rsp-8]
    mov     rdx, rax
    mov     rdi, rdx
    syscall
    cmp     rax, EOF
    je      .err
    mov     rax, [rsp-8]
.err:
    ret

; ssize_t read (int fd, void* buf, size_t nbytes)
__read:
    xor     rax, rax
    syscall
    ret

; ssize_t write (int fd, const void* buf, size_t nbytes)
__write:
    mov     eax, 1
    syscall
    ret

