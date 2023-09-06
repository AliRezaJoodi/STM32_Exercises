// GitHub Account: GitHub.com/AliRezaJoodi

#include "stm32f1xx_hal.h"
#include "Utility.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"

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
	GPIO_WritePin(RS_PORT,RS_PIN,MODE);
	
#define _OPERATION_WRITE	0
#define _OPERATION_READ		1
#define _SelectWriteOrReadModeForLCD(MODE) \
	GPIO_WritePin(RW_PORT,RW_PIN,MODE);

#define _INSTRUCTION_WRITE	0b00
#define _INSTRUCTION_READ		0b01
#define _DATA_WRITE					0b10
#define _DATA_READ					0b11
#define _LCD_SelectOperationMode(MODE) \
	GPIO_WritePin(RS_PORT,RS_PIN,GetBit(MODE,1));\
	GPIO_WritePin(RW_PORT,RW_PIN,GetBit(MODE,0));
	
void LCD_PutCommand(unsigned char data);
void LCD_ConfigureDisplayStatus(char status);
void LCD_ConfigureCursorStatus(char status);
void LCD_ConfigureBlinkingCursorStatus(char status);
void LCD_ConfigureInterfaceDataLength(char mode);
void LCD_ConfigureLine(char mode);
void LCD_ClearDisplay(void);
void LCD_GoToXY(unsigned char x, unsigned char y);
void LCD_ConfigureDefaultMode(void);
void LCD_PutChar(char data);
void LCD_PutString(char *str);
void LCD_PutStringFromFlash(const char *str);

#define lcd_clear()				LCD_ClearDisplay()
#define lcd_gotoxy(x,y)		LCD_GoToXY(x,y)
#define lcd_putchar(c)   	LCD_PutChar(c)
#define lcd_puts(str)   	LCD_PutString(str)
#define lcd_putsf(str)    LCD_PutStringFromFlash(str)
#define lcd_init()				LCD_ConfigureDefaultMode()

#ifdef __cplusplus
}
#endif

#endif
