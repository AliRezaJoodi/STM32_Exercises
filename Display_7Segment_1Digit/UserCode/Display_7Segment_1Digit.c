// GitHub Account: GitHub.com/AliRezaJoodi

#include "Display_7Segment.h"

#ifndef _DIGITS_PORT
    #define _DIGITS_PORT 
		
		#define DIGIT_ON      1
		
		#define DIGIT0_GPIO   GPIOA
    #define DIGIT0_PIN		15
#endif

//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
//A , B , C , D , E , F,
// - , Dp
const unsigned char _7segment_table[18]={
    0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111,
    0b01110111 , 0b01111100 , 0b00111001 , 0b01011110 , 0b01111001 , 0b01110001 ,
    0b01000000 , 0b10000000,
 };

char _1digit_onoff=1;

#define _1Digit_DigitsPins_Configuration \
	_7Segment_SetPinForOutputMode(DIGIT0_GPIO, DIGIT0_PIN);\

#define _1Digit_DigitsPins_TurnOff \
	GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, !DIGIT_ON);\
 
//***************************************************
void SevenSegment_1Digit_Configuration(void){
	BUS_GPIOA_EnableOrDisable(1);
	
	_7segment_SegmentsPins_Configuration;
	_7segment_SegmentsPins_TurnOff;
	
	_1Digit_DigitsPins_Configuration;
	_1Digit_DigitsPins_TurnOff;
}


//********************************************
void SevenSegment_1Digit_SetOnOff(char Status){
	_1digit_onoff = Status & 0b1;
	
	if(_1digit_onoff){
		GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, DIGIT_ON);
	}
	else{
		GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, !DIGIT_ON);
	}
}

//**************************************
void SevenSegment_1Digit_DisplayNumber(unsigned char number){
	#if SEGMENT_ON == 0
		number = ~_7segment_table[number];
	#else
		value = _7segment_table[number];
	#endif
	
	_7segment_DriveDataOnSegments(number);
	
	if(_1digit_onoff){
		GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, DIGIT_ON);
	}
	else{
		GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, !DIGIT_ON);
	}
}
