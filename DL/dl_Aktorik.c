#include <msp430.h>
#include "dl_Aktorik.h"
#include "hal_timerA1.h"

static inline int clamp(int x, int lo, int hi) {
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}

static inline unsigned map_lin(int x, int in_min, int in_max, unsigned out_min, unsigned out_max) {
    long num = (long)(x - in_min) * (long)(out_max - out_min);
    return (unsigned)(out_min + num / (in_max - in_min));
}

void dl_SteeringInit(void) {
    TA1CCR2 = Servo_Mitte;
}

void dl_SetSteering(int8_t iValue) {
    int v = clamp(iValue, -100, 100);
    unsigned ticks;
    if (v >= 0)
        ticks = map_lin(v, 0, 100, Servo_Mitte, Servo_rechts);
    else
        ticks = map_lin(v, -100, 0, Servo_links, Servo_Mitte);
    TA1CCR2 = ticks;
}

void dl_ThrottleInit(void) {
    TA1CCR1 = Throttle_min;
    __delay_cycles(8000000);
    TA1CCR1 = Throttle_neutral;
}

void dl_SetThrottle(int8_t iValue) {
    int v = clamp(iValue, -100, 100);
    unsigned ticks;
    if (v >= 0)
        ticks = map_lin(v, 0, 100, Throttle_neutral, Throttle_max);
    else
        ticks = map_lin(v, -100, 0, Throttle_min, Throttle_neutral);
    TA1CCR1 = ticks;
}
