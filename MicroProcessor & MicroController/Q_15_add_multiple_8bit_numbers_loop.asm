;<15. Develop an 8085 program to add multiple 8-bit numbers using loop.>
LXI H, 2050H
MVI C, 05H
MVI A, 00H
MVI B, 00H

LOOP: ADD M
      JNC NEXT
      INR B

NEXT: INX H
      DCR C
      JNZ LOOP

STA 2060H
MOV A, B
STA 2061H

HLT