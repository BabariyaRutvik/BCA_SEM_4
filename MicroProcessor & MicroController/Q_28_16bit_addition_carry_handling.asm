; <28. Write an 8085 program to perform 16-bit addition with carry handling.>

LHLD 2050H
XCHG
LHLD 2052H
DAD D
SHLD 2054H

MVI A,00H
JNC NO_CARRY
INR A

NO_CARRY: STA 2056H
HLT
