; <21. Write an 8085 program to find the minimum number from 5 8-bit numbers.>

LXI H,2050H
MOV B,M
INX H
MVI C,04H

LOOP: MOV A,M
      CMP B
      JNC NEXT
      MOV B,A

NEXT: INX H
      DCR C
      JNZ LOOP

MOV A,B
STA 2060H
HLT
