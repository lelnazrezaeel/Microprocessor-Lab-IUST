#include <mega32.h>
#include <stdio.h>

void putterminal(unsigned char n)
{
    if (n <= 9)
    {
        putchar(n + '0');
    }
    else
    {
        putchar(n - 10 + 'A');
    }
}

void main(void)
{
    const char msg[] = "In the name of God\r\n";
    int i, prev = 0;

    DDRA = (0 << DDA7) | (0 << DDA6) | (0 << DDA5) | (0 << DDA4) | (0 << DDA3) | (0 << DDA2) | (0 << DDA1) | (0 << DDA0);
    PORTA = (0 << PORTA7) | (0 << PORTA6) | (0 << PORTA5) | (0 << PORTA4) | (0 << PORTA3) | (0 << PORTA2) | (0 << PORTA1) | (0 << PORTA0);

    UCSRA = (0 << RXC) | (0 << TXC) | (0 << UDRE) | (0 << FE) | (0 << DOR) | (0 << UPE) | (0 << U2X) | (0 << MPCM);
    UCSRB = (0 << RXCIE) | (0 << TXCIE) | (0 << UDRIE) | (1 << RXEN) | (1 << TXEN) | (0 << UCSZ2) | (0 << RXB8) | (0 << TXB8);
    UCSRC = (1 << URSEL) | (0 << UMSEL) | (0 << UPM1) | (0 << UPM0) | (0 << USBS) | (1 << UCSZ1) | (1 << UCSZ0) | (0 << UCPOL);
    UBRRH = 0x00;
    UBRRL = 0x33;

    for (i = 0; msg[i]; i++)
        putchar(msg[i]);

    while (1)
    {
        unsigned int dipsw = PINA;
        if (dipsw != prev)
        {
            unsigned char yekan, dahgan;
            prev = dipsw;
            yekan = dipsw % 16;
            dahgan = dipsw / 16;
            putterminal(dahgan);
            putterminal(yekan);
            putchar('\r');
            putchar('\n');
        }
    }
}
