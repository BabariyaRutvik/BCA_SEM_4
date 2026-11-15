; <42. Write an 8085 program to convert a binary number to its BCD equivalent.>

LDA 2050H
MVI B, 00H

LOOP: CPI 0AH
      JC DONE
      SUI 0AH
      INR B
      JMP LOOP

DONE: MOV C, A
      MOV A, B
      RLC
      RLC
      RLC
      RLC
      ADD C
      STA 2051H
      HLT