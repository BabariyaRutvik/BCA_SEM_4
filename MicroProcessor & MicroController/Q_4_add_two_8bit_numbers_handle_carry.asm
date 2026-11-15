;<4. Develop an 8085 program to add two 8-bit numbers and handle carry.>

LDA 2050H
MOV B, A
LDA 2051H
ADD B
STA 2052H
MVI A, 00H
JNC NO_CARRY
INR A

NO_CARRY: STA 2053H
HLT
