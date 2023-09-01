// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _LCD_INCLOUDED
	#define _LCD_INCLOUDED


#include "Utility.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "stm32f1xx_hal.h"

#ifndef _LCD_PORT
	#define _LCD_PORT
		
	#define RS_PORT  			GPIOB
	#define RS_PIN  			0
	#define RW_PORT  			GPIOB
	#define RW_PIN  			1
	#define EN_PORT  			GPIOB
	#define EN_PIN  			2
		
	#define D4_PORT  			GPIOA
	#define D4_PIN  			4
	#define D5_PORT  			GPIOA
	#define D5_PIN  			5
	#define D6_PORT  			GPIOA
	#define D6_PIN  			6
	#define D7_PORT  			GPIOA
	#define D7_PIN  			7
#endif

#define _CLEAR_DISPLAY  0x01 // Clear display command
#define _RETURN_HOME    0x02 // Return home command

#define _DISPLAY_POS		2
#define DISPLAY_OFF			0
#define DISPLAY_ON			1

#define _CURSOR_POS			1
#define CURSOR_OFF			0
#define CURSOR_ON				1

#define _BLINK_POS			0
#define BLINK_OFF				0
#define BLINK_ON				1

#define _INTERFACE_POS	4
#define INTERFACE_4BIT	0
#define INTERFACE_8BIT	1

#define _LINE_POS				3
#define LINE_SINGLE			0
#define LINE_DUAL				1


#define _REGISTER_INSTRUCTION		0
#define _REGISTER_DATA					1
#define _SelectInstructionOrDataRegisterForLCD(MODE) \
	WritePinFromOutput(RS_PORT,RS_PIN,MODE&0b1);
	
#define _OPERATION_WRITE	0
#define _OPERATION_READ		1
#define _SelectWriteOrReadModeForLCD(MODE) \
	WritePinFromOutput(RW_PORT,RW_PIN,MODE&0b1);

void _LCD_Write_4BitMode(unsigned char data);
void LCD_PutCommand(unsigned char data);
void ConfigureDisplayStatus(char status);
void ConfigureCursorStatus(char status);
void ConfigureBlinkingCursorStatus(char status);
void ConfigureInterfaceDataLength(char mode);
void ConfigureLine(char mode);
void lcd_clear(void);
void lcd_gotoxy(unsigned char x, unsigned char y);
void lcd_init(void);
void lcd_PutChar(char data);
void lcd_PutString(char *str);
void lcd_PutStringFromFlash(const char *str);

static char _interface_line_=(0b00100000 | (INTERFACE_4BIT<<_INTERFACE_POS) | (LINE_DUAL<<_LINE_POS));
#define ConfigureLine_(MODE) \
	WriteBit(_interface_line_,_LINE_POS,(MODE&0b1));\
	LCD_PutCommand(_interface_line_);
	
#endif
