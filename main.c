#include <msp430.h> 
#include "hal_general.h"
#include "hal_gpio.h"

extern volatile ButtonCom buttonCom;  //Variable aus hal_general.c

/**
 * main.c
 */
void main(void)
{
    hal_Init();

    __enable_interrupt();

	while(1){

	            }
}
