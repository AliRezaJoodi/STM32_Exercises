
#include "Display_LCD.h"

static char _display_cursor_bink=(0b00001000 | (DISPLAY_ON<<_DISPLAY_POS) | (CURSOR_OFF<<_CURSOR_POS) | (BLINK_OFF<<_BLINK_POS));
static char _interface_line=(0b00100000 | (INTERFACE_4BIT<<_INTERFACE_POS) | (LINE_DUAL<<_LINE_POS));

//********************************
void _LCD_Write_4BitMode(unsigned char data){	
	WritePinFromOutput(D7_PORT,D7_PIN,GetBit(data,7));
	WritePinFromOutput(D6_PORT,D6_PIN,GetBit(data,6));
	WritePinFromOutput(D5_PORT,D5_PIN,GetBit(data,5));
	WritePinFromOutput(D4_PORT,D4_PIN,GetBit(data,4));
	
	SetPinFromOutput(EN_PORT,EN_PIN); HAL_Delay(1);
	ResetPinFromOutput(EN_PORT,EN_PIN); HAL_Delay(1);
	
	WritePinFromOutput(D7_PORT,D7_PIN,GetBit(data,3));
	WritePinFromOutput(D6_PORT,D6_PIN,GetBit(data,2));
	WritePinFromOutput(D5_PORT,D5_PIN,GetBit(data,1));
	WritePinFromOutput(D4_PORT,D4_PIN,GetBit(data,0));
	
	SetPinFromOutput(EN_PORT,EN_PIN); HAL_Delay(1);
	ResetPinFromOutput(EN_PORT,EN_PIN); HAL_Delay(1);
}

//********************************
void LCD_PutCommand(unsigned char data){
	_SelectInstructionOrDataRegisterForLCD(_REGISTER_INSTRUCTION);
	_SelectWriteOrReadModeForLCD(_OPERATION_WRITE);

	_LCD_Write_4BitMode(data); HAL_Delay(1);
}

//********************************
void ConfigureDisplayStatus(char status){
		WriteBit(_display_cursor_bink,2,status&0b1);
		LCD_PutCommand(_display_cursor_bink);
}

//********************************
void ConfigureCursorStatus(char status){
		WriteBit(_display_cursor_bink,1,status&0b1);
		LCD_PutCommand(_display_cursor_bink);
}

//********************************
void ConfigureBlinkingCursorStatus(char status){
		WriteBit(_display_cursor_bink,0,status&0b1);
		LCD_PutCommand(_display_cursor_bink);
}

//********************************
void ConfigureInterfaceDataLength(char mode){
		WriteBit(_interface_line,_INTERFACE_POS,mode&0b1);
		LCD_PutCommand(_interface_line);
}

//********************************
void ConfigureLine(char mode){
		WriteBit(_interface_line,_LINE_POS,mode&0b1);
		LCD_PutCommand(_interface_line);
}

//********************************
void lcd_gotoxy(unsigned char x, unsigned char y){
	const unsigned char _base_y[4]={0x80,0xC0,0x94,0xD4};
	
	_SelectInstructionOrDataRegisterForLCD(_REGISTER_INSTRUCTION);
	_SelectWriteOrReadModeForLCD(_OPERATION_WRITE);
	
	_LCD_Write_4BitMode(_base_y[y]+x); HAL_Delay(1);
}

//********************************
void lcd_clear(void){
	_SelectInstructionOrDataRegisterForLCD(_REGISTER_INSTRUCTION);
	_SelectWriteOrReadModeForLCD(_OPERATION_WRITE);

	_LCD_Write_4BitMode(_CLEAR_DISPLAY); HAL_Delay(2);
	_LCD_Write_4BitMode(_RETURN_HOME); HAL_Delay(2);
}

//********************************
void lcd_init(void){
  HAL_Delay(20);
	_SelectInstructionOrDataRegisterForLCD(_REGISTER_INSTRUCTION);
	_SelectWriteOrReadModeForLCD(_OPERATION_WRITE);
	
	_LCD_Write_4BitMode(_RETURN_HOME); HAL_Delay(2); 
	_LCD_Write_4BitMode(_interface_line);
	//ConfigureInterfaceDataLength(INTERFACE_8BIT);
	//ConfigureLine(LINE_DUAL);
	_LCD_Write_4BitMode(_display_cursor_bink);
	_LCD_Write_4BitMode(_CLEAR_DISPLAY); HAL_Delay(2);
	_LCD_Write_4BitMode(_RETURN_HOME); HAL_Delay(2);	
}

//********************************
void lcd_PutChar(char data){
	_SelectInstructionOrDataRegisterForLCD(_REGISTER_DATA);
	_SelectWriteOrReadModeForLCD(_OPERATION_WRITE);
	
  _LCD_Write_4BitMode(data); //HAL_Delay(1);
}

//********************************
void lcd_PutString(char *str){
	_SelectInstructionOrDataRegisterForLCD(_REGISTER_DATA);
	_SelectWriteOrReadModeForLCD(_OPERATION_WRITE);
  while(*str != 0){
		_LCD_Write_4BitMode(*str);
    str++;
  }
}

//********************************
void lcd_PutStringFromFlash(const char *str){
	_SelectInstructionOrDataRegisterForLCD(_REGISTER_DATA);
	_SelectWriteOrReadModeForLCD(_OPERATION_WRITE);
  while(*str != 0){
		_LCD_Write_4BitMode(*str);
    str++;
  }
}




