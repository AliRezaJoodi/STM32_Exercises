// GitHub Account: GitHub.com/AliRezaJoodi

#include <display_7segment_4digit_bm.h>

//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
//A , B , C , D , E , F,
// -, Dp, NULL
const unsigned char _7segment_table[19]={
    0b00111111 , 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111,
    0b01110111 , 0b01111100, 0b00111001, 0b01011110, 0b01111001, 0b01110001,
    0b01000000 , 0b10000000, 0b00000000
};

unsigned char _display_data[4]; //={~0b01100110, ~0b01001111, ~0b01011011, ~0b00000110};
char _display_decimal=0;
char _display_onoff=1;
//char _display_sign=0;

 /*
typedef struct{
	unsigned char data[4];
	char decimal_;
}_7segment;

_7segment display1;
display1.decimal_=0;
*/ 

#define _7Segment4Digit_TurnOffSegments \
	GPIO_WritePin(A_GPIO, A_PIN, !SEGMENT_ON);\
	GPIO_WritePin(B_GPIO, B_PIN, !SEGMENT_ON);\
	GPIO_WritePin(C_GPIO, C_PIN, !SEGMENT_ON);\
	GPIO_WritePin(D_GPIO, D_PIN, !SEGMENT_ON);\
	GPIO_WritePin(E_GPIO, E_PIN, !SEGMENT_ON);\
	GPIO_WritePin(F_GPIO, F_PIN, !SEGMENT_ON);\
	GPIO_WritePin(G_GPIO, G_PIN, !SEGMENT_ON);\
	GPIO_WritePin(DP_GPIO, DP_PIN, !SEGMENT_ON);
	
#define _7Segment4Digit_DriveSegments(data) \
	GPIO_WritePin(A_GPIO, A_PIN, GetBit(data,0));\
	GPIO_WritePin(B_GPIO, B_PIN, GetBit(data,1));\
	GPIO_WritePin(C_GPIO, C_PIN, GetBit(data,2));\
	GPIO_WritePin(D_GPIO, D_PIN, GetBit(data,3));\
	GPIO_WritePin(E_GPIO, E_PIN, GetBit(data,4));\
	GPIO_WritePin(F_GPIO, F_PIN, GetBit(data,5));\
	GPIO_WritePin(G_GPIO, G_PIN, GetBit(data,6));\
	GPIO_WritePin(DP_GPIO, DP_PIN, GetBit(data,7));

#define _7Segment4Digit_TurnOffDigits \
	GPIO_WritePin(DIGIT0_GPIO, DIGIT0_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT1_GPIO, DIGIT1_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT2_GPIO, DIGIT2_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT3_GPIO, DIGIT3_PIN, !DIGIT_ON);


//***************************************************
void Display7Segment4Digit_Config(void){
	BUS_GPIOx_EnableOrDisable(A_GPIO, 1);
	GPIO_OutputWithPushPullMode_ConfigPin(A_GPIO, A_PIN);
	
	BUS_GPIOx_EnableOrDisable(B_GPIO, 1);
	GPIO_OutputWithPushPullMode_ConfigPin(B_GPIO, B_PIN);
	
	BUS_GPIOx_EnableOrDisable(C_GPIO, 1);
	GPIO_OutputWithPushPullMode_ConfigPin(C_GPIO, C_PIN);
	
	BUS_GPIOx_EnableOrDisable(D_GPIO, 1);
	GPIO_OutputWithPushPullMode_ConfigPin(D_GPIO, D_PIN);
	
	BUS_GPIOx_EnableOrDisable(E_GPIO, 1);
	GPIO_OutputWithPushPullMode_ConfigPin(E_GPIO, E_PIN);
	
	BUS_GPIOx_EnableOrDisable(F_GPIO, 1);
	GPIO_OutputWithPushPullMode_ConfigPin(F_GPIO, F_PIN);
	
	BUS_GPIOx_EnableOrDisable(G_GPIO, 1);
	GPIO_OutputWithPushPullMode_ConfigPin(G_GPIO, G_PIN);
	
	BUS_GPIOx_EnableOrDisable(DP_GPIO, 1);
	GPIO_OutputWithPushPullMode_ConfigPin(DP_GPIO, DP_PIN);


	BUS_GPIOx_EnableOrDisable(DIGIT0_GPIO, 1);
	GPIO_OutputWithPushPullMode_ConfigPin(DIGIT0_GPIO, DIGIT0_PIN);
	
	BUS_GPIOx_EnableOrDisable(DIGIT1_GPIO, 1);
	GPIO_OutputWithPushPullMode_ConfigPin(DIGIT1_GPIO, DIGIT1_PIN);
	
	BUS_GPIOx_EnableOrDisable(DIGIT2_GPIO, 1);
	GPIO_OutputWithPushPullMode_ConfigPin(DIGIT2_GPIO, DIGIT2_PIN);
	
	BUS_GPIOx_EnableOrDisable(DIGIT3_GPIO, 1);
	GPIO_OutputWithPushPullMode_ConfigPin(DIGIT3_GPIO, DIGIT3_PIN);
	
	_7Segment4Digit_TurnOffDigits;
	_7Segment4Digit_TurnOffSegments;
}

