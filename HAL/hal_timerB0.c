
#include <msp430.h>
#include "hal_timerB0.h"
#include "hal_gpio.h"

void hal_TimerB0Init(void)
{
    unsigned long f_tick  = (unsigned long)SMCLK_FREQU / (TB0_ID_DIV * TB0_EX_DIV);
    unsigned long ticks   = f_tick / TB0_TOGGLE_FREQ_HZ;
    if (ticks == 0) ticks = 1;           //страховка
    unsigned int ccr0_val = (unsigned int)(ticks - 1);   //Up mode рахує

    //Вибір SMCLK, ID=/8, режим Up, скидання лічильника
    TB0CTL  = TBSSEL_2 | ID_3 | MC_1 | TBCLR;

    // /5
    TB0EX0  = TBIDEX_4;

    //Період і переривання CCR0
    TB0CCR0  = ccr0_val;
    TB0CCTL0 = CCIE;   //увімкнути переривання CCR0

    TB0CTL  |= MC__UP;
}

// Окремий вектор для CCR0:
#pragma vector = TIMERB0_VECTOR
__interrupt void TB0_CCR0_ISR(void)
{
    //перевірити/очистити правильний прапорець
   {
        LCD_BL_TOGGLE();        // макрос – вмик./вимик. підсвітку
    }
}
