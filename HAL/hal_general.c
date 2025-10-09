#include "hal_general.h"
#include "hal_pmm.h"
#include "hal_wdt.h"
#include "hal_gpio.h"

void hal_Init(void)
{
    hal_WdtInit();
    HAL_PMM_Init();
    hal_GpioInit();
}
