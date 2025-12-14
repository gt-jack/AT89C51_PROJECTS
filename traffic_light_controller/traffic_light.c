#include <reg51.h>

/* Road 1 */
sbit R1_G = P2^0;
sbit R1_Y = P2^1;
sbit R1_R = P2^2;

/* Road 2 */
sbit R2_G = P2^3;
sbit R2_Y = P2^4;
sbit R2_R = P2^5;

/* Road 3 */
sbit R3_G = P2^6;
sbit R3_Y = P2^7;
sbit R3_R = P1^3;

/* Road 4 */
sbit R4_G = P1^0;
sbit R4_Y = P1^1;
sbit R4_R = P1^2;

void delay(unsigned int d)
{
    unsigned int i, j;
    for(i=0;i<d;i++)
        for(j=0;j<3000;j++);
}

/* All RED ON */
void all_red()
{
    R1_R = 0; R2_R = 0; R3_R = 0; R4_R = 0;
    R1_G = 1; R1_Y = 1;
    R2_G = 1; R2_Y = 1;
    R3_G = 1; R3_Y = 1;
    R4_G = 1; R4_Y = 1;
}

void main()
{
    while(1)
    {
        /* ROAD 1 */
        all_red();
        R1_R = 1;
        R1_G = 0;
        delay(100);
        R1_G = 1;
        R1_Y = 0;
        delay(50);

        /* ROAD 2 */
        all_red();
        R2_R = 1;
        R2_G = 0;
        delay(100);
        R2_G = 1;
        R2_Y = 0;
        delay(50);

        /* ROAD 3 */
        all_red();
        R3_R = 1;
        R3_G = 0;
        delay(100);
        R3_G = 1;
        R3_Y = 0;
        delay(50);

        /* ROAD 4 */
        all_red();
        R4_R = 1;
        R4_G = 0;
        delay(100);
        R4_G = 1;
        R4_Y = 0;
        delay(50);
    }
}
