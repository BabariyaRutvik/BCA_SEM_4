;<6. Write an 8085 program to copy 5 bytes of data from source to destination memory.>

LXI H, 2050H
LXI D, 2060H
MVI C, 05H

LOOP: MOV A, M
STAX D
INX H
INX D
DCR C
JNZ LOOP

HLT
