// GitHub Account: GitHub.com/AliRezaJoodi

#include <display_lcd_bm.h>

static uint8_t _display_cursor_blinking=0b00001000;
static uint8_t _interface_line=0b00100000;

#define _LCD_DataPins_ConfigForOutputMode \
	GPIO_OutputWithPushPullMode_ConfigPin(LCD_D7_GPIO, LCD_D7_PIN);\
	GPIO_OutputWithPushPullMode_ConfigPin(LCD_D6_GPIO, LCD_D6_PIN);\
	GPIO_OutputWithPushPullMode_ConfigPin(LCD_D5_GPIO, LCD_D5_PIN);\
	GPIO_OutputWithPushPullMode_ConfigPin(LCD_D4_GPIO, LCD_D4_PIN);	

#define _LCD_DataPins_ConfigForInputMode \
	GPIO_InputWithFloatingMode_ConfigPin(LCD_D7_GPIO, LCD_D7_PIN);\
	GPIO_InputWithFloatingMode_ConfigPin(LCD_D6_GPIO, LCD_D6_PIN);\
	GPIO_InputWithFloatingMode_ConfigPin(LCD_D5_GPIO, LCD_D5_PIN);\
	GPIO_InputWithFloatingMode_ConfigPin(LCD_D4_GPIO, LCD_D4_PIN);

//#define _RS_IR		0
//#define _RS_DR		1
//#define _SetRegisterSelectorPin(MODE) \
//	GPIO_WritePin(LCD_RS_GPIO,LCD_RS_PIN, MODE);
//	
//#define _RW_WRITE		0
//#define _RW_READ		1
//#define _SetReadOrWritePin(MODE) \
//	GPIO_WritePin(LCD_RW_GPIO,LCD_RW_PIN, MODE);

#define _IR_WRITE		0b00	// IR write as an internal operation (display clear, etc.)
#define _BF_READ		0b01	// Read busy flag (DB7) and address counter (DB0 to DB7)
#define _DR_WRITE		0b10	// Write data to DDRAM or CGRAM (DR to DDRAM or CGRAM)
#define _DR_READ		0b11	// Read data from DDRAM or CGRAM (DDRAM or CGRAM to DR)

//********************************
void _SetOperationMode(uint32_t mode){
	mode=mode&0b11;
	
	GPIO_WritePin(LCD_RS_GPIO,LCD_RS_PIN, GetBit(mode,1));
	
	#ifdef LCD_RW_PIN
		GPIO_WritePin(LCD_RW_GPIO,LCD_RW_PIN, GetBit(mode,0));
	#endif
}

//********************************
void _4BitInterface_WaitForReady(void){
	uint8_t busy_flag=1;
	_LCD_DataPins_ConfigForInputMode;
	_SetOperationMode(_BF_READ);
	__NOP();	//Min: 40ns
	
	do{
		GPIO_SetPin(LCD_EN_GPIO, LCD_EN_PIN); 
		__NOP(); __NOP();	// Min: 230ns
		busy_flag = GPIO_GetPin(LCD_D7_GPIO,LCD_D7_PIN);
		GPIO_ResetPin(LCD_EN_GPIO, LCD_EN_PIN); 
		__NOP(); __NOP();	// Min: 230ns
	
		GPIO_SetPin(LCD_EN_GPIO, LCD_EN_PIN);
		__NOP(); __NOP();	// Min: 230ns
		GPIO_ResetPin(LCD_EN_GPIO, LCD_EN_PIN); 
		__NOP(); __NOP();	// Min: 230ns
	} while(busy_flag != 0);
	__NOP(); // Min: 10ns
	
	_LCD_DataPins_ConfigForOutputMode;
}

//********************************
void _4BitInterface_Write4Bit(uint8_t data){		
	GPIO_WritePin(LCD_D7_GPIO, LCD_D7_PIN, GetBit(data&0xF,3));
	GPIO_WritePin(LCD_D6_GPIO, LCD_D6_PIN, GetBit(data&0xF,2));
	GPIO_WritePin(LCD_D5_GPIO, LCD_D5_PIN, GetBit(data&0xF,1));
	GPIO_WritePin(LCD_D4_GPIO, LCD_D4_PIN, GetBit(data&0xF,0));
	
	GPIO_SetPin(LCD_EN_GPIO, LCD_EN_PIN);
	__NOP(); __NOP();	// Min: 230ns
	GPIO_ResetPin(LCD_EN_GPIO, LCD_EN_PIN);
	__NOP(); __NOP();	// Min: 230ns
}

