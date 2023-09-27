#include <glcd.h> 
#include <font5x7.h> 
#include <mega32.h>          
#include <delay.h>

int counter;
void main(void)
{

GLCDINIT_t glcd_init_data;

DDRA=(1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);
 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);

PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);


DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);

PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);


DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);


glcd_init_data.font=font5x7;

glcd_init_data.readxmem=NULL;

glcd_init_data.writexmem=NULL;

glcd_init(&glcd_init_data);

while (1)
    {
        glcd_clear();                        
        glcd_moveto(5,0);
        glcd_outtext("Niki majidifard");
        glcd_moveto(5,55);
        glcd_outtext("98522382");
        delay_ms(2000);
  
        glcd_clear();     
        glcd_line(30,54,98,54); 
        glcd_line(98,54,98,32); 
        glcd_line(30,32,30,54);
        glcd_line(20,32,30,32);
        glcd_line(98,32,108,32);
        glcd_line(108,32,64,5);
        glcd_line(64,5,40,20);
        glcd_line(40,20,40,10);
        glcd_line(40,10,45,10);
        glcd_line(45,10,45,5);
        glcd_line(45,5,25,5);
        glcd_line(25,5,25,10);
        glcd_line(25,10,30,10);
        glcd_line(30,10,30,25);
        glcd_line(30,25,20,32);
        delay_ms(2000);
        // Section 3 
        glcd_clear();    
        for(counter = 0; counter < 30; counter++)
        {
          glcd_clear();
          glcd_circle(2 + 2 * counter, 60 - 2 * counter, 2);
          delay_ms(70);
        }
            
        for(counter = 0; counter <= 31; counter++)
        {
          glcd_clear();
          glcd_circle(60 + 2 * counter, 2 + 2 * counter, 2);
          delay_ms(70);
        }
            
        for(counter = 0; counter < 30; counter++)
        {
          glcd_clear();
          glcd_circle(118 - 2 * counter, 60 - 2 * counter, 2);
          delay_ms(70);
        }
            
        for(counter = 0; counter < 30; counter++)
        {
          glcd_clear();
          glcd_circle(60 - 2 * counter, 2 + 2 * counter, 2);
          delay_ms(70);
        }
    }
}
