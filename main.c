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
	
	while(1){
	    if (buttonCom.active == 1)
	    {
	        switch (buttonCom.button) //welche Knopf?
	                {
	        case 1: //Start-Knopf
	            P8OUT |=  LCD_BL;    //beleuchtung ein
	            break;
	            case 2: //Stop-Knopf
	                P8OUT &= ~LCD_BL;   //beleuchtung aus
	                break;
	                default:
	                    break;
	                }
	        buttonCom.active = 0; //Flag zurücksetzen
	            }
	}
}
