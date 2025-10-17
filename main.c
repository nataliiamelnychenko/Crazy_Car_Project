#include <msp430.h> 
#include "hal_general.h"
#include "hal_gpio.h"

extern ButtonCom buttonCom;  //Variable aus hal_general.c

/**
 * main.c
 */
void main(void)
{
    hal_Init();
	
	while(1){
	    if (buttonCom.active == 1)
	    {
	        switch (buttonCom.button) //welche Knopf?
	                {
	        case 1: //Start-Knopf
	            P1OUT |= I2C_INT_MOTION;    //beleuchtung ein
	            break;
	            case 2: //Stop-Knopf
	                P1OUT &= ~I2C_INT_MOTION;   //beleuchtung aus
	                break;
	                default:
	                    break;
	                }
	        buttonCom.active = 0; //Flag zurücksetzen
	            }
	}
}
