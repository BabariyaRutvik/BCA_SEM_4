; <57. Write an 8085 program to generate a time delay using a register loop and calculate the delay in T-states.>

; Calculation of T-states:
; MVI C, FFH  -> 7 T-states (executed 1 time)
; LOOP: DCR C -> 4 T-states (executed 255 times)
; JNZ LOOP    -> 10 T-states (executed 254 times when jump taken)
;             -> 7 T-states (executed 1 time when jump not taken)
; Total Delay in T-states = 7 + (255 * 4) + (254 * 10) + 7 = 3574 T-states

      MVI C, FFH

LOOP: DCR C
      JNZ LOOP

      HLT