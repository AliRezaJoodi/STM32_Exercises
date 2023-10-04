// GitHub Account: GitHub.com/AliRezaJoodi

#include "Display_7Segment.h"

#ifndef _DIGITS_PORT
    #define _DIGITS_PORT 
		
		#define DISPLAYLAG    15000 //Display Lag
		#define DIGIT_ON      1
		
		#define DIGIT0_GPIO		GPIOB
    #define DIGIT0_PIN    3
		
		#define DIGIT1_GPIO		GPIOB
    #define DIGIT1_PIN    2
		
		#define DIGIT2_GPIO		GPIOB
    #define DIGIT2_PIN    1
		
		#define DIGIT3_GPIO		GPIOB
    #define DIGIT3_PIN    0
#endif

#define _ConfigureDigitsPins \
	_ConfigurePinFor7Segment(DIGIT0_GPIO, DIGIT0_PIN);\
	_ConfigurePinFor7Segment(DIGIT1_GPIO, DIGIT1_PIN);\
	_ConfigurePinFor7Segment(DIGIT2_GPIO, DIGIT2_PIN);\
	_ConfigurePinFor7Segment(DIGIT3_GPIO, DIGIT3_PIN);

#define _OffDigitsPins \
	GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT1_GPIO, DIGIT1_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT2_GPIO, DIGIT2_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT3_GPIO, DIGIT3_PIN, !DIGIT_ON);


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
																		
//***************************************************
void SevenSegment_4Digit_Configuration(void){
	BUS_GPIOA_EnableOrDisable(1);
	BUS_GPIOB_EnableOrDisable(1);
	
	_ConfigureSegmentsPins;
	_OffSegmentsPins;
	
	_ConfigureDigitsPins;
	_OffDigitsPins;
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
	
	_OffDigitsPins;
	_DriveDataOn7Segment(_digits7segment[i]);

	switch(i){
		case 0:
			GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, DIGIT_ON);
			++i;
			break;
		case 1:
			GPIO_WritePin(DIGIT1_GPIO, DIGIT1_PIN, DIGIT_ON);
			++i;
			break;
		case 2:
			GPIO_WritePin(DIGIT2_GPIO, DIGIT2_PIN, DIGIT_ON);
			++i;
			break;
		case 3:
			GPIO_WritePin(DIGIT3_GPIO, DIGIT3_PIN, DIGIT_ON);
			i=0;
			break;
	}
}

//***************************************************
void _4Digit_RefreshLefToRight(void){
	static unsigned char i=3; 
	
	_OffDigitsPins;
	_DriveDataOn7Segment(_digits7segment[i]);
	
	switch(i){
		case 3:
			GPIO_WritePin(DIGIT3_GPIO, DIGIT3_PIN, DIGIT_ON);
			--i;
			break;
		case 2:
			GPIO_WritePin(DIGIT2_GPIO, DIGIT2_PIN, DIGIT_ON);
			--i;
			break;
		case 1:
			GPIO_WritePin(DIGIT1_GPIO, DIGIT1_PIN, DIGIT_ON);
			--i;
			break;
		case 0:
			GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, DIGIT_ON);
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

