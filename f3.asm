section .rodata
const1 dd -2
const2 dd 14
const3 dd 2
const4 dd 6

section .text
global f3
f3:
push rbp
mov rbp, rsp
fild dword[const3]
fild dword[ebp+8]
fsubp
fld1
fxch
fdivp
fild dword[const4]
faddp
leave
ret




















