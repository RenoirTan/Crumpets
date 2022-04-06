%include "utils.inc"

section .data
    message: db "things", 0xA, 0x0

section .text
    global _start

_start:
    mov rax, message
    call sprint ; sprint(rax)
    call exit_ok ; exit_ok()
