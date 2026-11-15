; <58. Write an 8085 program to implement an up counter (00H to 09H) with a delay between counts.>

MVI A, 00H

COUNT: STA 2050H

       ; Delay loop
       MVI C, FFH
DELAY: DCR C
       JNZ DELAY

       INR A
       CPI 0AH
       JNZ COUNT

HLT