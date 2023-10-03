// GitHub Account: GitHub.com/AliRezaJoodi

#include "Display_7Segment.h"

#ifndef _DIGITS_PORT
    #define _DIGITS_PORT 
		
		#define DIGIT_ON      0
		
		#define DIGIT0_GPIO         GPIOA
    #define DIGIT0_PIN          15
#endif

#define _ConfigureDigitsPins \
	_ConfigurePinFor7Segment(DIGIT0_GPIO, DIGIT0_PIN);\

#define _OffDigitsPins \
	GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, !DIGIT_ON);\


//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
//A , B , C , D , E , F,
// - , Dp
const unsigned char table_7segment[18]={
    0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111,
    0b01110111 , 0b01111100 , 0b00111001 , 0b01011110 , 0b01111001 , 0b01110001 ,
    0b01000000 , 0b10000000,
 };


//***************************************************
void DisplayOn7Segment_Configuration(void){
	BUS_GPIOA_EnableOrDisable(1);
	
	_ConfigureSegmentsPins;
	_OffSegmentsPins;
	
	_ConfigureDigitsPins;
	_OffDigitsPins;
}

//**************************************
void DisplayOn7Segment_Number(unsigned char value){
	value = table_7segment[value];
	if(SEGMENT_ON==0){ToggleData(value);}
	_DriveDataOn7Segment(value);
	GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, DIGIT_ON);
}
