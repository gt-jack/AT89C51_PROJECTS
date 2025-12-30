#include <reg51.h>

#define lcd P0

sbit rs = P2^0;
sbit en = P2^1;

sbit rd = P3^7;
sbit wr = P3^6;
sbit intr = P3^5;

void delay(unsigned int t)
{
    unsigned int i,j;
    for(i=0;i<t;i++)
        for(j=0;j<1275;j++);
}

void lcd_cmd(unsigned char c)
{
    lcd = c;
    rs = 0;
    en = 1;
    delay(1);
    en = 0;
}

void lcd_data(unsigned char d)
{
    lcd = d;
    rs = 1;
    en = 1;
    delay(1);
    en = 0;
}

void lcd_init()
{
    lcd_cmd(0x38); // 8-bit, 2 line
    lcd_cmd(0x0C); // Display ON
    lcd_cmd(0x06); // Cursor move
    lcd_cmd(0x01); // Clear
}

unsigned char adc_read()
{
    unsigned char value;

    wr = 0;
    delay(1);
    wr = 1;

    while(intr == 1);

    rd = 0;
    value = P1;
    rd = 1;

    return value;
}

void main()
{
    unsigned char adc, temp;

    lcd_init();
    lcd_cmd(0x80);
    lcd_data('T');
    lcd_data('E');
    lcd_data('M');
    lcd_data('P');
    lcd_data(':');

    while(1)
    {
        adc = adc_read();
        temp = adc / 2;

        lcd_cmd(0x85);
        lcd_data((temp/10) + '0');
        lcd_data((temp%10) + '0');
        lcd_data(223);   // Degree symbol
        lcd_data('C');

        delay(500);
    }
}
