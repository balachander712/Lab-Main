
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

; add your code here 

MOV [1100H],0001H
MOV SI,1100H
MOV BX,[BX+SI]
MOV CX,BX
MOV [1300H],CX

ret



