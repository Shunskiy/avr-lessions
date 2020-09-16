#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main ()
{
DDRE |= (1 « PE0);
DDRE |= (1 « PE1);
DDRE |= (1 « PE2);
    	while (1)
    	{
		PORTE |= (1 « PE0);
		_delay_ms(10);
		PORTE |= (1 « PE1);
		_delay_ms(10);
		PORTE |= (1 « PE2);
		_delay_ms(10);
    	}
}

