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

#define _LCD_SetPinForOutputMode(GPIOx, PIN); \
	GPIO_SetInputOrOutputMode(GPIOx, PIN, MODE_OUTPUT_2MHz);\
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOx, PIN, OUTPUT_GPIO);\
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOx, PIN, OUTPUT_PUSHPULL);

#define _LCD_SetPinForInputMode(GPIOx, PIN); \
	GPIO_SetInputOrOutputMode(GPIOx, PIN, MODE_INPUT);\
	GPIO_InputMode_SetInputType(GPIOx, PIN, INPUT_FLOATING);

#define _LCD_ControlPins_Configuration \
	_LCD_SetPinForOutputMode(RS_PORT, RS_PIN);\
	_LCD_SetPinForOutputMode(RW_PORT, RW_PIN);\
	_LCD_SetPinForOutputMode(EN_PORT, EN_PIN);

#define _LCD_DataPins_ConfigureForOutputMode \
	_LCD_SetPinForOutputMode(D7_PORT, D7_PIN);\
	_LCD_SetPinForOutputMode(D6_PORT, D6_PIN);\
	_LCD_SetPinForOutputMode(D5_PORT, D5_PIN);\
	_LCD_SetPinForOutputMode(D4_PORT, D4_PIN);	

#define _LCD_DataPins_ConfigureForInputMode \
	_LCD_SetPinForInputMode(D7_PORT, D7_PIN);\
	_LCD_SetPinForInputMode(D6_PORT, D6_PIN);\
	_LCD_SetPinForInputMode(D5_PORT, D5_PIN);\
	_LCD_SetPinForInputMode(D4_PORT, D4_PIN);

#define _REGISTER_INSTRUCTION		0
#define _REGISTER_DATA					1
#define _SetInstructionOrDataRegister(MODE) \
	GPIO_WritePin(RS_PORT, RS_PIN, MODE);
	
#define _OPERATION_WRITE	0
#define _OPERATION_READ		1
#define _SetWriteOrReadMode(MODE) \
	GPIO_WritePin(RW_PORT, RW_PIN, MODE);

#define _INSTRUCTION_WRITE	0b00
#define _INSTRUCTION_READ		0b01
#define _DATA_WRITE					0b10
#define _DATA_READ					0b11
#define _SetOperationMode(MODE) \
	GPIO_WritePin(RS_PORT, RS_PIN, GetBit(MODE,1));\
	GPIO_WritePin(RW_PORT, RW_PIN, GetBit(MODE,0));

//********************************
void _LCD_EnableBusForPorts(void){
	if(	RS_PORT	==	GPIOA || \
			RW_PORT	==	GPIOA || \
			EN_PORT	==	GPIOA || \
			D7_PORT	==	GPIOA || \
			D6_PORT	==	GPIOA || \
			D5_PORT	==	GPIOA || \
			D4_PORT	==	GPIOA)
		{BUS_GPIOA_EnableOrDisable(1);}

	if(	RS_PORT	==	GPIOB || \
			RW_PORT	==	GPIOB || \
			EN_PORT	==	GPIOB || \
			D7_PORT	==	GPIOB || \
			D6_PORT	==	GPIOB || \
			D5_PORT	==	GPIOB || \
			D4_PORT	==	GPIOB)
		{BUS_GPIOB_EnableOrDisable(1);}

	if(	RS_PORT	==	GPIOC || \
			RW_PORT	==	GPIOC || \
			EN_PORT	==	GPIOC || \
			D7_PORT	==	GPIOC || \
			D6_PORT	==	GPIOC || \
			D5_PORT	==	GPIOC || \
			D4_PORT	==	GPIOC)
		{BUS_GPIOC_EnableOrDisable(1);}

	if( RS_PORT	==	GPIOD || \
			RW_PORT	==	GPIOD || \
			EN_PORT	==	GPIOD || \
			D7_PORT	==	GPIOD || \
			D6_PORT	==	GPIOD || \
			D5_PORT	==	GPIOD || \
			D4_PORT	==	GPIOD)
		{BUS_GPIOD_EnableOrDisable(1);}	
}

//********************************
void _LCD_Delay(void){
  volatile unsigned char i=3; //5
	while(i!=0){i--;}
}

