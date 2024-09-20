// GitHub Account: GitHub.com/AliRezaJoodi

#include <display_lcd.h>

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

#define _LCD_SetPinForOutputMode(GPIOx,PIN); \
	GPIO_SetInputOrOutputMode(GPIOx,PIN, IO_OUTPUT);\
	GPIO_OutputMode_SetGeneralPurposeOrAlternateFunction(GPIOx,PIN, OUTPUT_GP);\
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOx,PIN, OUTPUT_PUSHPULL);

#define _LCD_SetPinForInputMode(GPIOx,PIN); \
	GPIO_SetInputOrOutputMode(GPIOx,PIN, IO_INPUT);\
	GPIO_InputMode_SetInputType(GPIOx,PIN, INPUT_FLOATING);

#define _LCD_ControlPins_Config \
	_LCD_SetPinForOutputMode(RS_GPIO, RS_PIN);\
	_LCD_SetPinForOutputMode(RW_GPIO, RW_PIN);\
	_LCD_SetPinForOutputMode(EN_GPIO, EN_PIN);

#define _LCD_DataPins_ConfigForOutputMode \
	_LCD_SetPinForOutputMode(D7_GPIO, D7_PIN);\
	_LCD_SetPinForOutputMode(D6_GPIO, D6_PIN);\
	_LCD_SetPinForOutputMode(D5_GPIO, D5_PIN);\
	_LCD_SetPinForOutputMode(D4_GPIO, D4_PIN);	

#define _LCD_DataPins_ConfigForInputMode \
	_LCD_SetPinForInputMode(D7_GPIO, D7_PIN);\
	_LCD_SetPinForInputMode(D6_GPIO, D6_PIN);\
	_LCD_SetPinForInputMode(D5_GPIO, D5_PIN);\
	_LCD_SetPinForInputMode(D4_GPIO, D4_PIN);

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
void _LCD_EnableBusForGPIO(void){
	if(	RS_GPIO	==	GPIOA || \
			RW_GPIO	==	GPIOA || \
			EN_GPIO	==	GPIOA || \
			D7_GPIO	==	GPIOA || \
			D6_GPIO	==	GPIOA || \
			D5_GPIO	==	GPIOA || \
			D4_GPIO	==	GPIOA)
		{BUS_GPIOA_EnableOrDisable(1);}

	if(	RS_GPIO	==	GPIOB || \
			RW_GPIO	==	GPIOB || \
			EN_GPIO	==	GPIOB || \
			D7_GPIO	==	GPIOB || \
			D6_GPIO	==	GPIOB || \
			D5_GPIO	==	GPIOB || \
			D4_GPIO	==	GPIOB)
		{BUS_GPIOB_EnableOrDisable(1);}

	if(	RS_GPIO	==	GPIOC || \
			RW_GPIO	==	GPIOC || \
			EN_GPIO	==	GPIOC || \
			D7_GPIO	==	GPIOC || \
			D6_GPIO	==	GPIOC || \
			D5_GPIO	==	GPIOC || \
			D4_GPIO	==	GPIOC)
		{BUS_GPIOC_EnableOrDisable(1);}

	if( RS_GPIO	==	GPIOD || \
			RW_GPIO	==	GPIOD || \
			EN_GPIO	==	GPIOD || \
			D7_GPIO	==	GPIOD || \
			D6_GPIO	==	GPIOD || \
			D5_GPIO	==	GPIOD || \
			D4_GPIO	==	GPIOD)
		{BUS_GPIOD_EnableOrDisable(1);}	
}

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
void LCD_PutCommand(unsigned char data){
	_LCD_Ready();
	_SetOperationMode(_IR_WRITE);
	__NOP(); // Min: 40ns
	_LCD_Write_4BitMode(data); 
}

//********************************
void LCD_SetOnOff(char status){
	WriteBit(_display_cursor_bink, _DISPLAY_POS, status);
	LCD_PutCommand(_display_cursor_bink);
	Delay_us(40); //Min: 39us
}

//********************************
void LCD_Cursor_SetOnOff(char status){
	WriteBit(_display_cursor_bink, _CURSOR_POS, status);
	LCD_PutCommand(_display_cursor_bink);
	Delay_us(40); //Min: 39us
}

//********************************
void LCD_BlinkingCursor_SetOnOff(char status){
	WriteBit(_display_cursor_bink, _BLINK_POS, status);
	LCD_PutCommand(_display_cursor_bink);
	Delay_us(40); //Min: 39us
}

//********************************
void LCD_InterfaceDataLength_Set4BitOr8Bit(char mode){
	WriteBit(_interface_line, _INTERFACE_POS, mode);
	LCD_PutCommand(_interface_line);
	Delay_us(40); //Min: 39us
}

//********************************
void LCD_SetLine(char mode){
	WriteBit(_interface_line, _LINE_POS, mode);
	LCD_PutCommand(_interface_line);
	Delay_us(40); //Min: 39us
}

//********************************
void LCD_GoToXY(unsigned char x, unsigned char y){
	const unsigned char address[4]={0x80,0xC0,0x94,0xD4};
	LCD_PutCommand(address[y]+x);
	Delay_us(40); //Min: 39us
}

//********************************
void LCD_ClearDisplay(void){
	LCD_PutCommand(_CLEAR_DISPLAY); 
	Delay_ms(2);	// Min: 1.53ms
	LCD_PutCommand(_RETURN_HOME); 
	Delay_ms(2);	// Min: 1.53ms
}

//********************************
void LCD_PutChar(char data){
	_LCD_Ready();
	_SetOperationMode(_DR_WRITE);
  _LCD_Write_4BitMode(data); 
	Delay_us(50); //Min: 43us
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
	_LCD_EnableBusForGPIO();
	_LCD_ControlPins_Config;
	_LCD_DataPins_ConfigForOutputMode;
	
	Delay_ms(40);
	
	LCD_PutCommand(_RETURN_HOME); 
	Delay_ms(2);	// Min: 1.53ms
	
	LCD_PutCommand(_interface_line);
	Delay_us(40); //Min: 39us
	
	LCD_PutCommand(_display_cursor_bink);
	Delay_us(40); //Min: 39us
	
	LCD_PutCommand(_CLEAR_DISPLAY); 
	Delay_ms(2);	// 1.53ms
	
	LCD_PutCommand(_RETURN_HOME); 
	Delay_ms(2);	// 1.53ms
}




