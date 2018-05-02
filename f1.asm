section .rodata
const1 dd -2
const2 dd 14
const3 dd 2
const4 dd 6

section .text
global f1
f1:
push rbp
mov rbp, rsp
mov xmm0, 0
mov rcx, 0
mov rax, 0
pop rbp
ret
