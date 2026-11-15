; <46. Write an 8085 program to convert an 8-bit binary number to Gray code.>

LDA 2050H
MOV B, A
ORA A
RRC
ANI 7FH
XRA B
STA 2051H
HLT