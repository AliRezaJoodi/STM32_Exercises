// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

/*
Abbreviations:
	RS (LCD pin): 				Register Selector
	RW (LCD pin): 				Read/Write
	IR (8-Bit Register):	Instruction Register
	DR (8-Bit Register):	Data Register
	BF:										Busy Flag
	AC: 									Address Counter
	DDRAM:								Display Data RAM
	CGRAM:								Character Generator RAM
*/

#ifndef _LCD_INCLOUDED
#define _LCD_INCLOUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f1xx.h>

#include <utility.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_timer_systick.h>
///#include <delay_nop.h>

#ifdef HARDWARE_LOCAL
	#include "_hardware.h"
#endif

#ifndef LCD_HARDWARE
#define LCD_HARDWARE	
	#define RS_GPIO  			GPIOA
	#define RS_PIN  			0
	#define RW_GPIO  			GPIOA		// Optional
	#define RW_PIN  			1				// Optional
	#define EN_GPIO  			GPIOA
	#define EN_PIN  			2

	#define D4_GPIO  			GPIOA
	#define D4_PIN  			4
	#define D5_GPIO  			GPIOA
	#define D5_PIN  			5
	#define D6_GPIO  			GPIOA
	#define D6_PIN  			6	
	#define D7_GPIO  			GPIOA
	#define D7_PIN  			7
#endif

	
//***********************************************
void LCD_Config(void);
void LCD_Interface_Set4BitOr8Bit(uint8_t mode);
void LCD_Line_Set1LineOr2Line(uint8_t mode);
void LCD_Font_Set5x8DotOr5x11Dot(char mode);
void LCD_Display_SetOnOff(uint8_t status);
void LCD_Display_Clear(void);
void LCD_Cursor_ReturnHome(void);
void LCD_Cursor_SetXY(uint8_t x, uint8_t y);
void LCD_Cursor_SetOnOff(uint8_t status);
void LCD_Cursor_SetBlinking(uint8_t status);
void LCD_PutCommand(uint8_t data);
void LCD_PutChar(char data);
void LCD_PutString(char *str);
void LCD_PutStringFromFlash(const char *str);
void LCD_DefineChar(uint8_t charmap[], uint8_t location);

#define lcd_init()					LCD_Config()
#define lcd_clear()					LCD_Display_Clear()
#define lcd_gotoxy(x,y)			LCD_Cursor_SetXY(x,y)
#define lcd_putchar(c)   		LCD_PutChar(c)
#define lcd_puts(str)   		LCD_PutString(str)
#define lcd_putsf(str)    	LCD_PutStringFromFlash(str)

#ifdef __cplusplus
}
#endif

#endif	// _LCD_INCLOUDED