//********************************
//void _4BitInterface_Write8Bit(unsigned char data){		
//	GPIO_WritePin(LCD_D7_GPIO, LCD_D7_PIN, GetBit(data,7));
//	GPIO_WritePin(LCD_D6_GPIO, LCD_D6_PIN, GetBit(data,6));
//	GPIO_WritePin(LCD_D5_GPIO, LCD_D5_PIN, GetBit(data,5));
//	GPIO_WritePin(LCD_D4_GPIO, LCD_D4_PIN, GetBit(data,4));
//	
//	GPIO_SetPin(LCD_EN_GPIO, LCD_EN_PIN);
//	__NOP(); __NOP();	// Min: 230ns
//	GPIO_ResetPin(LCD_EN_GPIO, LCD_EN_PIN);
//	__NOP(); __NOP();	// Min: 230ns
//	
//	GPIO_WritePin(LCD_D7_GPIO, LCD_D7_PIN, GetBit(data,3));
//	GPIO_WritePin(LCD_D6_GPIO, LCD_D6_PIN, GetBit(data,2));
//	GPIO_WritePin(LCD_D5_GPIO, LCD_D5_PIN, GetBit(data,1));
//	GPIO_WritePin(LCD_D4_GPIO, LCD_D4_PIN, GetBit(data,0));
//	
//	GPIO_SetPin(LCD_EN_GPIO, LCD_EN_PIN); 
//	__NOP(); __NOP();	// Min: 230ns
//	GPIO_ResetPin(LCD_EN_GPIO, LCD_EN_PIN); 
//	__NOP(); __NOP();	// Min: 230ns
//}

//********************************
void LCD_PutCommand(uint8_t data){
	#ifdef LCD_RW_PIN
		_4BitInterface_WaitForReady();
	#else
		SysTick_Delay_1ms(2);
	#endif

	_SetOperationMode(_IR_WRITE);
	__NOP(); // Min: 40ns
	//_4BitInterface_Write8Bit(data);
	_4BitInterface_Write4Bit(data>>4);
	_4BitInterface_Write4Bit(data&0xF);	
}

/*
Instruction table:
0b00001xxx:	Display ON/OFF Control
Bit2:				Set display, On=1, Off=0
*/

//********************************
void LCD_Display_SetOnOff(uint8_t status){
	WriteBit(_display_cursor_blinking, 2, status);
	LCD_PutCommand(_display_cursor_blinking);
	SysTick_Delay_1us(50);		//Min: 39us
}

/*
Instruction table:
0b00001xxx:	Display ON/OFF Control
Bit1:				Set Cursor, On=1, Off=0
*/

//********************************
void LCD_Cursor_SetOnOff(uint8_t status){
	WriteBit(_display_cursor_blinking, 1, status);
	LCD_PutCommand(_display_cursor_blinking);
	SysTick_Delay_1us(50);		//Min: 39us
}

/*
Instruction table:
0b00001xxx:	Display ON/OFF Control
Bit0:				Set blinking of cursor, On=1, Off=0
*/

//********************************
void LCD_Cursor_SetBlinking(uint8_t status){
	WriteBit(_display_cursor_blinking, 0, status);
	LCD_PutCommand(_display_cursor_blinking);
	SysTick_Delay_1us(50);		//Min: 39us
}

//********************************
void LCD_Cursor_SetXY(uint8_t x, uint8_t y){
	const unsigned char address[4]={0x80,0xC0,0x94,0xD4};
	LCD_PutCommand(address[y]+x);
	SysTick_Delay_1us(50);		//Min: 39us
}

/*
Instruction table:
0b001xxx00:	Function Set
Bit4:				Set interface data length, 8-bit=1, 4-bit=0
*/

#define LCD_4BIT	0
#define LCD_8BIT	1

//********************************
void LCD_Interface_Set4BitOr8Bit(uint8_t mode){
	WriteBit(_interface_line, 4, mode);
	LCD_PutCommand(_interface_line);
	SysTick_Delay_1us(50);		//Min: 39us
}

/*
Instruction table:
0b001xxx00:	Function Set
Bit3:				Numbers of display line, 2-line=1, 1-line=0
*/

#define LCD_1LINE			0
#define LCD_2LINE			1

//********************************
void LCD_Line_Set1LineOr2Line(uint8_t mode){
	WriteBit(_interface_line, 3, mode);
	LCD_PutCommand(_interface_line);
	SysTick_Delay_1us(50);		//Min: 39us
}

/*
Instruction table:
0b001xxx00:	Function Set
Bit2:				Display font type, 5x11 dots = 1, 5x8 dots = 0
*/

#define LCD_5x8DOT			0
#define LCD_5x11DOT			1

//********************************
void LCD_Font_Set5x8DotOr5x11Dot(char mode){
	WriteBit(_interface_line, 2, mode);
	LCD_PutCommand(_interface_line);
	SysTick_Delay_1us(50);		//Min: 39us
}

