; <47. Write an 8085 program to subtract two 8-bit numbers and check the borrow (carry) flag.>

LDA 2050H
MOV B, A
LDA 2051H
MOV C, A

MOV A, B
SUB C
STA 2052H

MVI A, 00H
JNC NO_BORROW
INR A

NO_BORROW: STA 2053H
           HLT