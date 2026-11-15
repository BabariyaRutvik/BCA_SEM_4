; <40. Write an 8085 program to find both minimum and maximum from given data set.>

LXI H, 2050H
MOV A, M
MOV B, A
MOV D, A
MVI C, 04H

LOOP: INX H
      MOV A, M
      CMP B
      JNC CHK_MAX
      MOV B, A
      JMP NEXT

CHK_MAX: CMP D
         JC NEXT
         MOV D, A

NEXT: DCR C
      JNZ LOOP

MOV A, B
STA 2060H
MOV A, D
STA 2061H
HLT