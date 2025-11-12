#include <msp430.h>
#include "hal_timerA1.h"
#include "hal_gpio.h"

void hal_TimerA1Init(void){

    TA1CTL  = TASSEL__SMCLK | MC__UP | TACLR;

    TA1CCR0 = 41667;  //SMCLK_FREQU Timer 2500000 /60 Hz - wie viel Schritte sind in einem Period

    TA1CCTL1 = OUTMOD_7; //Reset-set

    TA1CCR1  = 2500;  //1/2500000=0,4 micros; (1 ms = 1000micros)/0,4=2500 ticks dauert 1ms; 5000 - 2ms, 2500+5000=3750 dauert 1.5 ms

    TA1CCTL2 = OUTMOD_7;

    TA1CCR2  = 8000;


    P3DIR |= BIT2 | BIT3;

    P3SEL |= BIT2 | BIT3;
}
