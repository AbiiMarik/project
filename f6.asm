section .rodata
const1 dd 8
const2 dd 2
const3 dd -10
const4 dd -14

section .text
global f6
f6:
push ebp
mov ebp, esp
fild dword[const1]
fld qword[ebp+8]
fld qword[ebp+8]
fld qword[ebp+8]
fmulp
fmulp
fmulp
fild dword[const2]
fld qword[ebp+8]
fld qword[ebp+8]
fmulp
fmulp
faddp
fild dword[const3]
fld qword[ebp+8]
fmulp
faddp
fild dword[const4]
fadd
leave
ret
