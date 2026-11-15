; <50. Write an 8085 program to count the number of 1s in an 8-bit number using rotate instructions.>

LDA 2050H
MVI C, 08H
MVI B, 00H

LOOP: RLC
      JNC NEXT
      INR B

NEXT: DCR C
      JNZ LOOP

MOV A, B
STA 2051H
HLT