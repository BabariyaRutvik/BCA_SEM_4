; <45. Write an 8085 program to split a packed BCD number into two unpacked BCD digits.>

LDA 2050H
MOV B, A

; Unpack lower BCD digit
ANI 0FH
STA 2051H

; Unpack upper BCD digit
MOV A, B
ANI F0H
RRC
RRC
RRC
RRC
STA 2052H

HLT