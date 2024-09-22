// GitHub Account: GitHub.com/AliRezaJoodi

#include <display_7segment_1digit.h>

//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
//A , B , C , D , E , F,
// - , Dp
const unsigned char _7segment_table[18]={
    0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111,
    0b01110111 , 0b01111100 , 0b00111001 , 0b01011110 , 0b01111001 , 0b01110001 ,
    0b01000000 , 0b10000000,
 };

char _1digit_onoff=1;

#define _7Segment1Digit_TurnOffSegments \
	GPIO_WritePin(A_GPIO, A_PIN, !SEGMENT_ON);\
	GPIO_WritePin(B_GPIO, B_PIN, !SEGMENT_ON);\
	GPIO_WritePin(C_GPIO, C_PIN, !SEGMENT_ON);\
	GPIO_WritePin(D_GPIO, D_PIN, !SEGMENT_ON);\
	GPIO_WritePin(E_GPIO, E_PIN, !SEGMENT_ON);\
	GPIO_WritePin(F_GPIO, F_PIN, !SEGMENT_ON);\
  	GPIO_WritePin(G_GPIO, G_PIN, !SEGMENT_ON);\
	GPIO_WritePin(DP_GPIO, DP_PIN, !SEGMENT_ON);
	
#define _7Segment1Digit_DriveSegments(data) \
	GPIO_WritePin(A_GPIO, A_PIN, GetBit(data,0));\
	GPIO_WritePin(B_GPIO, B_PIN, GetBit(data,1));\
	GPIO_WritePin(C_GPIO, C_PIN, GetBit(data,2));\
	GPIO_WritePin(D_GPIO, D_PIN, GetBit(data,3));\
	GPIO_WritePin(E_GPIO, E_PIN, GetBit(data,4));\
	GPIO_WritePin(F_GPIO, F_PIN, GetBit(data,5));\
	GPIO_WritePin(G_GPIO, G_PIN, GetBit(data,6));\
	GPIO_WritePin(DP_GPIO, DP_PIN, GetBit(data,7));

#define _7Segment1Digit_TurnOffDigits \
	GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, !DIGIT_ON);
	

//***************************************************
void Display7Segment1Digit_Config(void){
	BUS_GPIOx_EnableOrDisableWithAutoSearch(A_GPIO);
	GPIO_ConfigPinForPushPullOutputMode(A_GPIO, A_PIN);
	
	BUS_GPIOx_EnableOrDisableWithAutoSearch(B_GPIO);
	GPIO_ConfigPinForPushPullOutputMode(B_GPIO, B_PIN);
	
	BUS_GPIOx_EnableOrDisableWithAutoSearch(C_GPIO);
	GPIO_ConfigPinForPushPullOutputMode(C_GPIO, C_PIN);
	
	BUS_GPIOx_EnableOrDisableWithAutoSearch(D_GPIO);
	GPIO_ConfigPinForPushPullOutputMode(D_GPIO, D_PIN);
	
	BUS_GPIOx_EnableOrDisableWithAutoSearch(E_GPIO);
	GPIO_ConfigPinForPushPullOutputMode(E_GPIO, E_PIN);
	
	BUS_GPIOx_EnableOrDisableWithAutoSearch(F_GPIO);
	GPIO_ConfigPinForPushPullOutputMode(F_GPIO, F_PIN);
	
	BUS_GPIOx_EnableOrDisableWithAutoSearch(G_GPIO);
	GPIO_ConfigPinForPushPullOutputMode(G_GPIO, G_PIN);
	
	BUS_GPIOx_EnableOrDisableWithAutoSearch(DP_GPIO);
	GPIO_ConfigPinForPushPullOutputMode(DP_GPIO, DP_PIN);
	
	BUS_GPIOx_EnableOrDisableWithAutoSearch(DIGIT0_GPIO);
	GPIO_ConfigPinForPushPullOutputMode(DIGIT0_GPIO, DIGIT0_PIN);
	
	_7Segment1Digit_TurnOffDigits;
	_7Segment1Digit_TurnOffSegments;
}

//********************************************
void Display7Segment1Digit_SetOnOff(char Status){
	_1digit_onoff = Status & 0b1;
	
	if(_1digit_onoff==0){
		_7Segment1Digit_TurnOffDigits;
		_7Segment1Digit_TurnOffSegments;
	}
}

//**************************************
void Display7Segment1Digit_DisplayValue(unsigned char number){
	if(_1digit_onoff){
		#if SEGMENT_ON == 0
			number = ~_7segment_table[number];
		#else
			value = _7segment_table[number];
		#endif
	
		_7Segment1Digit_DriveSegments(number);
		GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, DIGIT_ON);
	}
}
