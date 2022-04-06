%include "utils.inc"

section .text

strlen:
    ; size_t strlen(char *rax)
    ; the return value is stored in rax

    push rbp
    mov rbp, rsp

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
    mov rsp, rbp
    pop rbp
    ret ; give control back to the caller

sprint:
    ; void sprint(char *rax)

    ; remember original stack pointer
    push rbp
    mov rbp, rsp

    ; push the values of these 4 registers to the stack since we're going to be
    ; using them
    push rax ; char *temp_rax = rax
    push rbx ; char *temp_rbx = rbx
    push rcx ; char *temp_rcx = rcx
    push rdx ; char *temp_rdx = rdx

    mov rcx, rax ; rcx = rax
    call strlen ; rax = strlen(rax)
    mov rdx, rax ; rdx = rax
    mov rbx, 1 ; rbx = 1
    mov rax, 4 ; rax = 4
    int 0x80 ; syscall(rax, rbx, rcx, rdx) --> write(rbx, rcx, rdx)
    
    ; reset 4 registers back to their original values
    pop rdx
    pop rcx
    pop rbx
    pop rax

    ; reset stack pointer to original location
    mov rsp, rbp
    pop rbp
    ret

exit_ok:
    ; void exit_ok(void)

    push rax
    push rbx
    mov rax, 1
    mov rbx, 0
    int 0x80
    pop rbx
    pop rax
