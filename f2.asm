section .rodata
const1 dd -2
const2 dd 14
const3 dd 2
const4 dd 6

section .text
global f2
f2:
push rbp
mov rbp, rsp
fild dword[const1]
fld qword[rbp+16]
fmulp
fild dword[const2]
faddp
mov rsp, rbp
pop rbp
ret
