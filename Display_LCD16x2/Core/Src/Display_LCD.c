// GitHub Account: GitHub.com/AliRezaJoodi

#include "Display_LCD.h"

static unsigned char _display_cursor_bink=(0b00001000 | (DISPLAY_ON<<_DISPLAY_POS) | (CURSOR_OFF<<_CURSOR_POS) | (BLINK_OFF<<_BLINK_POS));
static unsigned char _interface_line=(0b00100000 | (INTERFACE_4BIT<<_INTERFACE_POS) | (LINE_DUAL<<_LINE_POS));

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
	_LCD_DataPins_ConfigurationForInputMode;
	_SelectOperationMode(_INSTRUCTION_READ);
	_LCD_Delay();
	
	do{
		GPIO_SetPin(EN_PORT, EN_PIN); _LCD_Delay();
		busy_flag = GPIO_GetPin(D7_PORT, D7_PIN);
		GPIO_ResetPin(EN_PORT, EN_PIN); _LCD_Delay();
	
		GPIO_SetPin(EN_PORT, EN_PIN); _LCD_Delay();
		GPIO_ResetPin(EN_PORT, EN_PIN); _LCD_Delay();
	} while(busy_flag!=0);
	
	_LCD_DataPins_ConfigurationForOutputMode;
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
	_SelectOperationMode(_INSTRUCTION_WRITE);
	_LCD_Write_4BitMode(data); //HAL_Delay(1);
}

//********************************
void LCD_ConfigureDisplayStatus(char status){
	WriteBit(_display_cursor_bink,_DISPLAY_POS,status);
	LCD_PutCommand(_display_cursor_bink);
}

//********************************
void LCD_ConfigureCursorStatus(char status){
	WriteBit(_display_cursor_bink,_CURSOR_POS,status);
	LCD_PutCommand(_display_cursor_bink);
}

//********************************
void LCD_ConfigureBlinkingCursorStatus(char status){
	WriteBit(_display_cursor_bink,_BLINK_POS,status);
	LCD_PutCommand(_display_cursor_bink);
}

//********************************
void LCD_ConfigureInterfaceDataLength(char mode){
	WriteBit(_interface_line,_INTERFACE_POS,mode);
	LCD_PutCommand(_interface_line);
}

//********************************
void LCD_ConfigureLine(char mode){
	WriteBit(_interface_line,_LINE_POS,mode);
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
	_SelectOperationMode(_DATA_WRITE);
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
	_LCD_DataPins_ConfigurationForOutputMode;
	
	LCD_PutCommand(_RETURN_HOME); HAL_Delay(2);
	LCD_PutCommand(_interface_line);
	LCD_PutCommand(_display_cursor_bink);
	LCD_PutCommand(_CLEAR_DISPLAY); HAL_Delay(2);
	LCD_PutCommand(_RETURN_HOME); HAL_Delay(2);
}




