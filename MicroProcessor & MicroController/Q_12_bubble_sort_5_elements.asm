; <12. Write an 8085 program to perform Bubble Sort for 5 elements.>
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