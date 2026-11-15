; <10. Write an 8085 program to sort numbers in descending order using bubble sort.>

MVI B, 04H

OUTER: LXI H, 2050H
       MOV C, B

INNER: MOV A, M
       INX H
       CMP M
       JNC NOSWAP

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