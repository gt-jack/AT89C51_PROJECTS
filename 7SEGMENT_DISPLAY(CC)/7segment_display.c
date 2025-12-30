#include <reg51.h>

unsigned char seg_code[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i=0;i<ms;i++)
        for(j=0;j<1275;j++);
}

void main()
{
    unsigned char i;
    while(1)
    {
        for(i=0;i<10;i++)
        {
            P2 = seg_code[i];  // send data to 7-seg
            delay_ms(100);
        }
    }
}
