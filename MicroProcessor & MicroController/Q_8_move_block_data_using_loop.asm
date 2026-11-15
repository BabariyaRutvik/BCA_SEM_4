;<8. Write an 8085 program to move block of data using loop.>

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
