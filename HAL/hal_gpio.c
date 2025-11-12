#include "hal_gpio.h"

#include <msp430.h>


void hal_GpioInit(void)
{

    //SMCLK
    P3DIR |= BIT4;   //Ausgang
    P3SEL |= BIT4;   //SMCLK (nicht GPIO)


    // Unbenutzte pins in output low setzen:
    P1SEL  &= ~(BIT2 | BIT1 | BIT0);   // GPIO
    P1DIR  |=  (BIT2 | BIT1);   // output
    P1OUT  &= ~(BIT2 | BIT1);   // low setzen


    //Quarz Pins:
    P7SEL |= (XT2IN_P7 | XT2OUT_P7); //nicht GPIO, ein Modul!
    P7DIR &= ~(XT2IN_P7 | XT2OUT_P7); //als Eingangs
    P7REN &= ~(XT2IN_P7 | XT2OUT_P7); //ohne Pull-Up/Down
    P7OUT &= ~(XT2IN_P7 | XT2OUT_P7); //kein Signal an – es übernimmt UCS




}




