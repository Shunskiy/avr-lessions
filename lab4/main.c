#define F_CPU 16000000UL 
#include <avr/io.h>
#include <util/delay.h>

uint8_t read_adc(uint8_t aADCPort)
{
uint8_t valADMUX = ADMUX;
valADMUX &= ~((1 << MUX5) | (1 << MUX4) | (1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
switch (aADCPort)
{
    case 0: valADMUX |= (0 << MUX5)|(0 << MUX4)|(0 << MUX3)|(0 << MUX2)|(0 << MUX1)|(0 << MUX0); break;
    case 1: valADMUX |= (0 << MUX5)|(0 << MUX4)|(0 << MUX3)|(0 << MUX2)|(0 << MUX1)|(1 << MUX0); break;
    case 2: valADMUX |= (0 << MUX5)|(0 << MUX4)|(0 << MUX3)|(0 << MUX2)|(1 << MUX1)|(0 << MUX0); break;
    case 3: valADMUX |= (0 << MUX5)|(0 << MUX4)|(0 << MUX3)|(0 << MUX2)|(1 << MUX1)|(1 << MUX0); break;
    case 4: valADMUX |= (0 << MUX5)|(0 << MUX4)|(0 << MUX3)|(1 << MUX2)|(0 << MUX1)|(0 << MUX0); break;
    case 5: valADMUX |= (0 << MUX5)|(0 << MUX4)|(0 << MUX3)|(1 << MUX2)|(0 << MUX1)|(1 << MUX0); break;
    case 6: valADMUX |= (0 << MUX5)|(0 << MUX4)|(0 << MUX3)|(1 << MUX2)|(1 << MUX1)|(0 << MUX0); break;
    case 7: valADMUX |= (0 << MUX5)|(0 << MUX4)|(0 << MUX3)|(1 << MUX2)|(1 << MUX1)|(1 << MUX0); break;
}
ADMUX = valADMUX;
uint16_t v = 0;
for (uint8_t id = 0; id < (1 << 4); ++id)
{
ADCSRA |= (1<<ADSC); 
while (ADCSRA & (1<<ADSC)); 
v += (uint16_t)ADC;
}
return (uint8_t)(v >> 4); 
}



int main ()
{
int8_t btn_click_counter = 0;
uint8_t btn_ticks_counter = 0;	
	
DDRE &= ~(1 << PE2);
PORTE |= (1 << PE2);

DDRE |= (1 << PE7);
PORTE &= ~(1 << PE7);

DDRE |= (1 << PE3); 
PORTE &= ~(1 << PE3); 

ADMUX = (0 << REFS1) | (1 << REFS0) 
| (0 << ADLAR); 
ADCSRA = (1 << ADEN) 
| (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); 
while (ADCSRB & (1 << REFOK)); 

while (1)
{
uint8_t val_adc = read_adc(0);
if ((PINE & (1 << PE2)) == 0)
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
        
if (btn_click_counter == 1) {
val_adc = read_adc(0);
if (val_adc < 60)
{
PORTE |= (1 << PE3);
} else
{
PORTE &= ~(1 << PE3);
}
_delay_ms(10);
} else if (btn_click_counter == 2) {
	val_adc = read_adc(1);
	btn_click_counter = 0;
}
}
}


