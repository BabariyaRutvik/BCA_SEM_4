; <11. Develop an 8085 program to sort a block of 8-bit data.>
MVI B, 04H

OUTER: LXI H, 2050H
       MOV C, B

INNER: MOV A, M
       INX H
       CMP M
       JC NOSWAP
       JZ NOSWAP

       MOV D, M
       MOV M, A
       DCX H
       MOV M, D
       INX H

NOSWAP: DCR C
        JNZ INNER

        DCR B
        JNZ OUTER

HLT