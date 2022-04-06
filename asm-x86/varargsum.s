section .data
    message: db "sum(3, 1, 2, 3) = %ld", 0xA, 0x0

section .text
    global main
    global sum
    extern printf

sum:
    ; int64_t sum(size_t rax, ...) -> rax
    ; the numbers that are going to be summed up
    ; are stored in the stack
    push rbp
    mov rbp, rsp

    push rcx ; sacrifice rcx to keep count of numbers
    mov rcx, rax ; rax will be used for the final sum
    mov rax, 0 ; reset rax to 0

sum__loop__:
    ; while (rcx != 0)
    cmp rcx, 0
    je sum__fin__

    ; rbp is a reference point
    ; each number is 8 bytes (hence, 8*rcx)
    ; +8 is to jump past `push rbp`
    add rax, [rbp+8*rcx+8] ; rax += *(rbp + 8*rcx + 8)
    dec rcx ; --rcx
    jmp sum__loop__

sum__fin__:
    pop rcx
    mov rsp, rbp
    pop rbp
    ret

main:
    push rbp
    mov rbp, rsp
    push rax
    push rdi
    push rsi

    ; sum(3, 1, 2, 3)
    mov rax, 3
    push QWORD 1
    push QWORD 2
    push QWORD 3
    call sum
    
    add rsp, 3*8

    mov rdi, message
    mov rsi, rax
    mov rax, 0x0
    call printf

    ; pop everything off the stack
    pop rsi
    pop rdi
    pop rax
    
    ; exit
    mov rsp, rbp
    pop rbp
    mov rax, 0
    ret