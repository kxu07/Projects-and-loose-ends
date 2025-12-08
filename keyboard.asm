.orig x3000

AND R0, R0, #0
AND R1, R1, #0
AND R4, R4, #0
AND R5, R5, #0
AND R6, R6, #0
STI R0, FGCR ; mem[x440a] = R0 = 0
    ; set FGCR = 0 to stop playing note
BR WAIT_FOR_KEY

WAIT_FOR_KEY
  LDI R0, KPDR ; R0 = ascii(typed_key),
  BRz WAIT_FOR_KEY ; if zero, no key yet. loop back

;; write the frequency to the frequency generator FGDR
LEA R4, NOTE_FREQ_ARR
ADD R0, R0, #-1
ADD R4, R4, R0
ADD R4, R4, #-16
ADD R4, R4, #-16
ADD R4, R4, #-16
LDR R5, R4, #0
STI R5, FGDR

;; store non-zero number to FGCR to play sound
AND R6, R6, #0
ADD R6, R6, #3
STI R6, FGCR

WAIT_FOR_RELEASE
  LDI R0, KPSR
  ADD R0, R0, #0
  BRnp WAIT_FOR_RELEASE ; if zero, key has been released stop 

AND R6, R6, #0
STI R6, FGCR


BR WAIT_FOR_KEY

HALT

FGCR
  .FILL x440A
KPDR
  .FILL x4400
KPSR
  .FILL x4402
FGDR
  .FILL x4408

;; 9 frequences for 9 key_in numbers
NOTE_FREQ_ARR
  .FILL x01B8 ;; 1 A LA 6
  .FILL x01D2 ;; 2 A# LI RAISED 6
  .FILL x01ED ;; 3 B SI 7
  .FILL x020B ;; 4 C DO 1
  .FILL x022A ;; 5 C# DI RAISED 1
  .FILL x024B ;; 6 D RE 2
  .FILL x026E ;; 7 D# RI RAISED 2
  .FILL x02BA ;; 8 F FA 4
  .FILL x030F ;; 9 G SOL 5
;;

.END
