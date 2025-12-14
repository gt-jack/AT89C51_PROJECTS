#include <reg51.h>

sbit LED = P1^0;   // LED connected to P1.0

void delay_ms(unsigned int ms);

void main()
{
    while(1)
    {
        LED = 1;      // LED ON
        delay_ms(500);

        LED = 0;      // LED OFF
        delay_ms(500);
    }
}

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 100; j++);
}
