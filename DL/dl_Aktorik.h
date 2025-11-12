#ifndef DL_AKTORIK_H
#define DL_AKTORIK_H

#include <stdint.h>

#define Throttle_min 2500
#define Throttle_neutral 3750
#define Throttle_max 5000

void dl_SteeringInit(void);
void dl_ThrottleInit(void);
void dl_SetSteering(int8_t iValue);
void dl_SetThrottle(int8_t iValue);

#endif
