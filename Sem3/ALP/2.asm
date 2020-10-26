
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

; add your code here 

MOV [0309],0020H
MOV AX,[0309]
NEG AX
SUB AX,1


ret




