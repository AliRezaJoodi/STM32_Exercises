// GitHub Account: GitHub.com/AliRezaJoodi

#include "Display_7Segment.h"

#ifndef _DIGITS_PORT
    #define _DIGITS_PORT 
		
		#define DISPLAYLAG    15000 //Display Lag
		#define DIGIT_ON      1
		
		#define DIGIT0_PORT		GPIOB
    #define DIGIT0_PIN    3
		
		#define DIGIT1_PORT		GPIOB
    #define DIGIT1_PIN    2
		
		#define DIGIT2_PORT		GPIOB
    #define DIGIT2_PIN    1
		
		#define DIGIT3_PORT		GPIOB
    #define DIGIT3_PIN    0
#endif

#define _7segment_DigitsPins_Configuration \
	_7Segment_SetPinForOutputMode(DIGIT0_PORT, DIGIT0_PIN);\
	_7Segment_SetPinForOutputMode(DIGIT1_PORT, DIGIT1_PIN);\
	_7Segment_SetPinForOutputMode(DIGIT2_PORT, DIGIT2_PIN);\
	_7Segment_SetPinForOutputMode(DIGIT3_PORT, DIGIT3_PIN);

#define _7segment_DigitsPins_TurnOff \
	GPIO_WritePin(DIGIT0_PORT, DIGIT0_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT1_PORT, DIGIT1_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT2_PORT, DIGIT2_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT3_PORT, DIGIT3_PIN, !DIGIT_ON);


//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
//A , B , C , D , E , F,
// -, Dp, NULL
const unsigned char _table7segment[19]={
    0b00111111 , 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111,
    0b01110111 , 0b01111100, 0b00111001, 0b01011110, 0b01111001, 0b01110001,
    0b01000000 , 0b10000000, 0b00000000
 };
 
unsigned char _digits7segment[4]; //={~0b01100110, ~0b01001111, ~0b01011011, ~0b00000110};
char decimal=0;
//char sign=0;

//********************************
 void _7segment_EnableBusForPorts(void){
	if(	A_PORT 			==	GPIOA || \
			B_PORT 			==	GPIOA || \
			C_PORT 			==	GPIOA || \
			D_PORT 			==	GPIOA || \
			E_PORT 			==	GPIOA || \
			F_PORT 			==	GPIOA || \
			G_PORT 			==	GPIOA || \
			DIGIT0_PORT ==	GPIOA || \
			DIGIT1_PORT ==	GPIOA || \
			DIGIT2_PORT == 	GPIOA || \
			DIGIT3_PORT == 	GPIOA )
		{BUS_GPIOA_EnableOrDisable(1);}

	if(	A_PORT			==	GPIOB || \
			B_PORT			==	GPIOB || \
			C_PORT			==	GPIOB || \
			D_PORT			==	GPIOB || \
			E_PORT			==	GPIOB || \
			F_PORT			==	GPIOB || \
			G_PORT			==	GPIOB || \
			DIGIT0_PORT	==	GPIOB || \
			DIGIT1_PORT	==	GPIOB || \
			DIGIT2_PORT	==	GPIOB || \
			DIGIT3_PORT	==	GPIOB)
		{BUS_GPIOB_EnableOrDisable(1);}

	if(	A_PORT			==	GPIOC || \
			B_PORT			==	GPIOC || \
			C_PORT			==	GPIOC || \
			D_PORT			==	GPIOC || \
			E_PORT			==	GPIOC || \
			F_PORT			==	GPIOC || \
			G_PORT			==	GPIOC || \
			DIGIT0_PORT	==	GPIOC || \
			DIGIT1_PORT	==	GPIOC || \
			DIGIT2_PORT	==	GPIOC || \
			DIGIT3_PORT	==	GPIOC)
		{BUS_GPIOC_EnableOrDisable(1);}

	if(	A_PORT			==	GPIOD || \
			B_PORT			==	GPIOD || \
			C_PORT			==	GPIOD || \
			D_PORT			==	GPIOD || \
			E_PORT			==	GPIOD || \
			F_PORT			==	GPIOD || \
			G_PORT			==	GPIOD || \
			DIGIT0_PORT	==	GPIOD || \
			DIGIT1_PORT	==	GPIOD || \
			DIGIT2_PORT	==	GPIOD || \
			DIGIT3_PORT	==	GPIOD)
		{BUS_GPIOD_EnableOrDisable(1);}	
}

//***************************************************
void SevenSegment_4Digit_Configuration(void){
	_7segment_EnableBusForPorts();
	
	_7segment_SegmentsPins_Configuration;
	_7segment_SegmentsPins_TurnOff;
	
	_7segment_DigitsPins_Configuration;
	_7segment_DigitsPins_TurnOff;
}
	
