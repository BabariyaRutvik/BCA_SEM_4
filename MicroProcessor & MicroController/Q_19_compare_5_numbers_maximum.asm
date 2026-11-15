; <19. Develop an 8085 program to compare 5 numbers and display maximum.>



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
      