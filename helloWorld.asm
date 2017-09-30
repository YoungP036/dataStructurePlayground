;required sectoin->.text=code
;optional->.data=read write data
;optional->.bss= uninitialized read write data
;system calls through 0x80
;pass fastcall pass func num via eax, params in ebx ecx edx esi edi
;   dont touch stack

section     .text
global      _start;linker needs this declare

_start:

    mov     edx,len;msg len
    mov     ecx,msg;msg to write
    mov     ebx,1;stdout
    mov     eax,4;opcode for sys_write
    int     0x80;call kernal

    mov     eax,1;opcode sys_exit
    int     0x80

section .data

msg     db 'Hello, world!',0xa;msg
len     equ $ - msg; str length, equal to msg