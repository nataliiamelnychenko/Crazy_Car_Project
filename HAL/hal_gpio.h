#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#define RPM_SENSOR BIT3 //in
#define RPM_SENSOR_DIR BIT4 //in
#define LCD_BL BIT0 //out
#define START_BUTTON BIT7 //in
#define STOP_BUTTON BIT6 //in

#define XT2IN_P7   BIT2  //Quarz in
#define XT2OUT_P7  BIT3  //Quarz out

#define LCD_BL_ON()      (P8OUT |=  LCD_BL)
#define LCD_BL_OFF()     (P8OUT &= ~LCD_BL)
#define LCD_BL_TOGGLE()  (P8OUT ^=  LCD_BL)



//eine Datenstruktur definieren:
typedef struct {
    unsigned char active; //True-1, false - 0
    unsigned char button; //Button nummer
} ButtonCom;

void hal_GpioInit(void);


#endif
