/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 6/6/2023
Author  : 
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h> 
#include <delay.h> 
 
const char code[] = { 0x3F, 0x06, 0x5B, 0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F, 0x77,0x7C, 0x39 , 0x5E, 0x79, 0x71 }  ; 
unsigned char x = 0; 
unsigned int a = 0; 
unsigned int b = 0; 
unsigned int c = 0; 
 
// Timer 0 output compare interrupt service routine 
int Tohex(char a)
{
    int x=0;
    if(a == '' || a == '0' || a == '16') x = 0x3F;
    else if (a =='1') x = 0x06;
    else if (a == '2') x = 0x5B;
    else if(a == '3') x = 0x4F;
    else if (a =='4') x = 0x66;
    else if (a == '5') x = 0x6D;
    else if(a == '6') x = 0x7D;
    else if (a =='7') x = 0x07;
    else if (a == '8') x = 0x7F;
    else if(a == '9') x = 0x6F;
    else if (a =='A') x = 0x77;
    else if (a == 'B') x = 0x7C;
    else if(a == 'C') x = 0x39;
    else if (a =='D') x = 0x5E;
    else if (a == 'E') x = 0x79;
    else if(a =='F') x = 0x71;

    return x;
}
interrupt [TIM0_COMP] void timer0_comp_isr(void) 
{        
    b=Tohex((int)hexadecimalnum[0]);
    PORTC = b;
    delay_ms(20);
    PORTD = 0b11101111;
    c=Tohex((int)hexadecimalnum[1]); 
    PORTC = c;
    delay_ms(20);
} 
void main(void) 
{ 
// Declare your local variables here 
 
// Input/Output Ports initialization 
// Port A 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0); 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0); 
 
// Port B
DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0); 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0); 
 
// Port C 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0); 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0); 
 
// Port D 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0); 
PORTD = 0xff; 
 
// Timer/Counter 0 initialization 
// Clock source: System Clock 
// Clock value: 7.813 kHz 
// Mode: CTC top=OCR0 
// OC0 output: Disconnected 
// Timer Period: 0.128 ms 
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (1<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00); 
TCNT0=0x00; 
OCR0=0x00; 
 
// Timer(s)/Counter(s) Interrupt(s) initialization 
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (1<<OCIE0) | (0<<TOIE0); 
 
// Global enable interrupts 
#asm("sei") 
 
while (1) 
      { 
      } 
}