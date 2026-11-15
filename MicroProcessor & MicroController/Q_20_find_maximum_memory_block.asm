; <20. Write an 8085 program to find maximum value in memory block.>
;

LXI H,2050H
MOV B,M
INX H
MVI C,04H

LOOP: MOV A,M
      CMP B
      JC NEXT
      MOV B,A

NEXT: INX H
      DCR C
      JNZ LOOP

MOV A,B
STA 2060H
HLT

      