//********************************************
void Display7Segment4Digit_SetOnOff(char Status){
	_display_onoff = Status & 0b1;
	
	if(_display_onoff==0){
		_7Segment4Digit_TurnOffDigits;
		_7Segment4Digit_TurnOffSegments;
	}
}

//***************************************************
void _7Segment4Digit_SeparateTheNumbers_PositiveInteger(unsigned int value){
	unsigned int value_int=0;
	unsigned char digit=0;
	
	value_int=value/1; 
	digit=value_int%10;
	_display_data[0] = _7segment_table[digit];

	value_int=value/10; 
	digit=value_int%10;
	_display_data[1] = _7segment_table[digit];
	
	value_int=value/100; 
	digit=value_int%10;
	_display_data[2] = _7segment_table[digit];
	
	value_int=value/1000; 
	digit=value_int%10;
	_display_data[3] = _7segment_table[digit];
}

//********************************************
void _7Segment4Digit_RemoveExtraZero_PositiveInteger(void){
	if(_display_data[3]==0b00111111 && _display_data[2]==0b00111111 && _display_data[1]==0b00111111){
		_display_data[1] = _7segment_table[18];
		_display_data[2] = _7segment_table[18];
		_display_data[3] = _7segment_table[18];
	}
	if(_display_data[3]==0b00111111 && _display_data[2]==0b00111111){
		_display_data[2] = _7segment_table[18];
		_display_data[3] = _7segment_table[18];
	}
	if(_display_data[3]==0b00111111){
		_display_data[3] = _7segment_table[18];
	}
}

//***************************************************
void _7Segment4Digit_SeparateTheNumbers_NegativeInteger(unsigned int value){
	unsigned int value_int=0;
	unsigned char digit=0;
	
	value_int=value/1; 
	digit=value_int%10;
	_display_data[0] = _7segment_table[digit];

	value_int=value/10; 
	digit=value_int%10;
	_display_data[1] = _7segment_table[digit];
	
	value_int=value/100; 
	digit=value_int%10;
	_display_data[2] = _7segment_table[digit];
	
	_display_data[3] = _7segment_table[16];
}

//********************************************
void _7Segment4Digit_RemoveExtraZero_NegativeInteger(void){
	if(_display_data[2]==0b00111111 && _display_data[1]==0b00111111){
		_display_data[1] = _7segment_table[18];
		_display_data[2] = _7segment_table[18];
	}
	if(_display_data[2]==0b00111111){
		_display_data[2] = _7segment_table[18];
	}
}

//***************************************************
unsigned int _7Segment4Digit_AdjustNumberAndDecimalPointPosition_PositiveNumber(float value){
	unsigned int value_int=0;
	
		if(value<10){value_int=value*1000; _display_decimal=3;}
			else if(value<100){value_int=value*100; _display_decimal=2;}
				else if(value<1000){value_int=value*10; _display_decimal=1;}
					else {value_int=value; _display_decimal=0;}	

	return value_int;
}

