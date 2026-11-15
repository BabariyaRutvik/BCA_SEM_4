; <41. Write an 8085 program to convert a BCD number to its binary equivalent.>

LDA 2050H
MOV B, A

; Extract Lower nibble (Units digit)
ANI 0FH
MOV C, A

; Extract Upper nibble (Tens digit)
MOV A, B
ANI F0H
RRC
RRC
RRC
RRC
MOV D, A

; Multiply Tens digit by 10 (0AH) using addition
MVI E, 0AH
MVI A, 00H

MULT: ADD D
      DCR E
      JNZ MULT

; Add Units digit
ADD C

STA 2051H
HLT