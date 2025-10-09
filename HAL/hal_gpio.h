#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#define RPM_SENSOR BIT3 //in
#define RPM_SENSOR_DIR BIT4 //in
#define I2C_INT_MOTION BIT5 //out
#define START_BUTTON BIT6 //in
#define STOP_BUTTON BIT7 //in

#define LCD_BL BIT0 //für Oscimessungen

void hal_GpioInit(void);

void lcd_bl_on(void);
void lcd_bl_off(void);
int calc_int(int a, int b);
void wait_in_us(int us);


#endif
