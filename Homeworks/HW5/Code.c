// Elnaz Rezaee 98411387

#include <mega32.h>
#include <delay.h>

unsigned char CODE[]= {
    0x00,    //    0002        . . . . . . . . 
    0x00,    //    0003        . . . . . . . . 
    0x00,    //    0004        . . . . . . . . 
    0x00,    //    0005        . . . . . . . . 
    0x00,    //    0006        . . . . . . . . 
    0x00,    //    0007        . . . . . . . . 
    0x00,    //    0008        . . . . . . . . 
    0x00,    //    0002        . . . . . . . . 
    0x00,    //    0003        . . . . . . . . 
    0x00,    //    0004        . . . . . . . . 
    0x00,    //    0005        . . . . . . . . 
    0x00,    //    0006        . . . . . . . . 
    0x00,    //    0007        . . . . . . . . 
    0x00,    //    0008        . . . . . . . . 
    0x7C,    //    0009        . # # # # # . . 
    0x12,    //    000A        . . . # . . # . 
    0x11,    //    000B        . . . # . . . # 
    0x12,    //    000C        . . . # . . # . 
    0x7C,    //    000D        . # # # # # . . 
    0x00,    //    000E        . . . . . . . . 
    0x00,    //    000F        . . . . . . . . 
    0x00,    //    0010        . . . . . . . . 
    0x00,    //    0011        . . . . . . . . 
    0x7F,    //    0012        . # # # # # # # 
    0x49,    //    0013        . # . . # . . # 
    0x49,    //    0014        . # . . # . . # 
    0x49,    //    0015        . # . . # . . # 
    0x36,    //    0016        . . # # . # # . 
    0x00,    //    0017        . . . . . . . . 
    0x00,    //    0018        . . . . . . . . 
    0x00,    //    0019        . . . . . . . . 
    0x3E,    //    001A        . . # # # # # . 
    0x41,    //    001B        . # . . . . . # 
    0x41,    //    001C        . # . . . . . # 
    0x41,    //    001D        . # . . . . . # 
    0x22,    //    001E        . . # . . . # . 
    0x00,    //    001F        . . . . . . . . 
    0x00,    //    0020        . . . . . . . . 
    0x00,    //    0021        . . . . . . . . 
    0x7F,    //    0022        . # # # # # # # 
    0x41,    //    0023        . # . . . . . # 
    0x41,    //    0024        . # . . . . . # 
    0x41,    //    0025        . # . . . . . # 
    0x3E,    //    0026        . . # # # # # . 
    0x00,    //    0027        . . . . . . . . 
    0x00,    //    0028        . . . . . . . . 
    0x00,    //    0029        . . . . . . . . 
    0x00,    //    002A        . . . . . . . . 
    0x00,    //    002B        . . . . . . . . 
    0x7F,    //    002C        . # # # # # # # 
    0x49,    //    002D        . # . . # . . # 
    0x49,    //    002E        . # . . # . . # 
    0x49,    //    002F        . # . . # . . # 
    0x49,    //    0030        . # . . # . . # 
    0x00,    //    0031        . . . . . . . . 
    0x00,    //    0032        . . . . . . . . 
    0x00,    //    0033        . . . . . . . . 
    0x00,    //    0034        . . . . . . . . 
    0x00,    //    0035        . . . . . . . . 
    0x7F,    //    0036        . # # # # # # # 
    0x09,    //    0037        . . . . # . . # 
    0x09,    //    0038        . . . . # . . # 
    0x09,    //    0039        . . . . # . . # 
    0x00,    //    003A        . . . . . . . . 
    0x00,    //    003B        . . . . . . . . 
    0x00,    //    003C        . . . . . . . . 
    0x00,    //    003D        . . . . . . . . 
    0x00,    //    003E        . . . . . . . . 
    0x00,    //    003F        . . . . . . . . 
    0x00,    //    0040        . . . . . . . . 
    0x00,    //    0041        . . . . . . . . 
    0x00,    //    0042        . . . . . . . . 
    0x00,    //    0043        . . . . . . . . 
    0x00,    //    0044        . . . . . . . . 
    0x00,    //    0045        . . . . . . . . 
    0x00,    //    0046        . . . . . . . . 
    0x00,    //    0047        . . . . . . . . 
    };

unsigned char PORT[16] = {1, 2, 4, 8, 16, 32, 64, 128, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned int s, col, timer;

void main(void) {


    PORTB=0x00;
    DDRB=0xFF; 
    
    PORTC=0x00;
    DDRC=0xFF;
    
    PORTD=0x00;
    DDRD=0xFF;

    while(1) {  
        for(s=8; s<72; s++) {
            for(timer=0; timer<4; timer++) {    
                for (col=0;col<16;col++) {   
                    POsRTB = PORT[col];
                    PORTC = ~CODE[s+col];       
                    delay_ms(1);    
                }
                 
                delay_ms(2);
                
                for (col=0; col<16; col++) {   
                    PORTD = PORT[col];
                    PORTC = ~CODE[s+col-8];        
                    delay_ms(1);
                }
            }
        }
    };
}
