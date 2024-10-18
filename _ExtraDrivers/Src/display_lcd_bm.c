// GitHub Account: GitHub.com/AliRezaJoodi

#include <display_lcd_bm.h>

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

static unsigned char _display_cursor_bink=(0b00001000 | (DISPLAY_ON<<_DISPLAY_POS) | (CURSOR_OFF<<_CURSOR_POS) | (BLINK_OFF<<_BLINK_POS));
static unsigned char _interface_line=(0b00100000 | (INTERFACE_4BIT<<_INTERFACE_POS) | (LINE_DUAL<<_LINE_POS));

#define _LCD_DataPins_ConfigForOutputMode \
	GPIO_ConfigPinForPushPullOutputMode(D7_GPIO, D7_PIN);\
	GPIO_ConfigPinForPushPullOutputMode(D6_GPIO, D6_PIN);\
	GPIO_ConfigPinForPushPullOutputMode(D5_GPIO, D5_PIN);\
	GPIO_ConfigPinForPushPullOutputMode(D4_GPIO, D4_PIN);	

#define _LCD_DataPins_ConfigForInputMode \
	GPIO_ConfigPinForFloatingInputMode(D7_GPIO, D7_PIN);\
	GPIO_ConfigPinForFloatingInputMode(D6_GPIO, D6_PIN);\
	GPIO_ConfigPinForFloatingInputMode(D5_GPIO, D5_PIN);\
	GPIO_ConfigPinForFloatingInputMode(D4_GPIO, D4_PIN);

#define _RS_IR		0
#define _RS_DR		1
#define _SetRegisterSelectorPin(MODE) \
	GPIO_WritePin(RS_GPIO,RS_PIN, MODE);
	
#define _RW_WRITE		0
#define _RW_READ		1
#define _SetReadOrWritePin(MODE) \
	GPIO_WritePin(RW_GPIO,RW_PIN, MODE);

#define _IR_WRITE		0b00	// IR write as an internal operation (display clear, etc.)
#define _BF_READ		0b01	// Read busy flag (DB7) and address counter (DB0 to DB7)
#define _DR_WRITE		0b10	// Write data to DDRAM or CGRAM (DR to DDRAM or CGRAM)
#define _DR_READ		0b11	// Read data from DDRAM or CGRAM (DDRAM or CGRAM to DR)
#define _SetOperationMode(MODE) \
	GPIO_WritePin(RS_GPIO,RS_PIN, GetBit(MODE,1));\
	GPIO_WritePin(RW_GPIO,RW_PIN, GetBit(MODE,0));

//********************************
void _LCD_Ready(void){
	volatile char busy_flag=1;
	_LCD_DataPins_ConfigForInputMode;
	_SetOperationMode(_BF_READ);
	__NOP();	//Min: 40ns
	
	do{
		GPIO_SetPin(EN_GPIO, EN_PIN); 
		__NOP(); __NOP();	// Min: 230ns
		busy_flag = GPIO_GetPin(D7_GPIO,D7_PIN);
		GPIO_ResetPin(EN_GPIO, EN_PIN); 
		__NOP(); __NOP();	// Min: 230ns
	
		GPIO_SetPin(EN_GPIO, EN_PIN);
		__NOP(); __NOP();	// Min: 230ns
		GPIO_ResetPin(EN_GPIO, EN_PIN); 
		__NOP(); __NOP();	// Min: 230ns
	} while(busy_flag!=0);
	__NOP(); // Min: 10ns
	_LCD_DataPins_ConfigForOutputMode;
}

//********************************
void _LCD_Write_4BitMode(unsigned char data){		
	GPIO_WritePin(D7_GPIO, D7_PIN, GetBit(data,7));
	GPIO_WritePin(D6_GPIO, D6_PIN, GetBit(data,6));
	GPIO_WritePin(D5_GPIO, D5_PIN, GetBit(data,5));
	GPIO_WritePin(D4_GPIO, D4_PIN, GetBit(data,4));
	
	GPIO_SetPin(EN_GPIO, EN_PIN);
	__NOP(); __NOP();	// Min: 230ns
	GPIO_ResetPin(EN_GPIO, EN_PIN);
	__NOP(); __NOP();	// Min: 230ns
	
	GPIO_WritePin(D7_GPIO, D7_PIN, GetBit(data,3));
	GPIO_WritePin(D6_GPIO, D6_PIN, GetBit(data,2));
	GPIO_WritePin(D5_GPIO, D5_PIN, GetBit(data,1));
	GPIO_WritePin(D4_GPIO, D4_PIN, GetBit(data,0));
	
	GPIO_SetPin(EN_GPIO, EN_PIN); 
	__NOP(); __NOP();	// Min: 230ns
	GPIO_ResetPin(EN_GPIO, EN_PIN); 
	__NOP(); __NOP();	// Min: 230ns
}

