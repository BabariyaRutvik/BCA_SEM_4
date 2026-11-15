; <36. Write an 8085 program to divide two numbers and store quotient in register.>

LDA 2050H
MOV B, A
LDA 2051H
MOV C, A

MVI D, 00H
MOV A, B

LOOP: CMP C
      JC END
      SUB C
      INR D
      JMP LOOP

END: HLT