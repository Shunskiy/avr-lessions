#define F_CPU 16000000UL // Директива устновки частоты процессора
#include <avr/io.h>
// Библиотека для работы с портами ввода-вывода
#include <util/delay.h> // Библиотека для работы с паузой
int main ()
{
	int8_t btn_click_counter = 0;
    uint8_t btn_ticks_counter = 0;
	// Настройка вывода управления реле
	DDRB |= (1 << PB6); // Настройка вывода PB6 на выход
	PORTB &= ~(1 << PB6); // Выключен на старте МК
	DDRE &= ~(1 << PE5);
	PORTE |= (1 << PE5); 
	// Главный цикл работы МК
	while (1)
	{
		if ((PINE & (1 << PE5)) == 0)
        {
			_delay_ms(10);
            if (btn_ticks_counter == 0)
            {
                btn_click_counter++;
            }
            
            if (btn_ticks_counter < 100){
                btn_ticks_counter++;
            }
        } else
        {
            btn_ticks_counter = 0;
        }
		if (btn_ticks_counter == 50){
            for (int i = 1; i < btn_click_counter; i++) {
				PORTB |= (1 << PB6);
				_delay_ms(1000);
			}
			PORTB &= ~(1 << PB6);
			btn_click_counter = 0;
		}
			
       
	}
}
