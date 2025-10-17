#include "hal_gpio.h"

#include <msp430.h>

extern ButtonCom buttonCom;  //deklariert als externe globale Variable - echt existiert in hal_general.c

void hal_GpioInit(void)
{
    P1DIR &= ~RPM_SENSOR;
    P1DIR &= ~RPM_SENSOR_DIR;
    P1DIR &= ~START_BUTTON; //als Eingang konfiguriert
    P1DIR &= ~STOP_BUTTON; //als Eingang konfiguriert

    P1DIR |= I2C_INT_MOTION;


    // Unbenutzte pins in output low setzen:
    P1SEL  &= ~(BIT2 | BIT1 | BIT0);   // GPIO
    P1DIR  |=  (BIT2 | BIT1 | BIT0);   // output
    P1OUT  &= ~(BIT2 | BIT1 | BIT0);   // low setzen

    P1REN |= (START_BUTTON | STOP_BUTTON); //Pull-Up/Down aktivieren
    P1OUT |= (START_BUTTON | STOP_BUTTON);       // Pull-Up ausw�hlen

    P1IE |= START_BUTTON; //Aktivierung des Interrupts
    P1IE |= STOP_BUTTON; //Aktivierung des Interrupts

    P1IES |= (START_BUTTON | STOP_BUTTON); //fallende Flanke(1-0)

    P1IFG &= ~(START_BUTTON | STOP_BUTTON); // gel�scht in der ISR

    __enable_interrupt(); //Aktivierung des GIE(Global Interrupt Enable)-Bit(erlaubt alle Interrupts)

}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
        unsigned char ifg_mask = P1IFG & (START_BUTTON | STOP_BUTTON); //nur zwei Tasten ber�cksichtigen!
            switch (ifg_mask)
            {
            case START_BUTTON: // Start wurde gedr�ckt
                __delay_cycles(5000);          //Pause um das Prellen zu vermeiden
                if ((P1IN & START_BUTTON) == 0)       //pr�fen, ob die Taste noch gedr�ckt ist
                        {
                    buttonCom.active = 1;   //active-Flag, eine Knopf ist gedr�ckt
                    buttonCom.button = 1;   //button-Nummer, welche Knopf
                        }
                        P1IFG &= ~START_BUTTON;   // Interrupt-Flag l�schen, sonst kommt der Interrupt wieder
            break;

            case STOP_BUTTON:  // Stop wurde gedr�ckt
                __delay_cycles(5000);
                if ((P1IN & STOP_BUTTON) == 0)
                    {
                    buttonCom.active = 1;
                    buttonCom.button = 2;
                    }
                P1IFG &= ~STOP_BUTTON;
                break;
            }

}



