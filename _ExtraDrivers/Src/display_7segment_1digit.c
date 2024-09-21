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

#define _7Segment1Digit_SetPinForOutputMode(GPIOx, PIN); \
	GPIO_SetInputOrOutputMode(GPIOx, PIN, IO_OUTPUT);\
	GPIO_OutputMode_SetGeneralPurposeOrAlternateFunction(GPIOx, PIN, OUTPUT_GP);\
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOx, PIN, OUTPUT_PUSHPULL);

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
	BUS_GPIOA_EnableOrDisable(1);
	
	_7Segment1Digit_SetPinForOutputMode(A_GPIO, A_PIN);
	_7Segment1Digit_SetPinForOutputMode(B_GPIO, B_PIN);
	_7Segment1Digit_SetPinForOutputMode(C_GPIO, C_PIN);
	_7Segment1Digit_SetPinForOutputMode(D_GPIO, D_PIN);
	_7Segment1Digit_SetPinForOutputMode(E_GPIO, E_PIN);
	_7Segment1Digit_SetPinForOutputMode(F_GPIO, F_PIN);
	_7Segment1Digit_SetPinForOutputMode(G_GPIO, G_PIN);
	_7Segment1Digit_SetPinForOutputMode(DP_GPIO, DP_PIN);
	
	_7Segment1Digit_SetPinForOutputMode(DIGIT0_GPIO, DIGIT0_PIN);
	
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