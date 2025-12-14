#include <reg51.h>

#define LCD P1     // LCD data pins connected to Port 1

sbit RS = P2^0;    // Register Select
sbit EN = P2^1;    // Enable pin

void delay();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char dat);
void lcd_init();
void lcd_string(unsigned char *str);

void main()
{
    lcd_init();                  // Initialize LCD
    lcd_string("HELLO GT");    // Print message

    while(1);                    // Stay here
}

void lcd_init()
{
    lcd_cmd(0x38);   // 8-bit, 2 line, 5x7 font
    lcd_cmd(0x0C);   // Display ON, cursor OFF
    lcd_cmd(0x06);   // Auto increment cursor
    lcd_cmd(0x01);   // Clear display
}

void lcd_cmd(unsigned char cmd)
{
    LCD = cmd;
    RS = 0;          // Command mode
    EN = 1;
    delay();
    EN = 0;
}

void lcd_data(unsigned char dat)
{
    LCD = dat;
    RS = 1;          // Data mode
    EN = 1;
    delay();
    EN = 0;
}

void lcd_string(unsigned char *str)
{
    while(*str)
    {
        lcd_data(*str);
        str++;
    }
}

void delay()
{
    unsigned int i, j;
    for(i = 0; i < 50; i++)
        for(j = 0; j < 1275; j++);
}
