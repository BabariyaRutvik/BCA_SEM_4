; <43. Write an 8085 program to convert a given binary number into its equivalent ASCII code.>

LDA 2050H
CPI 0AH
JC DIGIT
ADI 07H

DIGIT: ADI 30H
       STA 2051H
       HLT