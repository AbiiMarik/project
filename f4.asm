section .rodata
const1 dd 5
const2 dd -14

section .text
global f4
f4:
push ebp
mov ebp, esp
fild dword[const1]
fld qword[ebp+8]
fmulp
fild dword[const2]
fadd
leave
ret
