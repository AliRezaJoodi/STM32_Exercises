#ifndef LCD_LL_H
#define LCD_LL_H

#include "stm32f1xx_ll_gpio.h"

// Define the LCD pins (adjust according to your connections)
#define LCD_RS_PIN       LL_GPIO_PIN_0
#define LCD_EN_PIN       LL_GPIO_PIN_2
#define LCD_D4_PIN       LL_GPIO_PIN_4
#define LCD_D5_PIN       LL_GPIO_PIN_5
#define LCD_D6_PIN       LL_GPIO_PIN_6
#define LCD_D7_PIN       LL_GPIO_PIN_7
#define LCD_GPIO_PORT    GPIOA

// Function prototypes
void LCD_Init(void);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_Print(char *str);
void LCD_SendCommand(uint8_t cmd);
void LCD_SendData(uint8_t data);

#endif /* LCD_LL_H */
