section .rodata
const1 dd -2
const2 dd 14

section .text
global f2
f2:
push ebp
mov ebp, esp
fild dword[const1]
fld qword[ebp+8]
fmulp
fild dword[const2]
faddp
mov esp, ebp
pop ebp
ret
