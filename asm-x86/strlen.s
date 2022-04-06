section .data
    string: db "a string of unknown length", 0xa

section .text
    global _start

_start:
    mov ebx, string ; char *ebx = string
    mov eax, ebx ; char *eax = ebx

__strlen_iter:
    cmp byte [eax], 0 ; if (*eax == 0)
    jz __strlen_res ; goto __strlen_res
    ; else
    inc eax ; ++eax
    jmp __strlen_iter ; continue

__strlen_res:
    sub eax, ebx ; eax - ebx

    ; rest of _start
    mov edx, eax ; eax stores the length of the string
    mov ecx, string
    mov ebx, 1
    mov eax, 4
    int 0x80
    
    mov ebx, 0
    mov eax, 1
    int 0x80