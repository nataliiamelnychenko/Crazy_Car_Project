#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#define RPM_SENSOR BIT3 //in
#define RPM_SENSOR_DIR BIT4 //in
#define LCD_BL BIT0 //out
#define START_BUTTON BIT7 //in
#define STOP_BUTTON BIT6 //in





//eine Datenstruktur definieren:
typedef struct {
    unsigned char active; // TRUE = 1 / FALSE = 0
    unsigned char button; // Button number
} ButtonCom;

void hal_GpioInit(void);


#endif
