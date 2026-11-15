; <51. Write an 8085 program to swap the upper and lower nibbles of an 8-bit number using rotate instructions.>

LDA 2050H
RLC
RLC
RLC
RLC
STA 2051H
HLT