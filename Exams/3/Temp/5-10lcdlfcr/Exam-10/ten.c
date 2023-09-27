

#include <mega32.h>

// Alphanumeric LCD functions
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned char a = 0;
bool ON = false;                    // Initialize LED as OFF

// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{
    if (ON) a = a + 10;
    else    a++; 
    delay_ms(10);
}

// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void)
{
    if (ON) a = a - 10;
    else    a--;
    delay_ms(10);
}

// External Interrupt 2 service routine
interrupt [EXT_INT2] void ext_int2_isr(void)
{
    ON = !ON;                                 // TOGGLE LED state
    if(ON) PORTC = PORTC | 0b00001000;        
    else PORTC = PORTC & 0b11110111; 

}


void main(void)
{

char *str;
str = '';
PORTC=0x00;
DDRC=0x08;             

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

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

lcd_init(16);


#asm("sei")

while (1)
      {
      lcd_gotoxy(0,0);
      itoa(a,str);                                                                                      
      lcd_puts(str);
      lcd_putchar(' ');
      lcd_putchar(' ');
      delay_ms(50);
      }
}