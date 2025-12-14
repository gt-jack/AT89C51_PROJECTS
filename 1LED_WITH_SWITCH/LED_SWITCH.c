#include <reg51.h>

sbit LED = P1^0;   // LED at P1.0
sbit SW  = P1^1;   // Switch at P1.1

void delay_ms(unsigned int ms);

void main()
{
    LED = 0;   // LED OFF initially
    SW  = 1;   // Configure P1.1 as input (pull-up)

    while(1)
    {
        if(SW == 0)        // Switch PRESSED
        {
            LED = 1;      // LED ON
            delay_ms(100);

            if(SW == 1)   // If switch released during delay
            {
                LED = 0;
                continue;
            }

            LED = 0;      // LED OFF
            delay_ms(100);
        }
        else              // Switch RELEASED
        {
            LED = 0;      // LED OFF
        }
    }
}

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}
