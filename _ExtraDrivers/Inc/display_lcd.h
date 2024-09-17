// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_hal.h>
#include <utility.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>

#ifndef _LCD_INCLOUDED
#define _LCD_INCLOUDED

#ifdef __cplusplus
extern "C" {
#endif


#ifndef _LCD_PORT
	#define _LCD_PORT
		
	#define RS_PORT  			GPIOB
	#define RS_PIN  			0
	#define RW_PORT  			GPIOB
	#define RW_PIN  			1
	#define EN_PORT  			GPIOB
	#define EN_PIN  			2

	#define D7_PORT  			GPIOA
	#define D7_PIN  			7
	#define D6_PORT  			GPIOA
	#define D6_PIN  			6
	#define D5_PORT  			GPIOA
	#define D5_PIN  			5
	#define D4_PORT  			GPIOA
	#define D4_PIN  			4
#endif
	
void LCD_PutCommand(unsigned char data);
void LCD_SetOnOff(char status);
void LCD_Cursor_SetOnOff(char status);
void LCD_BlinkingCursor_SetOnOff(char status);
void LCD_InterfaceDataLength_Set4BitOr8Bit(char mode);
void LCD_SetLine(char mode);
void LCD_ClearDisplay(void);
void LCD_GoToXY(unsigned char x, unsigned char y);
void LCD_Configuration(void);
void LCD_PutChar(char data);
void LCD_PutString(char *str);
void LCD_PutStringFromFlash(const char *str);

#define lcd_clear()				LCD_ClearDisplay()
#define lcd_gotoxy(x,y)		LCD_GoToXY(x,y)
#define lcd_putchar(c)   	LCD_PutChar(c)
#define lcd_puts(str)   	LCD_PutString(str)
#define lcd_putsf(str)    LCD_PutStringFromFlash(str)
#define lcd_init()				LCD_Configuration()

#ifdef __cplusplus
}
#endif

#endif	// _LCD_INCLOUDED
