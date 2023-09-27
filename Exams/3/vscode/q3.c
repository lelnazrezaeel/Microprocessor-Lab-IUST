#include <mega32.h>

int counter, rem = 0, index;
char hex[2];
char HEXVALUE[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
char code[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

int i = 0;
int j = 0;
unsigned int number = 0;
int tempDecimal;

interrupt[TIM0_COMP] void timer0_comp_isr(void)
{
    counter++;
    if (counter == 2)
        counter = 0;

    number = PINA;

    i = number % 10;
    j = number / 10;

    index = 0;

    tempDecimal = number;
    while (tempDecimal != 0)
    {
        rem = tempDecimal % 16;
        hex[index] = HEXVALUE[rem];
        tempDecimal /= 16;
        index++;
    }

    if (counter == 0)
    {
        PORTD = 0b11011111;
        PORTC = code[hex[1] - 48];
        if (hex[1] >= 'A' && hex[1] <= 'F')
            PORTC = code[hex[1] - 55];
    }

    else if (counter == 1)
    {
        PORTD = 0b11111101;
        PORTC = code[hex[0] - 48];
        if (hex[0] >= 'A' && hex[0] <= 'F')
            PORTC = code[hex[0] - 55];
    }

    number = 0;
    hex[0] = '';
    hex[1] = '';
}

void main(void)
{
    PORTC = 0x00;
    DDRC = 0xFF;
    DDRD = 0xFF;

    TCCR0 = 0x0C;
    TCNT0 = 0x00;
    OCR0 = 0x63;

    TIMSK = 0x12;

#asm("sei")

    while (1)
    {
    }
}
