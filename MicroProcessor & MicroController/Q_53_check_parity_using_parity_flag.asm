; <53. Write an 8085 program to check the parity of an 8-bit number using the parity flag.>

LDA 2050H
ORA A
JPE EVEN
MVI A, 01H
JMP STORE

EVEN: MVI A, 00H

STORE: STA 2051H
       HLT