#include "hal_general.h"
#include "hal_pmm.h"
#include "hal_wdt.h"
#include "hal_gpio.h"
#include "hal_ucs.h"
#include "hal_timerB0.h"

volatile ButtonCom buttonCom;    //die echte globale Variable (wird hier definiert)

void hal_Init(void)
{
    hal_WdtInit();
    HAL_PMM_Init();
    hal_GpioInit();
    hal_ucsInit();
    hal_TimerB0Init();
}
