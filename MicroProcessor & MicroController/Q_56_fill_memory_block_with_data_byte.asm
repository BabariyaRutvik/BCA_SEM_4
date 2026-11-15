; <56. Write an 8085 program to fill a block of memory with a given data byte using a counter.>

LDA 2040H
MOV B, A
LXI H, 2050H
MVI C, 05H

LOOP: MOV M, B
      INX H
      DCR C
      JNZ LOOP

HLT