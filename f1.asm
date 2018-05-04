section .text
global f1
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
