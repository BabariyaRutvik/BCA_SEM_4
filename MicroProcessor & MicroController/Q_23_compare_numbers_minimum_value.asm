; <23. Develop an 8085 program to compare numbers and identify minimum value.>

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