//********************************
void _LCD_Ready(void){
	volatile char busy_flag=1;
	_LCD_DataPins_ConfigureForInputMode;
	_SetOperationMode(_INSTRUCTION_READ);
	_LCD_Delay();
	
	do{
		GPIO_SetPin(EN_PORT, EN_PIN); _LCD_Delay();
		busy_flag = GPIO_GetPin(D7_PORT, D7_PIN);
		GPIO_ResetPin(EN_PORT, EN_PIN); _LCD_Delay();
	
		GPIO_SetPin(EN_PORT, EN_PIN); _LCD_Delay();
		GPIO_ResetPin(EN_PORT, EN_PIN); _LCD_Delay();
	} while(busy_flag!=0);
	
	_LCD_DataPins_ConfigureForOutputMode;
}

//********************************
void _LCD_Write_4BitMode(unsigned char data){		
	GPIO_WritePin(D7_PORT, D7_PIN, GetBit(data,7));
	GPIO_WritePin(D6_PORT, D6_PIN, GetBit(data,6));
	GPIO_WritePin(D5_PORT, D5_PIN, GetBit(data,5));
	GPIO_WritePin(D4_PORT, D4_PIN, GetBit(data,4));
	
	GPIO_SetPin(EN_PORT, EN_PIN); _LCD_Delay(); //HAL_Delay(1);
	GPIO_ResetPin(EN_PORT, EN_PIN); _LCD_Delay(); //HAL_Delay(1);
	
	GPIO_WritePin(D7_PORT, D7_PIN, GetBit(data,3));
	GPIO_WritePin(D6_PORT, D6_PIN, GetBit(data,2));
	GPIO_WritePin(D5_PORT, D5_PIN, GetBit(data,1));
	GPIO_WritePin(D4_PORT, D4_PIN, GetBit(data,0));
	
	GPIO_SetPin(EN_PORT, EN_PIN); _LCD_Delay(); //HAL_Delay(1);
	GPIO_ResetPin(EN_PORT, EN_PIN); _LCD_Delay(); //HAL_Delay(1);
}

//********************************
void LCD_PutCommand(unsigned char data){
	_LCD_Ready();
	_SetOperationMode(_INSTRUCTION_WRITE);
	_LCD_Write_4BitMode(data); //HAL_Delay(1);
}

//********************************
void LCD_SetOnOff(char status){
	WriteBit(_display_cursor_bink, _DISPLAY_POS, status);
	LCD_PutCommand(_display_cursor_bink);
}

//********************************
void LCD_Cursor_SetOnOff(char status){
	WriteBit(_display_cursor_bink, _CURSOR_POS, status);
	LCD_PutCommand(_display_cursor_bink);
}

//********************************
void LCD_BlinkingCursor_SetOnOff(char status){
	WriteBit(_display_cursor_bink, _BLINK_POS, status);
	LCD_PutCommand(_display_cursor_bink);
}

//********************************
void LCD_InterfaceDataLength_Set4BitOr8Bit(char mode){
	WriteBit(_interface_line, _INTERFACE_POS, mode);
	LCD_PutCommand(_interface_line);
}

//********************************
void LCD_SetLine(char mode){
	WriteBit(_interface_line, _LINE_POS, mode);
	LCD_PutCommand(_interface_line);
}

//********************************
void LCD_GoToXY(unsigned char x, unsigned char y){
	const unsigned char base_y[4]={0x80,0xC0,0x94,0xD4};
	LCD_PutCommand(base_y[y]+x); //HAL_Delay(1);
}

//********************************
void LCD_ClearDisplay(void){
	LCD_PutCommand(_CLEAR_DISPLAY); HAL_Delay(2);
	LCD_PutCommand(_RETURN_HOME); HAL_Delay(2);
}

//********************************
void LCD_PutChar(char data){
	_LCD_Ready();
	_SetOperationMode(_DATA_WRITE);
  _LCD_Write_4BitMode(data); //HAL_Delay(1);
}

//********************************
void LCD_PutString(char *str){
  while(*str != 0){
		LCD_PutChar(*str);
    str++;
  }
}

//********************************
void LCD_PutStringFromFlash(const char *str){
  while(*str != 0){
		LCD_PutChar(*str);
    str++;
  }
}

//********************************
void LCD_Configuration(void){
  HAL_Delay(20);
	_LCD_EnableBusForPorts();
	_LCD_ControlPins_Configuration;
	_LCD_DataPins_ConfigureForOutputMode;
	
	LCD_PutCommand(_RETURN_HOME); HAL_Delay(2);
	LCD_PutCommand(_interface_line);
	LCD_PutCommand(_display_cursor_bink);
	LCD_PutCommand(_CLEAR_DISPLAY); HAL_Delay(2);
	LCD_PutCommand(_RETURN_HOME); HAL_Delay(2);
}




