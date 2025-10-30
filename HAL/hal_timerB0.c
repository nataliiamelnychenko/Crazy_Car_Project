
#include <msp430.h>
#include "hal_timerB0.h"
#include "hal_gpio.h"

void hal_TimerB0Init(void)
{
    unsigned long f_tick  = (unsigned long)SMCLK_FREQU / (TB0_ID_DIV * TB0_EX_DIV);
    unsigned long ticks   = f_tick / TB0_TOGGLE_FREQ_HZ;
    if (ticks == 0) ticks = 1;
    unsigned int ccr0_val = (unsigned int)(ticks - 1);

    TB0CTL  = TBSSEL_2 | ID_3 | MC_1 | TBCLR;

    TB0EX0  = TBIDEX_4;

    TB0CCR0  = ccr0_val;

    TB0CCTL0 = CCIE;

    TB0CTL  |= MC__UP;
}


#pragma vector = TIMERB0_VECTOR
__interrupt void TB0_CCR0_ISR(void)
{
            LCD_BL_TOGGLE();
}
