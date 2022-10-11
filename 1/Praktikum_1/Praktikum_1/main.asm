;
; test.asm
;
; Created: 26.08.2020 11:41:51
; Author : ie4938e
;


.org 0x000		; Reset Vector
	rjmp start
;Rest der Tabelle bleibt ungenutzt

start:
; Stack Pointer initialisieren
	ldi r16, LOW( RAMEND )
	out SPL, r16
	ldi r16, HIGH( RAMEND )
	out SPH, r16

	;PB5 als Output
	ldi r16,0b11111111
	out DDRD, r16
	ldi r16, 0b00000011
	out DDRB, r16

	rjmp main
	
main:
	ldi r16, 0b00000001
	out PORTD, r16
	rcall delay		;kleine Pause (unterprogramm)

	ldi r16, 0b00000010
	out PORTD, r16
	rcall delay

	ldi r16, 0b00000100
	out PORTD, r16
	rcall delay	
	
	ldi r16, 0b00001000
	out PORTD, r16
	rcall delay	
	
	ldi r16, 0b00010000
	out PORTD, r16
	rcall delay	
	
	ldi r16, 0b00100000
	out PORTD, r16
	rcall delay
	
	ldi r16, 0b01000000
	out PORTD, r16
	rcall delay	

	ldi r16, 0b10000000
	out PORTD, r16
	rcall delay	
	
	ldi r16, 0b00000000
	out PORTD, r16
	ldi r16, 0b00000001
	out PORTB, r16
	rcall delay	
	
	ldi r16, 0b00000010
	out PORTB, r16
	rcall delay

	ldi r16, 0b00000001
	out PORTB, r16
	rcall delay	

	ldi r16, 0b00000000
	out PORTB, r16
	ldi r16, 0b10000000
	out PORTD, r16
	rcall delay

	ldi r16, 0b01000000
	out PORTD, r16
	rcall delay	

	ldi r16, 0b00100000
	out PORTD, r16
	rcall delay	

	ldi r16, 0b00010000
	out PORTD, r16
	rcall delay	

	ldi r16, 0b00001000
	out PORTD, r16
	rcall delay	

	ldi r16, 0b00000100
	out PORTD, r16
	rcall delay	

	ldi r16, 0b00000010
	out PORTD, r16
	rcall delay	

	ldi r16, 0b000000001
	out PORTD, r16

	rjmp main		;Ruecksprung

delay:
    ldi  r18, 17
    ldi  r19, 60
    ldi  r20, 204
L1: dec  r20
    brne L1
    dec  r19
    brne L1
    dec  r18
    brne L1
    lpm
    ret

