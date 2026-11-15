; <59. Write an 8085 program to reverse a block of data using the stack (PUSH and POP).>

LXI SP, 2200H
LXI H, 2050H
MVI C, 05H

PUSH_LOOP: MOV A, M
           PUSH PSW
           INX H
           DCR C
           JNZ PUSH_LOOP

LXI H, 2050H
MVI C, 05H

POP_LOOP: POP PSW
          MOV M, A
          INX H
          DCR C
          JNZ POP_LOOP

HLT