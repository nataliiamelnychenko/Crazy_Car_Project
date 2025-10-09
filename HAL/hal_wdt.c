#include <msp430.h>
#include "hal_wdt.h"


void hal_WdtInit(void)
{
    WDTCTL = WDTPW | WDTHOLD;
}
