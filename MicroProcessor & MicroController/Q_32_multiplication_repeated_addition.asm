; <32. Write an 8085 program to perform multiplication using repeated addition method.>

LDA 2050H
MOV B, A
LDA 2051H
MOV C, A

MVI A, 00H
MVI D, 00H

LOOP: ADD B
      JNC NEXT
      INR D

NEXT: DCR C
      JNZ LOOP

STA 2052H
MOV A, D
STA 2053H
HLT