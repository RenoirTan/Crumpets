%include "utils.inc"

section .data
    string: db "a string of unknown length", 0xa

section .text
    global _start

_start:
    mov eax, string ; char *eax = string
    call strlen ; eax = strlen(eax)

    ; rest of _start
    mov edx, eax ; eax stores the length of the string
    mov ecx, string
    mov ebx, 1
    mov eax, 4
    int 0x80
    
    mov ebx, 0
    mov eax, 1
    int 0x80
