
#include <mega32.h>

char numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

unsigned int counter = 0;

interrupt[TIM0_COMP] void timer0_comp_isr(void)
{
    int a, n;

    counter++;
    if (counter == 3)
        counter = 0;

    a = PINA;
    n = a % 10;

    switch (counter)
    {

    case (0):
        PORTD = 0b11011111;
        PORTC = numbers[n];
        break;

    case (1):
        PORTD = 0b11101111;
        n = (a % 100) / 10;
        PORTC = numbers[n];
        break;

    case (2):
        PORTD = 0b11110111;
        n = (a / 100);
        PORTC = numbers[n];
        break;

    default:
        break;
    }
}

void main(void)
{

    DDRA = 0x00;
    PORTA = 0x00;

    DDRC = 0xff;
    PORTC = 0x00;

    DDRD = 0xff;
    PORTD = 0x00;

    TCCR0 = 0x0C;
    TCNT0 = 0x00;
    OCR0 = 0x63;
    TCCR1A = 0x00;
    TCCR1B = 0x0C;
    TCNT1H = 0x00;
    TCNT1L = 0x00;
    ICR1H = 0x00;
    ICR1L = 0x00;
    OCR1AH = 0x7A;
    OCR1AL = 0x12;
    OCR1BH = 0x00;
    OCR1BL = 0x00;
    TCCR2 = 0x00;
    TCNT2 = 0x00;
    OCR2 = 0x00;
    MCUCR = 0x00;
    MCUCSR = 0x00;
    TIMSK = 0x12;

    ACSR = 0x80;
    SFIOR = 0x00;

#asm("sei")

    while (1)
    {
    }
}
