#define F_CPU 8000000UL
#include <avr/io.h>

int main(void)
{
    unsigned char number[10] = {
        0x3F,           //0
        0x06,           //1
        0x5B,           //2
        0x4F,           //3
        0x66,           //4
        0x6D,           //5
        0x7D,           //6
        0x07,           //7
        0x7F,           //8
        0x6F            //9
    };
    DDRA = 0xFF;
    DDRB = 0xFF;
    DDRD = 0x00;
    PORTD = 0x01;                   // 1 default
    unsigned char count = 0;
    bool but_state = false;
    PORTA = number[count / 10];
    PORTB = number[count % 10];
    while (1)
    {
        //Button on - PIND == 0bxxxxxxx0 (0x00)
        //Button off - PIND == 0bxxxxxxx1 (0x01)
        
        if ( but_state ^ (~PIND & 0x01)){
            but_state = !but_state;
            if (!but_state){
                count = (count + 1) % 100;
                PORTA = number[count / 10];
                PORTB = number[count % 10];
            }
        }
    }
}

