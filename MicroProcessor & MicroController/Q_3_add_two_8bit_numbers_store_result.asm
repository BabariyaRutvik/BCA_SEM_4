;<3. Write an 8085 program to add two 8-bit numbers and store result in memory.>

LDA 2050H
MOV B, A
LDA 2051H
ADD B
STA 2052H
HLT
