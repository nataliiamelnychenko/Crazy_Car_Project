#include <msp430.h> 
#include "hal_general.h"
#include "hal_gpio.h"



/**
 * main.c
 */
void main(void)
{
    hal_Init();
	
	while(1){
	    lcd_bl_on();
	    volatile int int_result = calc_int(20, 30);
	    lcd_bl_off();
	    wait_in_us(500);
	    lcd_bl_on();
	    volatile float float_result = 20.00f * 30.00f;
	    lcd_bl_off();
	    wait_in_us(1000);
	}
}
