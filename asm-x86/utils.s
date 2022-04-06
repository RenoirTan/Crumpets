%include "utils.inc"

section .text

strlen:
    ; size_t strlen(char *eax)
    ; the return value is stored in eax

    ; push the value of ebx onto the stack because we are going to use this
    ; register for some special calculations,
    ; so its value must be preserved on the stack
    ; because x86_64 only allows pushing/popping 64-bit registers,
    ; i have to use rbx instead of ebx
    push rbx
    mov ebx, eax ; char *ebx = eax

__strlen_iter:
    cmp byte [eax], 0 ; if (*eax == 0)
    jz __strlen_res ; goto __strlen_res
    ; else
    inc eax ; ++eax
    jmp __strlen_iter ; continue

__strlen_res:
    sub eax, ebx ; eax -= ebx
    pop rbx ; pop the original value of ebx from the stack into ebx
    ret ; give control back to the caller

exit_ok:
    ; void exit_ok(void)

    push rax
    push rbx
    mov eax, 1
    mov ebx, 0
    int 0x80
    pop rbx
    pop rax