//********************************
void _LCD_PutCommand(uint8_t data){
	_LCD_Ready();
	_SetOperationMode(_IR_WRITE);
	__NOP(); // Min: 40ns
	_LCD_Write_4BitMode(data); 
}

//********************************
void LCD_Display_SetOnOff(char status){
	WriteBit(_display_cursor_bink, _DISPLAY_POS, status);
	_LCD_PutCommand(_display_cursor_bink);
	SysTick_Delay_1us(39);
	///Delay_us(40); //Min: 39us
}

//********************************
void LCD_Cursor_SetOnOff(char status){
	WriteBit(_display_cursor_bink, _CURSOR_POS, status);
	_LCD_PutCommand(_display_cursor_bink);
	SysTick_Delay_1us(39);
	///Delay_us(40); //Min: 39us
}

//********************************
void LCD_Cursor_SetBlinking(char status){
	WriteBit(_display_cursor_bink, _BLINK_POS, status);
	_LCD_PutCommand(_display_cursor_bink);
	SysTick_Delay_1us(39);
	///Delay_us(40); //Min: 39us
}

//********************************
void LCD_InterfaceDataLength_Set4BitOr8Bit(char mode){
	WriteBit(_interface_line, _INTERFACE_POS, mode);
	_LCD_PutCommand(_interface_line);
	SysTick_Delay_1us(39);
	///Delay_us(40); //Min: 39us
}

//********************************
void _LCD_SetLine(char mode){
	WriteBit(_interface_line, _LINE_POS, mode);
	_LCD_PutCommand(_interface_line);
	SysTick_Delay_1us(39);
	///Delay_us(40); //Min: 39us
}

//********************************
void LCD_Cursor_SetXY(uint8_t x, uint8_t y){
	const unsigned char address[4]={0x80,0xC0,0x94,0xD4};
	_LCD_PutCommand(address[y]+x);
	SysTick_Delay_1us(39);
	///Delay_us(40); //Min: 39us
}

//********************************
void LCD_Display_Clear(void){
	_LCD_PutCommand(_CLEAR_DISPLAY);
	SysTick_Delay_1us(1530);	
	///Delay_ms(2);	// Min: 1.53ms
	_LCD_PutCommand(_RETURN_HOME); 
	SysTick_Delay_1us(1530);
	///Delay_ms(2);	// Min: 1.53ms
}

//********************************
void LCD_PutChar(char data){
	_LCD_Ready();
	_SetOperationMode(_DR_WRITE);
  _LCD_Write_4BitMode(data); 
	SysTick_Delay_1us(43);
	///Delay_us(50); //Min: 43us
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
	BUS_GPIOx_EnableOrDisableWithAutoSearch(RS_GPIO);
	BUS_GPIOx_EnableOrDisableWithAutoSearch(RW_GPIO);
	BUS_GPIOx_EnableOrDisableWithAutoSearch(EN_GPIO);
	BUS_GPIOx_EnableOrDisableWithAutoSearch(D4_GPIO);
	BUS_GPIOx_EnableOrDisableWithAutoSearch(D5_GPIO);
	BUS_GPIOx_EnableOrDisableWithAutoSearch(D6_GPIO);
	BUS_GPIOx_EnableOrDisableWithAutoSearch(D7_GPIO);

	GPIO_ConfigPinForPushPullOutputMode(RS_GPIO, RS_PIN);	
	GPIO_ConfigPinForPushPullOutputMode(RW_GPIO, RW_PIN);
	GPIO_ConfigPinForPushPullOutputMode(EN_GPIO, EN_PIN);
	_LCD_DataPins_ConfigForOutputMode;
	
	SysTick_Delay_1ms(40);
	///Delay_ms(40);
	
	_LCD_PutCommand(_RETURN_HOME); 
	SysTick_Delay_1us(1530);
	///Delay_ms(2);	// Min: 1.53ms
	
	_LCD_PutCommand(_interface_line);
	SysTick_Delay_1us(39);
	///Delay_us(40); //Min: 39us
	
	_LCD_PutCommand(_display_cursor_bink);
	SysTick_Delay_1us(39);
	///Delay_us(40); //Min: 39us
	
	_LCD_PutCommand(_CLEAR_DISPLAY); 
	SysTick_Delay_1us(1530);
	///Delay_ms(2);	// 1.53ms
	
	_LCD_PutCommand(_RETURN_HOME); 
	SysTick_Delay_1us(1530);
	///Delay_ms(2);	// 1.53ms
}