//***************************************************
void SevenSegment_4Digit_UpdateNumbers_uint(unsigned int value){
	unsigned int value_int=0;
	unsigned char digit=0;
	
	value_int=value/1; digit=value_int%10;
	_digits7segment[0] = _table7segment[digit];

	value_int=value/10; digit=value_int%10;
	_digits7segment[1] = _table7segment[digit];
	
	value_int=value/100; digit=value_int%10;
	_digits7segment[2] = _table7segment[digit];
	
	value_int=value/1000; digit=value_int%10;
	_digits7segment[3] = _table7segment[digit];
	
	if(decimal==0){
		if(_digits7segment[3]==0b00111111 && _digits7segment[2]==0b00111111 && _digits7segment[1]==0b00111111){
			_digits7segment[1] = _table7segment[18];
			_digits7segment[2] = _table7segment[18];
			_digits7segment[3] = _table7segment[18];
		}
		if(_digits7segment[3]==0b00111111 && _digits7segment[2]==0b00111111){
			_digits7segment[2] = _table7segment[18];
			_digits7segment[3] = _table7segment[18];
		}
		if(_digits7segment[3]==0b00111111){
			_digits7segment[3] = _table7segment[18];
		}
	}
	else if(decimal==1){SetBit(_digits7segment[1],7);}
		else if(decimal==2){SetBit(_digits7segment[2],7);}
			else if(decimal==3){SetBit(_digits7segment[3],7);}
	
	if(value>9999){
			_digits7segment[0] = _table7segment[16];
			_digits7segment[1] = _table7segment[16];
			_digits7segment[2] = _table7segment[16];
			_digits7segment[3] = _table7segment[16];		
	};
	
	#if SEGMENT_ON == 0
		_digits7segment[0] = ~_digits7segment[0];
		_digits7segment[1] = ~_digits7segment[1];
		_digits7segment[2] = ~_digits7segment[2];
		_digits7segment[3] = ~_digits7segment[3];
	#endif
}

//***************************************************
void SevenSegment_4Digit_UpdateNumbers_float(float value){
	unsigned int value_int=0;
	
	if(value<10){value_int=value*1000; decimal=3;}
		else if(value<100){value_int=value*100; decimal=2;}
			else if(value<1000){value_int=value*10; decimal=1;}
				else {value_int=value; decimal=0;}
	
	SevenSegment_4Digit_UpdateNumbers_uint(value_int);
}

//***************************************************
void _4Digit_RefreshRightToLeft(void){
	static unsigned char i=0; 
	
	_7segment_DigitsPins_TurnOff;
	_DriveDataOn7Segment(_digits7segment[i]);

	switch(i){
		case 0:
			GPIO_WritePin(DIGIT0_PORT, DIGIT0_PIN, DIGIT_ON);
			++i;
			break;
		case 1:
			GPIO_WritePin(DIGIT1_PORT, DIGIT1_PIN, DIGIT_ON);
			++i;
			break;
		case 2:
			GPIO_WritePin(DIGIT2_PORT, DIGIT2_PIN, DIGIT_ON);
			++i;
			break;
		case 3:
			GPIO_WritePin(DIGIT3_PORT, DIGIT3_PIN, DIGIT_ON);
			i=0;
			break;
	}
}

//***************************************************
void _4Digit_RefreshLefToRight(void){
	static unsigned char i=3; 
	
	_7segment_DigitsPins_TurnOff;
	_DriveDataOn7Segment(_digits7segment[i]);
	
	switch(i){
		case 3:
			GPIO_WritePin(DIGIT3_PORT, DIGIT3_PIN, DIGIT_ON);
			--i;
			break;
		case 2:
			GPIO_WritePin(DIGIT2_PORT, DIGIT2_PIN, DIGIT_ON);
			--i;
			break;
		case 1:
			GPIO_WritePin(DIGIT1_PORT, DIGIT1_PIN, DIGIT_ON);
			--i;
			break;
		case 0:
			GPIO_WritePin(DIGIT0_PORT, DIGIT0_PIN, DIGIT_ON);
			i=3;
			break;
	}
}

//**********************************************
/*char SevenSegment_Delay(void){
	static unsigned int i=0;
	++i;
	if(i>DISPLAYLAG){
		i=0;
		return 1;
	}
	return 0;
}*/

//********************************************
/*void SevenSegment_Refresh_(char onoff){
	if(SevenSegment_Delay() && onoff==1){
		_4Digit_RefreshRightToLeft();
	};
}*/

//********************************************
void SevenSegment_4Digit_Refresh(char onoff){
	static unsigned int i=0;
	
	++i;
	if(i>DISPLAYLAG){
		i=0;
		if(onoff){_4Digit_RefreshLefToRight();}
	}
}

