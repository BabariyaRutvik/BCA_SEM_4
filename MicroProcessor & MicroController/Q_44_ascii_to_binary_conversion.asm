; <44. Write an 8085 program to convert a given ASCII code into its equivalent binary number.>

LDA 2050H
SUI 30H
CPI 0AH
JC DONE
SUI 07H

DONE: STA 2051H
      HLT