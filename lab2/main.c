#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main ()
{
    DDRE |= (1 << PE0);
    DDRE &= ~(1 << PE5);
    PORTE &= ~(1 << PE0);
    PORTE |= (1 << PE5);
    
    uint8_t btn_click_counter = 0;
    uint8_t btn_ticks_counter = 0;
    
    while (1)
    {
        if ((PINE & (1 << PE5)) == 0)
        {
            _delay_ms(10);
            if (btn_ticks_counter == 0)
            {
                btn_click_counter++;
            }
            
            if (btn_ticks_counter < 10){
                btn_ticks_counter++;
            }
        } else
        {
            btn_ticks_counter = 0;
        }
        
        if (btn_ticks_counter == 9){
            for (int i = 1; i < btn_click_counter; i++) {
				PORTE |= (1 << PE0);
				_delay_ms(100);
				PORTE &= ~(1 << PE0);
				_delay_ms(100);
			}
			
			btn_click_counter = 0;
        }
    }
}
