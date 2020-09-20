
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

; add your code here

mov ax, 30
mov bx, 10
mov cx, 20

cmp ax, bx

JGE AX_COMP
    mov dx, bx
    JMP SECOND_CMP
    
AX_COMP:
    mov dx, ax
    
SECOND_CMP:
cmp dx, cx
JGE DX_COMP
    mov dx,cx
    
DX_COMP:


ret







