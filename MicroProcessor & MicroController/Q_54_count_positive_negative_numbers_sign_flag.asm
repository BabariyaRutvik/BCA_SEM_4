; <54. Write an 8085 program to count the number of positive and negative numbers in a data block using the sign flag.>

LXI H, 2050H
MVI C, 05H
MVI D, 00H
MVI E, 00H

LOOP: MOV A, M
      ORA A
      JM NEGATIVE
      INR D
      JMP NEXT

NEGATIVE: INR E

NEXT: INX H
      DCR C
      JNZ LOOP

MOV A, D
STA 2060H
MOV A, E
STA 2061H
HLT