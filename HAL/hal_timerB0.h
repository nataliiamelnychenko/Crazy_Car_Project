#ifndef HAL_TIMERB0_H
#define HAL_TIMERB0_H

#include "hal_ucs.h"

#define TB0_TOGGLE_FREQ_HZ  4u

#define TB0_ID_DIV     8u     // ID=/8  (ID_3)
#define TB0_EX_DIV     5u     // TBIDEX=/5 (TBIDEX_4)

void hal_TimerB0Init(void);

#endif
