#include "hal_ucs.h"

#include <msp430.h>

void hal_ucsInit(void)
{
    UCSCTL6 &= ~XT2OFF;             // XT2 einschalten
    UCSCTL3 |= SELREF_2;            // FLL Referenz = REFO
    UCSCTL4 |= SELA_2;              // ACLK = REFO

    // Warten bis Fehlerflags gelscht sind
    while (SFRIFG1 & OFIFG)
    {
        UCSCTL7 &= ~(XT2OFFG + DCOFFG + XT1HFOFFG + XT1LFOFFG);
        SFRIFG1 &= ~OFIFG;
    }

    UCSCTL6 &= ~(XT2DRIVE_3);       // Drive-Strength reduzieren (nach Anlauf)
    UCSCTL4 |= SELS_5 + SELM_5;     // SMCLK und MCLK = XT2
    UCSCTL5 |= DIVS_3;              // SMCLK Divider setzen (z. B. /8)
}
