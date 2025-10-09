#include "hal_gpio.h"

#include <msp430.h>

void hal_GpioInit(void)
{
    P1DIR &= ~RPM_SENSOR;
    P1DIR &= ~RPM_SENSOR_DIR;
    P1DIR &= ~START_BUTTON;
    P1DIR &= ~STOP_BUTTON;

    P1DIR |= I2C_INT_MOTION;

    P8DIR |= LCD_BL;


    // Unbenutzte pins in output low setzen:
    P1SEL  &= ~(BIT2);   // GPIO
    P1DIR  |=  (BIT2);   // output
    P1OUT  &= ~(BIT2);   // low setzen


}

void lcd_bl_on(void)
{
    P8OUT |= LCD_BL;
}

void lcd_bl_off(void)
{
    P8OUT &= ~LCD_BL;
}

int calc_int(int a, int b)
{
    int result= a*b;
    return result;
}



void wait_in_us(int time)
{
    int one_us = 20;
    int i;

    for (i = 0; i<one_us*time; i++)
    {

    }
}
