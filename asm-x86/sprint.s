%include "utils.inc"

section .data
    message: db "things", 0xA, 0x0

section .text
    global _start

_start:
    mov rax, message
    call sprint
    call exit_ok
