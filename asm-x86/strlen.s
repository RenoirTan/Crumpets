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


strlen:
    ; size_t strlen(char *eax)
    ; the return value is stored in eax

    ; push the value of ebx onto the stack because we are going to use this
    ; register for some special calculations,
    ; so its value must be preserved on the stack
    push ebx
    mov ebx, eax ; char *ebx = eax

__strlen_iter:
    cmp byte [eax], 0 ; if (*eax == 0)
    jz __strlen_res ; goto __strlen_res
    ; else
    inc eax ; ++eax
    jmp __strlen_iter ; continue

__strlen_res:
    sub eax, ebx ; eax -= ebx
    pop ebx ; pop the original value of ebx from the stack into ebx
    ret ; give control back to the caller