//***************************************************
unsigned int _7Segment4Digit_AdjustNumberAndDecimalPointPosition_NegativeNumber(float value){
	unsigned int value_int=0;
	
		if(value<10){value_int=value*100; _display_decimal=2;}
			else if(value<100){value_int=value*10; _display_decimal=1;}
				else {value_int=value; _display_decimal=0;}	

	return value_int;
}

//***************************************************
void _7Segment4Digit_SetDecimalPointPosition(void){
	if(_display_decimal==1){SetBit(_display_data[1],7);}
		else if(_display_decimal==2){SetBit(_display_data[2],7);}
			else if(_display_decimal==3){SetBit(_display_data[3],7);}	
}

//***************************************************
void Display7Segment4Digit_SetValue_float(float value){
	unsigned int buffer=0;
	
	if(0<=value && value<9999){
		buffer=_7Segment4Digit_AdjustNumberAndDecimalPointPosition_PositiveNumber(value);
		_7Segment4Digit_SeparateTheNumbers_PositiveInteger(buffer);
		_7Segment4Digit_SetDecimalPointPosition();
	}
	else if(-999<=value && value<0){
		buffer=_7Segment4Digit_AdjustNumberAndDecimalPointPosition_NegativeNumber(value*-1);
		_7Segment4Digit_SeparateTheNumbers_NegativeInteger(buffer);
		_7Segment4Digit_SetDecimalPointPosition();
	}
	else{
		_display_data[0] = _7segment_table[16];
		_display_data[1] = _7segment_table[16];
		_display_data[2] = _7segment_table[16];
		_display_data[3] = _7segment_table[16];		
	}
	
	#if SEGMENT_ON == 0
		_display_data[0] = ~_display_data[0];
		_display_data[1] = ~_display_data[1];
		_display_data[2] = ~_display_data[2];
		_display_data[3] = ~_display_data[3];
	#endif
}

//***************************************************
void Display7Segment4Digit_SetValue_int(int value){
	unsigned int buffer=0;
	
	if(0<=value && value<9999){
		buffer=value;
		_7Segment4Digit_SeparateTheNumbers_PositiveInteger(buffer);
		_7Segment4Digit_RemoveExtraZero_PositiveInteger();
	}
	else if(-999<=value && value<0){
		buffer=value*(-1);
		_7Segment4Digit_SeparateTheNumbers_NegativeInteger(buffer);
		_7Segment4Digit_RemoveExtraZero_NegativeInteger();
	}
	else{
		_display_data[0] = _7segment_table[16];
		_display_data[1] = _7segment_table[16];
		_display_data[2] = _7segment_table[16];
		_display_data[3] = _7segment_table[16];		
	}

	#if SEGMENT_ON == 0
		_display_data[0] = ~_display_data[0];
		_display_data[1] = ~_display_data[1];
		_display_data[2] = ~_display_data[2];
		_display_data[3] = ~_display_data[3];
	#endif
}

//***************************************************
char Display7Segment4Digit_MultiplexLefToRight(void){
	static unsigned char i=3; 
	
	_7Segment4Digit_TurnOffDigits;
	_7Segment4Digit_DriveSegments(_display_data[i]);
	
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
	
	return 3-i;
}

//***************************************************
char Display7Segment4Digit_MultiplexRightToLeft(void){
	static unsigned char i=0; 
	
	_7Segment4Digit_TurnOffDigits;
	_7Segment4Digit_DriveSegments(_display_data[i]);

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
	
	return i;
}

//********************************************
void Display7Segment4Digit_Refresh(void){
	static unsigned int i=0;
	
	if(_display_onoff){
		++i;
		if(i>DISPLAY_LAG){
			i=0;
			#if MULTIPLEX_MODE ==0
				Display7Segment4Digit_MultiplexLefToRight();
			#else
				Display7Segment4Digit_MultiplexRightToLeft();
			#endif
		}
	}
}


