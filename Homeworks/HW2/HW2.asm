;Elnaz Rezaee 98411387

.include "m32def.inc"
LDI		R16, HIGH(RAMEND)
OUT		SPH, R16
LDI		R16, LOW(RAMEND)
OUT		SPL, R16

LDI		R16, 0xFF
OUT		DDRC, R16
OUT		DDRD, R16

OUT		PORTA, R16
LDI		R16, 0x00
OUT		DDRA, R16
OUT		DDRB, R16

BEGIN:
    IN		R16, PINA
    CPI 	R16, 0
    BREQ 	Increment
    LDI		R17, 0
    LDI		R18, 0
    LDI		R19, 0
    LDI     R20, 0
    RJMP	inc0

Increment:
    LDI		R17, 9
    LDI		R18, 9
    LDI		R19, 9
    LDI     R20, 9
    RJMP	dec0

Start:
    IN		R16, PINA
    CPI 	R16, 0
    BREQ 	dec0

inc0:
    CPI 	R17, 0x09
    BREQ 	inc1
    INC 	R17
    RJMP	DISPLAY

inc1:
    LDI 	R17, 0x00
    CPI 	R18, 0x09
    BREQ 	inc2
    INC 	R18
    RJMP	DISPLAY

inc2:
    LDI 	R18, 0x00
    CPI 	R19, 0x09
    BREQ 	inc3
    INC 	R19
    RJMP	DISPLAY

inc3:
    LDI 	R19, 0x00
    CPI 	R20, 0x09
    BREQ 	inc4
    INC 	R20

inc4:
    LDI 	R20, 0x00
    BREQ 	DISPLAY


dec0:
    CPI 	R17, 0x00
    BREQ 	dec1
    DEC		R17
    RJMP	DISPLAY


dec1:
    LDI 	R17, 0x09
    CPI 	R18, 0x00
    BREQ 	dec2
    DEC 	R18
    RJMP	DISPLAY

dec2:
    LDI 	R18, 0x09
    CPI 	R19, 0x00
    BREQ 	dec3
    DEC 	R19
    RJMP	DISPLAY

dec3:
    LDI 	R19, 0x09
    CPI 	R20, 0x00
    BREQ 	dec4
    DEC 	R19

dec4:
    LDI 	R20, 0x09
    RJMP 	DISPLAY


CONVERT:
    CPI		R16, 0
    BRNE	C1
    LDI		R16, 0x3F
    RET
C1:		
    CPI		R16, 1
    BRNE	C2
    LDI		R16, 0x06
    RET
C2:		
    CPI		R16, 2
    BRNE	C3
    LDI		R16, 0x5B
    RET
C3:		
    CPI		R16, 3
    BRNE	C4
    LDI		R16, 0x4F
    RET
C4:		
    CPI		R16, 4
    BRNE	C5
    LDI		R16, 0x66
    RET
C5:		
    CPI		R16, 5
    BRNE	C6
    LDI		R16, 0x6D
    RET
C6:		
    CPI		R16, 6
    BRNE	C7
    LDI		R16, 0x7D
    RET
C7:		
    CPI		R16, 7
    BRNE	C8
    LDI		R16, 0x07
    RET
C8:		
    CPI		R16, 8
    BRNE	C9
    LDI		R16, 0x7F
    RET
C9:		
    CPI		R16, 9
    BRNE	C10
    LDI		R16, 0x6F
C10:	
    RET




DISPLAY:
    LDI		R16, 0b11111110
    OUT		PORTD, R16
    MOV		R16, R20
    CALL	CONVERT
    OUT		PORTC, R16
    CALL	DELAY

    LDI		R16, 0b11111101
    OUT		PORTD, R16
    MOV		R16, R19
    CALL	CONVERT
    OUT		PORTC, R16
    CALL	DELAY

    LDI		R16, 0b11111011
    OUT		PORTD, R16
    MOV		R16, R18
    CALL	CONVERT
    OUT		PORTC, R16
    CALL	DELAY

    LDI		R16, 0b11110111
    OUT		PORTD, R16
    MOV		R16, R17
    CALL	CONVERT
    OUT		PORTC, R16
    CALL	DELAY
    RJMP	START
DELAY:	
    LDI		R21, 0x01
    L1:		LDI		R22, 0xFF
    L2:		LDI		R23, 0xFF
    L3:		DEC		R23
    BRNE	L3
    DEC		R22
    BRNE	L2
    DEC		R21
    BRNE	L1
    RET
