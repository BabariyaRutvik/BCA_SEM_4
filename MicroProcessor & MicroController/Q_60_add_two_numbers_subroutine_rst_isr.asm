; <60. Write an 8085 program to add two numbers using a subroutine (CALL and RET), and demonstrate the use of an RST instruction and a simple interrupt service routine.>

; Main Program
LXI SP, 2200H

LDA 2050H
MOV B, A
LDA 2051H
MOV C, A

CALL ADDSUB
STA 2052H

RST 1
HLT

; Subroutine for addition
ADDSUB: MOV A, B
        ADD C
        RET

; Interrupt Service Routine (ISR) for RST 1 (Vector Address: 0008H)
ORG 0008H
ISR_RST1: MVI A, FFH
          STA 2053H
          EI
          RET