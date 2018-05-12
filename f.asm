section .rodata
const7 dd 8
const8 dd -10
const9 dd 13
const5 dd 5
const6 dd -14
const3 dd 2
const4 dd 6
const1 dd -2
const2 dd 14

section .text
global f1 ;ln(x)
f1:
push ebp
mov ebp, esp
fld1
fld qword[ebp+8]
fyl2x
fldl2e
fdivp
leave
ret

global f2 ; -2*x+14
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

global f3 ;1/(2-x)+6
f3:
push ebp
mov ebp, esp
fild dword[const3]
fld qword[ebp+8]
fsubp
fld1
fxch
fdivp
fild dword[const4]
faddp
leave
ret

global f4 ;5*x-14
f4:
push ebp
mov ebp, esp
fild dword[const5]
fld qword[ebp+8]
fmulp
fild dword[const6]
fadd
leave
ret

global f5 ;2*x*x-10*x+13
f5:
push ebp
mov ebp, esp
fild dword[const3]
fld qword[ebp+8]
fld qword[ebp+8]
fmulp
fmulp
fild dword[const8]
fld qword[ebp+8]
fmulp
faddp
fild dword[const9]
fadd
leave
ret

global f6 ;8*x*x*x+2*x*x-10*x-14
f6:
push ebp
mov ebp, esp
fild dword[const7]
fld qword[ebp+8]
fld qword[ebp+8]
fld qword[ebp+8]
fmulp
fmulp
fmulp
fild dword[const3]
fld qword[ebp+8]
fld qword[ebp+8]
fmulp
fmulp
faddp
fild dword[const8]
fld qword[ebp+8]
fmulp
faddp
fild dword[const6]
fadd
leave
ret
