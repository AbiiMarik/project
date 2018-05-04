section .rodata
const1 dd 2
const2 dd -10
const3 dd 13

section .text
global f5
f5:
push ebp
mov ebp, esp
fild dword[const1]
fld qword[ebp+8]
fld qword[ebp+8]
fmulp
fmulp
fild dword[const2]
fld qword[ebp+8]
fmulp
faddp
fild dword[const3]
fadd
leave
ret
