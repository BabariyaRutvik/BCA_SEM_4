;<7. Develop an 8085 program to transfer block data using register pair.>


LXI H, 2050H
LXI D, 2060H
MVI B, 05H

LOOP: MOV A, M
STAX D
INX H
INX D
DCR B
JNZ LOOP
HLT
