; <49. Write an 8085 program to check whether an 8-bit number is even or odd using logic instructions.>

LDA 2050H
ANI 01H
JZ EVEN
MVI A, 01H
JMP STORE

EVEN: MVI A, 00H

STORE: STA 2051H
       HLT