section .rodata
const1 dd 2
const2 dd 6

section .text
global f3
f3:
push ebp
mov ebp, esp
fild dword[const1]
fld qword[ebp+8]
fsubp
fld1
fxch
fdivp
fild dword[const2]
faddp
leave
ret



















