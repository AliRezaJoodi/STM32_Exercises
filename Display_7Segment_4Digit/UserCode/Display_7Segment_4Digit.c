// GitHub Account: GitHub.com/AliRezaJoodi

#include "Display_7Segment.h"

#ifndef _DIGITS_PORT
    #define _DIGITS_PORT 
		
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
// - , Dp
const unsigned char _table7segment[18]={
    0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111,
    0b01110111 , 0b01111100 , 0b00111001 , 0b01011110 , 0b01111001 , 0b01110001 ,
    0b01000000 , 0b10000000,
 };
 
unsigned char _digits7segment[4]; //={~0b01100110, ~0b01001111, ~0b01011011, ~0b00000110};
char decimal=0;
																		
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
	int value_int=value;
	unsigned char digit=0;
	
	digit=value_int%10;
	#if SEGMENT_ON == 0
		_digits7segment[0] = ~_table7segment[digit];
	#else
		_digits7segment[0] = _table7segment[digit];
	#endif
	
	value_int=value_int/10;
	digit=value_int%10;
	#if SEGMENT_ON == 0
		_digits7segment[1] = ~_table7segment[digit];
	#else
		_digits7segment[1] = _table7segment[digit];
	#endif
	
	value_int=value_int/10;
	digit=value_int%10;
	#if SEGMENT_ON == 0
		_digits7segment[2] = ~_table7segment[digit];
	#else
		_digits7segment[2] = _table7segment[digit];
	#endif
	
	value_int=value_int/10;
	digit=value_int%10;
	#if SEGMENT_ON == 0
		_digits7segment[3] = ~_table7segment[digit];
	#else
		_digits7segment[3] = _table7segment[digit];
	#endif
	
	if(value>9999){
		#if SEGMENT_ON == 0
			_digits7segment[0] = ~_table7segment[16];
			_digits7segment[1] = ~_table7segment[16];
			_digits7segment[2] = ~_table7segment[16];
			_digits7segment[3] = ~_table7segment[16];
		#else
			_digits7segment[0] = _table7segment[16];
			_digits7segment[1] = _table7segment[16];
			_digits7segment[2] = _table7segment[16];
			_digits7segment[3] = _table7segment[16];		
		#endif
	};
}

//***************************************************
void SevenSegment_4Digit_RefreshRightToLeft_uint(void){
	static unsigned char i = 0; 
	
	_OffDigitsPins;
	
	switch(i){
		case 0:
			_DriveDataOn7Segment(_digits7segment[i]);
			GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, DIGIT_ON);
			i++;
			#if SEGMENT_ON == 0
				if(_digits7segment[3]==0b11000000 && _digits7segment[2]==0b11000000 && _digits7segment[1]==0b11000000){i=0;}
			#else
				if(_digits7segment[3]==0b00111111 && _digits7segment[2]==0b00111111 && _digits7segment[1]==0b00111111){i=0;}
			#endif
			break;
		case 1:
			_DriveDataOn7Segment(_digits7segment[i]);
			GPIO_WritePin(DIGIT1_GPIO, DIGIT1_PIN, DIGIT_ON);
			i++;
			#if SEGMENT_ON == 0
				if(_digits7segment[3]==0b11000000 && _digits7segment[2]==0b11000000){i=0;}
			#else
				if(_digits7segment[3]==0b00111111 && _digits7segment[2]==0b00111111){i=0;}
			#endif
			break;
		case 2:
			_DriveDataOn7Segment(_digits7segment[i]);
			GPIO_WritePin(DIGIT2_GPIO, DIGIT2_PIN, DIGIT_ON);
			i++;
			#if SEGMENT_ON == 0
				if(_digits7segment[3]==0b11000000){i=0;}
			#else
				if(_digits7segment[3]==0b00111111){i=0;}
			#endif
			break;
		case 3:
			_DriveDataOn7Segment(_digits7segment[i]);
			GPIO_WritePin(DIGIT3_GPIO, DIGIT3_PIN, DIGIT_ON);
			i=0;
			break;
	}
}

