#include <reg51.h>   // 8051 header file

void delay();       // delay function declaration

void main()
{
    while(1)        // infinite loop
    {
        P1 = 0x01;  // 0000 0001 ? LED at P1.0 ON
        delay();

        P1 = 0x02;  // 0000 0010 ? LED at P1.1 ON
        delay();

        P1 = 0x04;  // 0000 0100 ? LED at P1.2 ON
        delay();

        P1 = 0x08;  // 0000 1000 ? LED at P1.3 ON
        delay();

        P1 = 0x10;  // 0001 0000 ? LED at P1.4 ON
        delay();

        P1 = 0x20;  // 0010 0000 ? LED at P1.5 ON
        delay();

        P1 = 0x40;  // 0100 0000 ? LED at P1.6 ON
        delay();

        P1 = 0x80;  // 1000 0000 ? LED at P1.7 ON
        delay();
    }
}

void delay()
{
    unsigned int i, j;
    for(i = 0; i < 30; i++)
        for(j = 0; j < 1275; j++);
}
