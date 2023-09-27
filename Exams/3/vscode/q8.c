#include <mega32.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>

void main(void)
{
    char input;

    DDRC = 0x00;
    PORTC = 0x00;

    DDRD = 0x00;
    PORTD = 0x00;

    UCSRA = 0x00;
    UCSRB = (0 << RXCIE) | (0 << TXCIE) | (0 << UDRIE) | (1 << RXEN) | (1 << TXEN) | (0 << UCSZ2) | (0 << RXB8) | (0 << TXB8);
    UCSRC = (1 << URSEL) | (0 << UMSEL) | (0 << UPM1) | (0 << UPM0) | (0 << USBS) | (1 << UCSZ1) | (1 << UCSZ0) | (0 << UCPOL);
    UBRRH = 0x00;
    UBRRL = 0x33;

    lcd_init(16);

    while (1)
    {
        input = getchar();
        if (((int)input >= 65 && (int)input <= 90) || ((int)input >= 97 && (int)input <= 122))
        { // Checking ascii codes
            putchar(input);
            lcd_putchar(input);
            putchar(0x0d);
            putchar(0x0a);
        }

        if (input == '1')
        {
            putchar(input);
            putchar(0x0d);
            putchar(0x0a);
            lcd_clear();
            lcd_gotoxy(0, 0);
            lcd_puts("Bayan");
            lcd_gotoxy(0, 1);
            lcd_puts("Divaaniazar");
        }
        else if (input == '2')
        {

            putchar(input);
            putchar(0x0d);
            putchar(0x0a);
            puts("Bayan DivaaniAzar");
            putchar(0x0d);
            putchar(0x0a);
            // lcd_gotoxy(0,0);
            // lcd_puts("6");
        }

        else if (input == '7')
        {
            putchar(input);
            putchar(0x0d);
            putchar(0x0a);
            lcd_clear();
        }
    }
}
