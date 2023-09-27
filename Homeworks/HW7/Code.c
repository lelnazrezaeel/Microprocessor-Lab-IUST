// Elnaz Rezaee 98411387

#include <mega32.h>
#include <stdlib.h>
#include <delay.h>

// Alphanumeric LCD functions
#include <alcd.h>

#define ADC_VREF_TYPE 0x40

int temp;
char show_arr[5];

unsigned int read_adc(unsigned char adc_input)
{
    ADMUX = adc_input | (ADC_VREF_TYPE & 0xff);

    delay_us(10);

    ADCSRA |= 0x40;
    while ((ADCSRA & 0x10) == 0)
        ;
    ADCSRA |= 0x10;
    return ADCW;
}

void main(void)
{

    PORTA = 0x00;
    DDRA = 0x00;

    PORTB = 0x00;
    DDRB = 0x00;

    PORTC = 0xFF;
    DDRC = 0x00;

    PORTD = 0x00;
    DDRD = 0x00;

    TCCR0 = 0x00;
    TCNT0 = 0x00;
    OCR0 = 0x00;

    TCCR1A = 0x00;
    TCCR1B = 0x00;
    TCNT1H = 0x00;
    TCNT1L = 0x00;
    ICR1H = 0x00;
    ICR1L = 0x00;
    OCR1AH = 0x00;
    OCR1AL = 0x00;
    OCR1BH = 0x00;
    OCR1BL = 0x00;

    ASSR = 0x00;
    TCCR2 = 0x00;
    TCNT2 = 0x00;
    OCR2 = 0x00;

    MCUCR = 0x00;
    MCUCSR = 0x00;

    TIMSK = 0x00;

    UCSRB = 0x00;

    ACSR = 0x80;
    SFIOR = 0x00;

    ADMUX = ADC_VREF_TYPE & 0xff;
    ADCSRA = 0x85;

    SPCR = 0x00;

    TWCR = 0x00;

    lcd_init(16);
    lcd_clear();
    lcd_gotoxy(2, 0);
    lcd_puts("TEMPERATURE");

    while (1)
    {
        temp = read_adc(0);
        temp = (temp * 4.8898);
        temp = temp / 10;
        lcd_gotoxy(5, 1);
        ftoa(temp, 2, show_arr);
        lcd_puts(show_arr);
        delay_ms(1000);
    }
}
