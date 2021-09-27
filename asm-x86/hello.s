section .data
   message: db "hello world", 0xa ; 0xa is newline
   length: equ $-message

section .text
   global _start

_start:

   ; portion to print to stdout

   mov ecx, message
   mov edx, length
   mov ebx, 1 ; stdout file
   mov eax, 4 ; system call (sys_write)
   int 0x80; call kernel to perform sys_write

   ; portion to exit program

   mov ebx, 0 ; exit code
   mov eax, 1 ; system call (sys_exit)
   int 0x80 ; call kernel to perform (sys_exit)
