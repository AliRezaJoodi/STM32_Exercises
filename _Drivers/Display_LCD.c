// GitHub Account: GitHub.com/AliRezaJoodi

#include "Display_LCD.h"

static unsigned char _display_cursor_bink=(0b00001000 | (DISPLAY_ON<<_DISPLAY_POS) | (CURSOR_OFF<<_CURSOR_POS) | (BLINK_OFF<<_BLINK_POS));
static unsigned char _interface_line=(0b00100000 | (INTERFACE_4BIT<<_INTERFACE_POS) | (LINE_DUAL<<_LINE_POS));

//********************************
void _LCD_EnableBusForGPIO(void){
	BUS_EnableOrDisableClockForPortA(1); BUS_WaitTillEnableClockForPortA;
	BUS_EnableOrDisableClockForPortB(1); BUS_WaitTillEnableClockForPortB;
}

//********************************
void _LCD_ConfigurationControlPinsForOutput(void){
	GPIO_ConfigurePinDirection(RS_PORT,RS_PIN,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(RS_PORT,RS_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(RS_PORT,RS_PIN);
	
	GPIO_ConfigurePinDirection(RW_PORT,RW_PIN,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(RW_PORT,RW_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(RW_PORT,RW_PIN);
	
	GPIO_ConfigurePinDirection(EN_PORT,EN_PIN,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(EN_PORT,EN_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(EN_PORT,EN_PIN);
}

//********************************
void _LCD_ConfigurationDataPinsForOutput(void){
	GPIO_ConfigurePinDirection(D7_PORT,D7_PIN,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(D7_PORT,D7_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(D7_PORT,D7_PIN);
	
	GPIO_ConfigurePinDirection(D6_PORT,D6_PIN,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(D6_PORT,D6_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(D6_PORT,D6_PIN);
	
	GPIO_ConfigurePinDirection(D5_PORT,D5_PIN,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(D5_PORT,D5_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(D5_PORT,D5_PIN);
	
	GPIO_ConfigurePinDirection(D4_PORT,D4_PIN,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(D4_PORT,D4_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(D4_PORT,D4_PIN);	
}

//********************************
void _LCD_ConfigurationDataPinsForInput(void){
	GPIO_ConfigurePinDirection(D7_PORT,D7_PIN,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(D7_PORT,D7_PIN,FLOATING_INPUT);
	
	GPIO_ConfigurePinDirection(D6_PORT,D6_PIN,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(D6_PORT,D6_PIN,FLOATING_INPUT);
	
	GPIO_ConfigurePinDirection(D5_PORT,D5_PIN,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(D5_PORT,D5_PIN,FLOATING_INPUT);
	
	GPIO_ConfigurePinDirection(D4_PORT,D4_PIN,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(D4_PORT,D4_PIN,FLOATING_INPUT);
}

//********************************
void _LCD_Delay(void){
  volatile unsigned char i=1; //5
	while(i!=0){i--;}
}

//********************************
void _LCD_Ready(void){
	volatile char busy_flag=1;
	_LCD_ConfigurationDataPinsForInput();
	_LCD_SelectOperationMode(_INSTRUCTION_READ);
	_LCD_Delay();
	
	do{
		GPIO_SetPin(EN_PORT,EN_PIN); _LCD_Delay();
		busy_flag=GPIO_GetPin(D7_PORT,D7_PIN);
		GPIO_ResetPin(EN_PORT,EN_PIN); _LCD_Delay();
	
		GPIO_SetPin(EN_PORT,EN_PIN); _LCD_Delay();
		GPIO_ResetPin(EN_PORT,EN_PIN); _LCD_Delay();
	} while(busy_flag!=0);
	
	_LCD_ConfigurationDataPinsForOutput();
}

//********************************
void _LCD_Write_4BitMode(unsigned char data){		
	GPIO_WritePin(D7_PORT,D7_PIN,GetBit(data,7));
	GPIO_WritePin(D6_PORT,D6_PIN,GetBit(data,6));
	GPIO_WritePin(D5_PORT,D5_PIN,GetBit(data,5));
	GPIO_WritePin(D4_PORT,D4_PIN,GetBit(data,4));
	
	GPIO_SetPin(EN_PORT,EN_PIN); _LCD_Delay(); //HAL_Delay(1);
	GPIO_ResetPin(EN_PORT,EN_PIN); _LCD_Delay(); //HAL_Delay(1);
	
	GPIO_WritePin(D7_PORT,D7_PIN,GetBit(data,3));
	GPIO_WritePin(D6_PORT,D6_PIN,GetBit(data,2));
	GPIO_WritePin(D5_PORT,D5_PIN,GetBit(data,1));
	GPIO_WritePin(D4_PORT,D4_PIN,GetBit(data,0));
	
	GPIO_SetPin(EN_PORT,EN_PIN); _LCD_Delay(); //HAL_Delay(1);
	GPIO_ResetPin(EN_PORT,EN_PIN); _LCD_Delay(); //HAL_Delay(1);
}

//********************************
void LCD_PutCommand(unsigned char data){
	_LCD_Ready();
	_LCD_SelectOperationMode(_INSTRUCTION_WRITE);
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
	_LCD_SelectOperationMode(_DATA_WRITE);
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
void LCD_ConfigureDefaultMode(void){
  HAL_Delay(20);
	_LCD_EnableBusForGPIO();
	_LCD_ConfigurationControlPinsForOutput();
	_LCD_ConfigurationDataPinsForOutput();
	
	LCD_PutCommand(_RETURN_HOME); HAL_Delay(2);
	LCD_PutCommand(_interface_line);
	LCD_PutCommand(_display_cursor_bink);
	LCD_PutCommand(_CLEAR_DISPLAY); HAL_Delay(2);
	LCD_PutCommand(_RETURN_HOME); HAL_Delay(2);
}




