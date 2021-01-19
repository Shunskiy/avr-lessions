#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

//Функция отключения всех диодов
void disableAll {
    PORTE &= ~(1 << PE1);
    PORTE &= ~(1 << PE2);
    PORTE &= ~(1 << PE3);
}

int main ()
{
    DDRE |= (1 << PE1);
    DDRE |= (1 << PE2);
    DDRE |= (1 << PE3);
    DDRE &= ~(1 << PE4);
    DDRE &= ~(1 << PE5);
    PORTE |= (1 << PE1); //1 диод горит сразу
    PORTE &= ~(1 << PE2);
    PORTE &= ~(1 << PE3);
    PORTE |= (1 << PE4);
    PORTE |= (1 << PE5);
    
    uint8_t btn_click_counter = 0;
    uint8_t btn_ticks_counter = 0;
    
    while (1)
    {
        //Кнопка перехода вперёд
        if ((PINE & (1 << PE4)) == 0)
        {
            _delay_ms(10);
            if (btn_ticks_counter == 0)
            {
                //Проверка последнего диода
                if (btn_click_counter == 2) {
                    btn_click_counter = 0;
                } else {
                    btn_click_counter++;    
                }
                
            }
            
            if (btn_ticks_counter < 10){
                btn_ticks_counter++;
            }
        } else
        {
            btn_ticks_counter = 0;
        }
        
        
        //Кнопка перехода назад
        if ((PINE & (1 << PE5)) == 0)
        {
            _delay_ms(10);
            if (btn_ticks_counter == 0)
            {
                //Проверка первого диода
                if (btn_click_counter == 0) {
                    btn_click_counter = 2;
                } else {
                    btn_click_counter--;    
                }
            }
            
            if (btn_ticks_counter < 10){
                btn_ticks_counter++;
            }
        } else
        {
            btn_ticks_counter = 0;
        }
        
        
        
        //Переключение диода взависимости от значения btn_click_counter
        if (btn_click_counter == 0){
                disableAll();
                PORTE &= ~(1 << PE1);
		} else if (btn_click_counter == 1 ){
                disableAll();
                PORTE &= ~(1 << PE2);
		} else if (btn_click_counter == 2 ){
                disableAll();
                PORTE &= ~(1 << PE3);
    }
}