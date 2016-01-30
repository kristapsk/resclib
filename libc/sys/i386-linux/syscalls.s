use32

global __putchar
global __puts
global __read
global __write

extern __strlen

%define EOF -1

; syscall args: i386          ebx   ecx   edx   esi   edi   ebp

; int putchar (int character)
__putchar:
    push    ebx
    mov     eax, 4
    lea     ecx, [esp+8]
    mov     ebx, 1
    mov     edx, ebx
    int     80h
    cmp     eax, EOF
    je      .err
    mov     eax, [esp+8]
.err:
    pop     ebx
    ret

; int puts (const char* str)
__puts:
    push    ebx
    push    dword [esp+8]
    call    __strlen
    pop     ecx
    mov     edx, eax            ; buffer size
    mov     eax, 4              ; sys_write
    mov     ebx, 1              ; stdout
    mov     ecx, [esp+8]        ; buffer (str)
    int     80h
    cmp     eax, EOF
    je      .ret
    push    0Ah
    call    __putchar
    pop     ebx
.ret:
    pop     ebx
    ret

; ssize_t read (int fd, void* buf, size_t nbytes);
__read:
    mov     eax, 3
    mov     ebx, [esp+4]
    mov     ecx, [esp+8]
    mov     edx, [esp+12]
    int     80h
    ret

; ssize_t write (int fd, const void* buf, size_t nbytes);
__write:
    mov     eax, 4
    mov     ebx, [esp+4]
    mov     ecx, [esp+8]
    mov     edx, [esp+12]
    int     80h
    ret

