%include "utils.inc"

section .text

strlen:
    ; size_t strlen(char *rax)
    ; the return value is stored in rax

    ; push the value of rbx onto the stack because we are going to use this
    ; register for some special calculations,
    ; so its value must be preserved on the stack
    ; because x86_64 only allows pushing/popping 64-bit registers,
    ; i have to use rbx instead of rbx
    push rbx
    mov rbx, rax ; char *rbx = rax

__strlen_iter:
    cmp byte [rax], 0 ; if (*rax == 0)
    jz __strlen_res ; goto __strlen_res
    ; else
    inc rax ; ++rax
    jmp __strlen_iter ; continue

__strlen_res:
    sub rax, rbx ; rax -= rbx
    pop rbx ; pop the original value of rbx from the stack into rbx
    ret ; give control back to the caller

exit_ok:
    ; void exit_ok(void)

    push rax
    push rbx
    mov rax, 1
    mov rbx, 0
    int 0x80
    pop rbx
    pop rax
