// Elnaz Rezaee 98411387

#include <mega32.h>
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define KEYPAD_R1 PORTD .0
#define KEYPAD_R2 PORTD .1
#define KEYPAD_R3 PORTD .2
#define KEYPAD_R4 PORTD .3
#define KEYPAD_C1 PIND .4
#define KEYPAD_C2 PIND .5
#define KEYPAD_C3 PIND .6
#define KEYPAD_C4 PIND .7

#define KEYPAD_NUM0 0
#define KEYPAD_NUM1 1
#define KEYPAD_NUM2 2
#define KEYPAD_NUM3 3
#define KEYPAD_NUM4 4
#define KEYPAD_NUM5 5
#define KEYPAD_NUM6 6
#define KEYPAD_NUM7 7
#define KEYPAD_NUM8 8
#define KEYPAD_NUM9 9

#define KEYPAD_DIV '/'
#define KEYPAD_MUL '*'
#define KEYPAD_SUB '-'
#define KEYPAD_ADD '+'

#define KEYPAD_EQ '='
#define KEYPAD_ON 'c'

unsigned char keypad_scan();
void calculate();
float number[10];
float opert[10];
char result_char[20];
int counter = 0;
int index = 0;
int last_op = 1;
int result = 0;
int i, j;
int error = 0;
void main(void)
{
    unsigned char key_res;
    DDRC = 0xFF;
    DDRD = 0x0F;
    PORTC = 0x00;
    lcd_init(16);
    lcd_clear();

    while (1)
    {
        key_res = keypad_scan();

        if (key_res != 255)
        {
            while (keypad_scan() != 255)
                ;
            delay_ms(20);

            if (key_res < 10)
            {
                last_op = 0;
                lcd_putchar(key_res + 48);
                number[counter] *= 10;
                number[counter] += key_res;
            }
            else if (last_op == 0 || key_res == KEYPAD_ON)
            {
                if (key_res == KEYPAD_EQ)
                {
                    last_op = 1;
                    lcd_putchar(key_res);
                    calculate();
                    if (error == 1)
                    {
                        lcd_gotoxy(0, 1);
                        lcd_puts("error");
                    }
                    else
                    {
                        sprintf(result_char, "%d", result);
                        lcd_gotoxy(0, 1);
                        lcd_puts(result_char);
                    }
                }
                else if (key_res == KEYPAD_ON)
                {
                    lcd_clear();
                    lcd_gotoxy(0, 0);
                    lcd_clear();
                    memset(number, 0, 10 * sizeof(int));
                    memset(opert, '\0', 10 * sizeof(char));
                    index = 0;
                    counter = 0;
                    last_op = 1;
                }
                else
                {
                    last_op = 1;
                    lcd_putchar(key_res);
                    counter++;
                    opert[index] = key_res;
                    index++;
                }
            }
        }
    }
}

void calculate()
{
    for (i = 0; i < index; i++)
    {
        if (opert[i] == '+' || opert[i] == '-')
            continue;
        if (opert[i] == '/')
        {
            if (number[i + 1] == 0)
                error = 1;
            else
                number[i] /= number[i + 1];
        }
        else if (opert[i] == '*')
        {
            number[i] *= number[i + 1];
        }
        counter--;
        index--;
        for (j = i + 1; j < counter + 1; j++)
        {
            number[j] = number[j + 1];
        }
        for (j = i; j < index; j++)
        {
            opert[j] = opert[j + 1];
        }
        i--;
    }
    for (i = 0; i < index; i++)
    {

        if (opert[i] == '+')
        {
            number[i] += number[i + 1];
        }
        else if (opert[i] == '-')
        {
            number[i] -= number[i + 1];
        }
        counter--;
        index--;
        for (j = i + 1; j < counter + 1; j++)
        {
            number[j] = number[j + 1];
        }
        for (j = i; j < index; j++)
        {
            opert[j] = opert[j + 1];
        }
        i--;
    }
    result = number[0];
    return;
}

unsigned char keypad_scan()
{
    unsigned char result = 255;

    ////////////////////////  ROW1 ////////////////////////
    KEYPAD_R1 = 1;
    KEYPAD_R2 = 0;
    KEYPAD_R3 = 0;
    KEYPAD_R4 = 0;

    delay_ms(5);
    if (KEYPAD_C1)
        result = KEYPAD_NUM7;
    else if (KEYPAD_C2)
        result = KEYPAD_NUM8;
    else if (KEYPAD_C3)
        result = KEYPAD_NUM9;
    else if (KEYPAD_C4)
        result = KEYPAD_DIV;

    ////////////////////////  ROW2 ////////////////////////
    KEYPAD_R1 = 0;
    KEYPAD_R2 = 1;
    KEYPAD_R3 = 0;
    KEYPAD_R4 = 0;

    delay_ms(5);
    if (KEYPAD_C1)
        result = KEYPAD_NUM4;
    else if (KEYPAD_C2)
        result = KEYPAD_NUM5;
    else if (KEYPAD_C3)
        result = KEYPAD_NUM6;
    else if (KEYPAD_C4)
        result = KEYPAD_MUL;

    ////////////////////////  ROW3 ////////////////////////
    KEYPAD_R1 = 0;
    KEYPAD_R2 = 0;
    KEYPAD_R3 = 1;
    KEYPAD_R4 = 0;

    delay_ms(5);
    if (KEYPAD_C1)
        result = KEYPAD_NUM1;
    else if (KEYPAD_C2)
        result = KEYPAD_NUM2;
    else if (KEYPAD_C3)
        result = KEYPAD_NUM3;
    else if (KEYPAD_C4)
        result = KEYPAD_SUB;

    ////////////////////////  ROW4 ////////////////////////
    KEYPAD_R1 = 0;
    KEYPAD_R2 = 0;
    KEYPAD_R3 = 0;
    KEYPAD_R4 = 1;

    delay_ms(5);
    if (KEYPAD_C1)
        result = KEYPAD_ON;
    else if (KEYPAD_C2)
        result = KEYPAD_NUM0;
    else if (KEYPAD_C3)
        result = KEYPAD_EQ;
    else if (KEYPAD_C4)
        result = KEYPAD_ADD;

    return result;
}