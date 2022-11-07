/*
* Author : KaiO_3239574
*/

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

#define led0 PINB0
#define led9 PINB1
#define sw0 PIND2
#define sw1 PIND3


int blinkstate = 1;
int currentLED = PINB0;

ISR(INT0_vect)
{
	if(currentLED == led0)
	{
		if(blinkstate == 1)
		{
			blinkstate = 0;
		}
		else
		{
			blinkstate = 1;
		}
	}
	else
	{
		currentLED = led0;
	}
}

ISR(INT1_vect){
	if(currentLED == led9)
	{
		//blinkstate toggle
		if(blinkstate == 1)
		{
			blinkstate = 0;
		}
		else
		{
			blinkstate = 1;
		}
	}
	else
	{
		currentLED = led9;
	}
}

int main(void)
{
	
	//Eingänge und Ausgänge
	DDRB = 0xff;
	PORTB = 0x00;
	
	DDRD = 0x00;
	PORTD = 0xff;
	
	//determines what to react to
	//VALUE11 rising edge
	//VALUE01 double edge
	EICRA |= (1<<ISC11) | (1<<ISC01);
	
	//External Interrupt Mask Register
	EIMSK |= (1<<INT0);
	EIMSK |= (1<<INT1);
	
	//how could you forget what this means..
	sei();
	
	while (1)
	{
		//		PINB &= (1 << PINB0)	sets PINB0 to high
		//		PINB &= ~(1 << PINB0)	sets PINB0 to low
		//		PINB ^= (1 << PINB0)	toggles PINB0
		//		PINB |= (1 << PINB0)	sets PINB0 to high
		
		
		
		if(blinkstate == 1)
		{
			PORTB &= ~(1<< (!currentLED)); //deactivates all other LED
			PORTB ^= (1 << currentLED); //toggles current LED
		}
		else
		{
			PORTB &= ~(1<< (!currentLED)); //deactivates all other LED
			PORTB |= (1 << currentLED); //sets currentLED to HIGH
		}
		_delay_ms(250);
	}
}






