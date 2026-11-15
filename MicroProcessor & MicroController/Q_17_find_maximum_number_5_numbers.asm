; <17. Write an 8085 program to find the maximum number from 5 8-bit numbers.>

; Q17. Find maximum number from 5 numbers

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
      