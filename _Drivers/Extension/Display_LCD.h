#ifndef _LCD_INCLOUDED
#define _LCD_INCLOUDED

#include "stm32f1xx_hal.h"

#define DATA_PORT  		GPIOA
#define D0_PIN_Start  04
#define D4_PIN  			GPIO_PIN_4
#define D5_PIN  			GPIO_PIN_5
#define D6_PIN  			GPIO_PIN_6
#define D7_PIN  			GPIO_PIN_7
#define CTRL_PORT  		GPIOB
#define RS_PIN  			0
#define RW_PIN  			1
#define EN_PIN  			2

void Cmd(uint8_t cmd);
void lcd_init(void);
void lcd_clear(void);
void lcd_gotoxy(unsigned char x, unsigned char y);
void lcd_puts(char *str);

#endif
