section .text
   global _start

_start:
   mov ecx, 200
   cmp ecx, 100
   jg exit_program
   jmp exit_program

exit_program:
   mov eax, 1
   mov ebx, 0
   int 0x80
