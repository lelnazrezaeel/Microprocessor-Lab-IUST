#include <mega32.h>

// Alphanumeric LCD functions
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>
unsigned char a = 0;
unsigned char LED = 0;
// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{
    if (LED == 1)
    { 
        a = a + 10;
    }
    else 
    {
        a++;
    }
    delay_ms(10);
}

// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void)
{
    if (LED == 1)
    { 
        a = a - 10;
    }
    else 
    {
        a--;
    }
    delay_ms(10);
}

// External Interrupt 2 service routine
interrupt [EXT_INT2] void ext_int2_isr(void)
{
    if (LED == 0)
    {
        LED = 1;
        PORTC = PORTC | 0b00001000;
    }
    else 
    {
        LED = 0;
        PORTC = PORTC & 0b11110111;
    }
    delay_ms(10);

}

// Declare your global variables here

void main(void)
{
// Declare your local variables here
char *str = "";
// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x00;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x08;              // for LED 

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;


// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Low level
// INT1: On
// INT1 Mode: Low level
// INT2: On
// INT2 Mode: Falling Edge
GICR|=0xE0;
MCUCR=0x00;
MCUCSR=0x00;
GIFR=0xE0;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTC Bit 0
// RD - PORTC Bit 1
// EN - PORTC Bit 2
// D4 - PORTC Bit 4
// D5 - PORTC Bit 5
// D6 - PORTC Bit 6
// D7 - PORTC Bit 7
// Characters/line: 16
lcd_init(16);

// Global enable interrupts
#asm("sei")

while (1)
      {
      // Place your code here
      lcd_gotoxy(0,0);
      itoa(a,str);                                                                                      
      lcd_puts(str);
      lcd_putchar(' ');
      lcd_putchar(' ');
      delay_ms(50);
      }
}