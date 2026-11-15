; <39. Write an 8085 program to copy data block and then add all elements.>

LXI H, 2050H
LXI D, 2060H
MVI C, 05H

COPY: MOV A, M
      STAX D
      INX H
      INX D
      DCR C
      JNZ COPY

LXI H, 2060H
MVI C, 05H
MVI A, 00H
MVI B, 00H

ADDLOOP: ADD M
         JNC NEXT
         INR B

NEXT: INX H
      DCR C
      JNZ ADDLOOP

STA 2070H
MOV A, B
STA 2071H
HLT