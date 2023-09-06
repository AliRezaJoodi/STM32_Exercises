// GitHub Account: GitHub.com/AliRezaJoodi

#include "Display_LCD.h"

static unsigned char _display_cursor_bink=(0b00001000 | (DISPLAY_ON<<_DISPLAY_POS) | (CURSOR_OFF<<_CURSOR_POS) | (BLINK_OFF<<_BLINK_POS));
static unsigned char _interface_line=(0b00100000 | (INTERFACE_4BIT<<_INTERFACE_POS) | (LINE_DUAL<<_LINE_POS));

//********************************
void _LCD_EnableBusForGPIO(void){
	EnableOrDisableClockSourceForPortA(1); WaitTillEnableClockSourceForPortA;
	EnableOrDisableClockSourceForPortB(1); WaitTillEnableClockSourceForPortB;
}

//********************************
void _LCD_ConfigurationControlPinsForOutput(void){
	ConfigurePinForDirection(RS_PORT,RS_PIN,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(RS_PORT,RS_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(RS_PORT,RS_PIN);
	
	ConfigurePinForDirection(RW_PORT,RW_PIN,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(RW_PORT,RW_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(RW_PORT,RW_PIN);
	
	ConfigurePinForDirection(EN_PORT,EN_PIN,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(EN_PORT,EN_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(EN_PORT,EN_PIN);
}

//********************************
void _LCD_ConfigurationDataPinsForOutput(void){
	ConfigurePinForDirection(D7_PORT,D7_PIN,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(D7_PORT,D7_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(D7_PORT,D7_PIN);
	
	ConfigurePinForDirection(D6_PORT,D6_PIN,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(D6_PORT,D6_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(D6_PORT,D6_PIN);
	
	ConfigurePinForDirection(D5_PORT,D5_PIN,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(D5_PORT,D5_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(D5_PORT,D5_PIN);
	
	ConfigurePinForDirection(D4_PORT,D4_PIN,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(D4_PORT,D4_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(D4_PORT,D4_PIN);	
}

//********************************
void _LCD_ConfigurationDataPinsForInput(void){
	ConfigurePinForDirection(D7_PORT,D7_PIN,INPUT_MODE);
	ConfigurePinForInputMode(D7_PORT,D7_PIN,FLOATING_INPUT);
	
	ConfigurePinForDirection(D6_PORT,D6_PIN,INPUT_MODE);
	ConfigurePinForInputMode(D6_PORT,D6_PIN,FLOATING_INPUT);
	
	ConfigurePinForDirection(D5_PORT,D5_PIN,INPUT_MODE);
	ConfigurePinForInputMode(D5_PORT,D5_PIN,FLOATING_INPUT);
	
	ConfigurePinForDirection(D4_PORT,D4_PIN,INPUT_MODE);
	ConfigurePinForInputMode(D4_PORT,D4_PIN,FLOATING_INPUT);
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
		SetPinFromOutput(EN_PORT,EN_PIN); _LCD_Delay();
		busy_flag=GetPinFromInput(D7_PORT,D7_PIN);
		ResetPinFromOutput(EN_PORT,EN_PIN); _LCD_Delay();
	
		SetPinFromOutput(EN_PORT,EN_PIN); _LCD_Delay();
		ResetPinFromOutput(EN_PORT,EN_PIN); _LCD_Delay();
	} while(busy_flag!=0);
	
	_LCD_ConfigurationDataPinsForOutput();
}

//********************************
void _LCD_Write_4BitMode(unsigned char data){		
	WritePinFromOutput(D7_PORT,D7_PIN,GetBit(data,7));
	WritePinFromOutput(D6_PORT,D6_PIN,GetBit(data,6));
	WritePinFromOutput(D5_PORT,D5_PIN,GetBit(data,5));
	WritePinFromOutput(D4_PORT,D4_PIN,GetBit(data,4));
	
	SetPinFromOutput(EN_PORT,EN_PIN); _LCD_Delay(); //HAL_Delay(1);
	ResetPinFromOutput(EN_PORT,EN_PIN); _LCD_Delay(); //HAL_Delay(1);
	
	WritePinFromOutput(D7_PORT,D7_PIN,GetBit(data,3));
	WritePinFromOutput(D6_PORT,D6_PIN,GetBit(data,2));
	WritePinFromOutput(D5_PORT,D5_PIN,GetBit(data,1));
	WritePinFromOutput(D4_PORT,D4_PIN,GetBit(data,0));
	
	SetPinFromOutput(EN_PORT,EN_PIN); _LCD_Delay(); //HAL_Delay(1);
	ResetPinFromOutput(EN_PORT,EN_PIN); _LCD_Delay(); //HAL_Delay(1);
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




