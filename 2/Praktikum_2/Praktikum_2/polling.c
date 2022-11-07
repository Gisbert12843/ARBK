/*
* Author : KaiO_3239574
*/

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

#define led0 PINB0
#define led9 PINB1
#define sw0 PIND2
#define sw1 PIND3





int blinkstate = 1;
int currentLED = PINB1;

int main(void)
{
	
	DDRB = 0xff;
	PORTB = 0x00;
	
	DDRD = 0x00;
	PORTD = 0xff;
	
	//		PINB &= (1 << PINB0)	sets PINB0 to high
	//		PINB &= ~(1 << PINB0)	sets PINB0 to low
	//		PINB ^= (1 << PINB0)	toggles PINB0
	//		PINB |= (1 << PINB0)	sets PINB0 to high
	
	while (1)
	{
		blink_func();

		if(blinkstate == 1)
		{
			PORTB &= ~(1<< (!currentLED)); //sets all other LED to low
			PORTB ^= (1 << currentLED); //toggles current LED
		}
		else
		{
			PORTB &= ~(1<< (!currentLED)); //sets all other LED to low
			PORTB |= (1 << currentLED); //sets current LED to HIGH
		}
		_delay_ms(250);
	}
}

void blink_func(){
	if(!(PIND & (1<<sw0))) //checks for SW0 button press, negative since the buttons are low active
	{
		if(currentLED == led0) //if already on
		{
			//toggle blinkstate
			if(blinkstate == 1)
			{
				blinkstate = 0;
			}
			else
			{
				blinkstate = 1;
			}
		}
		else //change led if not on
		{
			currentLED = led0;
		}	
	}
	if(!(PIND & (1<<sw1))) //checks for SW1 button press, negative since the buttons are low active
	{
		if(currentLED == led9)
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
			currentLED = led9;
		}	
	}
}