/*******************************************************
Project : Alimohammad Movahedian
Version : Az11
Date    : 17/07/2020
Author  : 
*******************************************************/

#include <mega32.h>

#include <delay.h>
#include <stdlib.h>

// I2C Bus functions
#include <i2c.h>

// DS1307 Real Time Clock functions
#include <ds1307.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here

void main(void)
{
// Declare your local variables here

unsigned char a,b,c,w;
char *s;
s = 0;

i2c_init();

rtc_init(0,0,0);

lcd_init(20);

while (1)
      {
      // Place your code here
        rtc_get_time(&a, &b, &c);
        lcd_clear();
        lcd_putsf("TIME> ");
        itoa(a,s);
        lcd_puts(s);
        lcd_putsf(" ");
        itoa(b,s);
        lcd_puts(s); 
        lcd_putsf(" ");
        itoa(c,s);
        lcd_puts(s);
         
        lcd_gotoxy(0,1);
        
        rtc_get_date(&w, &a, &b, &c);
        lcd_putsf("DATE> ");
        itoa(a,s);
        lcd_puts(s);
        lcd_putsf(" ");
        itoa(b,s);
        lcd_puts(s); 
        lcd_putsf(" 20");
        itoa(c,s);
        lcd_puts(s);        
                      
        
        delay_ms(250);
      }
}
