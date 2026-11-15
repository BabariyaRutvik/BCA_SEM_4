; <52. Write an 8085 program to perform AND, OR and XOR operations on two 8-bit numbers.>

LDA 2050H
MOV B, A
LDA 2051H
MOV C, A

; AND operation
MOV A, B
ANA C
STA 2052H

; OR operation
MOV A, B
ORA C
STA 2053H

; XOR operation
MOV A, B
XRA C
STA 2054H

HLT