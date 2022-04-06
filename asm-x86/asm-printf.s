section .data:
    message: db "something", 0xA, 0 ; const char message[] = "something\n\0"

section .text:
    global main
    extern printf

main:
    push rbp
    mov rbp, rsp

    ; printf(message)
    lea rax, [message]
    mov rdi, rax
    mov rax, 0 ; __VA_ARGS__ magic
    call printf

    ; return 0
    mov rax, 0
    leave
    ret
