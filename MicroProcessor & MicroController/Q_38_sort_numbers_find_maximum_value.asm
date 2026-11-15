; <38. Write an 8085 program to sort numbers and then find maximum value.>

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

LDA 2054H
STA 2060H
HLT