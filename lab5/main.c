//https://www.kingbrightusa.com/images/catalog/SPEC/SA08-11SRWA.pdf

#define F_CPU 16000000UL 	//частота процессора
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

volatile uint8_t counter = 0; // Счетчик секунд

void switch_sides(int i)
{
	switch(i) {
		case 1: 
			PORTD |= (1 << PD4); // C
			PORTD |= (1 << PD3); // B
			break;
		case 2:
			PORTD |= (1 << PD2); // A
			PORTD |= (1 << PD3); // b
			PORTB |= (1 << PB5); // g
			PORTD |= (1 << PD5); // d
			PORTB |= (1 << PB6); // E
			break;
		case 3:
			PORTD |= (1 << PD2);
			PORTD |= (1 << PD3);
			PORTB |= (1 << PB5);
			PORTD |= (1 << PD4);
			PORTD |= (1 << PD5);
			break;
		case 4:
			PORTB |= (1 << PB4);
			PORTB |= (1 << PB5);
			PORTD |= (1 << PD3);
			PORTD |= (1 << PD4);
			break;
		case 5:
			PORTD |= (1 << PD2);
			PORTB |= (1 << PB4);
			PORTB |= (1 << PB5);
			PORTD |= (1 << PD4);
			PORTD |= (1 << PD5);
			break;
	}
}

void clear_shit() {
	PORTB &= ~(1 << PB4);
	PORTB &= ~(1 << PB5);
	PORTD &= ~(1 << PD2);
	PORTD &= ~(1 << PD3);
	PORTD &= ~(1 << PD4);
	PORTD &= ~(1 << PD5);
}


int main ()
{
	SREG &= ~(1 << 7);
	// Настройка вывода управления светодиодом
	DDRE |= (1 << PE6); // Настройка вывода PB6 на выход
	PORTE &= ~(1 << PE6); // Выключен на старте МК
	
	DDRB |= (1 << PB4);
	PORTB &= ~(1 << PB4);
		
	DDRB |= (1 << PB5);
	PORTB &= ~(1 << PB5);
	
	DDRD |= (1 << PD2);
	PORTD &= ~(1 << PD2);
	
	DDRD |= (1 << PD3);
	PORTD &= ~(1 << PD3);
	
	DDRD |= (1 << PD4);
	PORTD &= ~(1 << PD4);
	
	DDRD |= (1 << PD5);
	PORTD &= ~(1 << PD5);
	
	// Настройка таймера
	TCCR1A = 0;
	TCCR1B = (1 << CS12) | (0 << CS11) | (1 << CS10); // Делитель 1024
	OCR1A = 0x3D09; // 15625 — 1 секунда
	TCNT1 = 0;
	// Обнуление счетчика
	TIMSK1 = (1 << OCIE1A); // Активация прерывания для данного таймера
	SREG |= (1 << 7);
	while (1)
	{
		if (counter == 5)
		{
			PORTE |= (1 << PE6);
			for (int count = 5; count >= 1; count--){
				switch_sides(count);
				_delay_ms(1000);
				clear_shit();
				
			}
		} else if (counter == 10)
				{
					PORTE &= ~(1 << PE6);
					counter = 0;
				}
	}
}
ISR(TIMER1_COMPA_vect)
{
	counter++;
	TCNT1 = 0;
}