/*
Instruction table:
0b00000010:	Return Home
*/
//********************************
void LCD_Cursor_ReturnHome(void){
	LCD_PutCommand(0x2); 
	SysTick_Delay_1ms(2);		// Min: 1.53ms
}

/*
Instruction table:
0b00000001:	Clear Display	
*/
//********************************
void LCD_Display_Clear(void){
	LCD_PutCommand(0x1);
	SysTick_Delay_1ms(2);		// Min: 1.53ms
	//LCD_Cursor_ReturnHome();
}

//********************************
void LCD_PutChar(char data){
	#ifdef LCD_RW_PIN
		_4BitInterface_WaitForReady();
	#else
		SysTick_Delay_1ms(2);
	#endif
	
	_SetOperationMode(_DR_WRITE);
  //_4BitInterface_Write8Bit(data);
	_4BitInterface_Write4Bit(data>>4);
	_4BitInterface_Write4Bit(data&0xF);
	SysTick_Delay_1us(50);		//Min: 43us
}

//********************************
void LCD_PutString(char *str){
  while(*str != 0){
		LCD_PutChar(*str);
    ++str;
  }
}

//********************************
void LCD_PutStringFromFlash(const char *str){
  while(*str != 0){
		LCD_PutChar(*str);
    ++str;
  }
}

//********************************
void LCD_Config(void){
	BUS_GPIOx_EnableOrDisableWithAutoSearch(LCD_RS_GPIO);
	GPIO_OutputWithPushPullMode_ConfigPin(LCD_RS_GPIO, LCD_RS_PIN);
	
	#ifdef LCD_RW_PIN
		BUS_GPIOx_EnableOrDisableWithAutoSearch(LCD_RW_GPIO);
		GPIO_OutputWithPushPullMode_ConfigPin(LCD_RW_GPIO, LCD_RW_PIN);
	#endif
	
	BUS_GPIOx_EnableOrDisableWithAutoSearch(LCD_EN_GPIO);
	GPIO_OutputWithPushPullMode_ConfigPin(LCD_EN_GPIO, LCD_EN_PIN);
	
	BUS_GPIOx_EnableOrDisableWithAutoSearch(LCD_D4_GPIO);
	GPIO_OutputWithPushPullMode_ConfigPin(LCD_D4_GPIO, LCD_D4_PIN);
	
	BUS_GPIOx_EnableOrDisableWithAutoSearch(LCD_D5_GPIO);
	GPIO_OutputWithPushPullMode_ConfigPin(LCD_D5_GPIO, LCD_D5_PIN);
	
	BUS_GPIOx_EnableOrDisableWithAutoSearch(LCD_D6_GPIO);
	GPIO_OutputWithPushPullMode_ConfigPin(LCD_D6_GPIO, LCD_D6_PIN);
	
	BUS_GPIOx_EnableOrDisableWithAutoSearch(LCD_D7_GPIO);
	GPIO_OutputWithPushPullMode_ConfigPin(LCD_D7_GPIO, LCD_D7_PIN);

	SysTick_Delay_1ms(50);
	
	_SetOperationMode(_IR_WRITE);
	
	_4BitInterface_Write4Bit(0x3);	
	SysTick_Delay_1ms(5);		// Min: 4.1 ms
	
	_4BitInterface_Write4Bit(0x3);
	SysTick_Delay_1ms(1);		// Min: 100 �s
	
	_4BitInterface_Write4Bit(0x3);
	SysTick_Delay_1ms(1);
	
	_4BitInterface_Write4Bit(0x2);
	SysTick_Delay_1ms(1);
	
	LCD_Interface_Set4BitOr8Bit(LCD_4BIT);
	LCD_Line_Set1LineOr2Line(LCD_2LINE);
	LCD_Font_Set5x8DotOr5x11Dot(LCD_5x8DOT);
	
	LCD_Display_SetOnOff(0);
	LCD_Display_Clear();
	LCD_Cursor_SetOnOff(0);
	LCD_Cursor_SetBlinking(0);
	
	LCD_Display_SetOnOff(1);
}

//********************************
void LCD_DefineChar(uint8_t charmap[], uint8_t location){
	location= location & 0x7;
	LCD_PutCommand(0x40 | (location<<3));
  for (uint8_t i=0; i<8; i++) {
		LCD_PutChar(charmap[i]);
  }
}

const uint8_t char0[8]={
	0b01000,
  0b10100,
  0b01000,
  0b00011,
  0b00100,
  0b00100,
  0b00011,
  0b00000
};  //^c

const uint8_t char1[8]={
  0b10001000,
  0b10010100,
  0b10000000,
  0b10000100,
  0b10000101,
  0b10000110,
  0b10000101,
  0b10000000
};  //^k

const uint8_t char2[8]={
  0b10000111,
  0b10000101,
  0b10000111,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000
};  //^



