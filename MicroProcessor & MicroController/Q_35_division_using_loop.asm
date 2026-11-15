; <35. Write an 8085 program to perform division using loop.>

LDA 2050H
MOV B, A
LDA 2051H
MOV C, A

MVI D, 00H
MOV A, B

LOOP: CMP C
      JC STORE
      SUB C
      INR D
      JMP LOOP

STORE: STA 2053H
       MOV A, D
       STA 2052H
       HLT