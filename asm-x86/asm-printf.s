section .data:
    message: db "something", 0xA, 0 ; const char message[] = "something\n\0"

section .text:
    global main
    extern printf

main:
    ; printf(message)
    mov rax, 0 ; __VA_ARGS__ magic
    push message
    call printf

    ; return 0
    mov rax, 0
    ret
