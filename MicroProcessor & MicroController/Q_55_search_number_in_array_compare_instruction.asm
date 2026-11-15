; <55. Write an 8085 program to search for a given number in a data array using the compare instruction and indexing.>

LDA 2060H
MOV B, A
LXI H, 2050H
MVI C, 05H

LOOP: MOV A, M
      CMP B
      JZ FOUND
      INX H
      DCR C
      JNZ LOOP

MVI A, 00H
STA 2061H
JMP END

FOUND: MVI A, 01H
       STA 2061H

END: HLT