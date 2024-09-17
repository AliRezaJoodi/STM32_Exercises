// GitHub Account: GitHub.com/AliRezaJoodi

#include <display_7segment_4digit.h>

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

#define _7Segment_SetPinForOutputMode(GPIOx,PIN); \
	GPIO_SetInputOrOutputMode(GPIOx, PIN, IO_OUTPUT);\
	GPIO_OutputMode_SetGeneralPurposeOrAlternateFunction(GPIOx, PIN, OUTPUT_GP);\
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOx, PIN, OUTPUT_PUSHPULL);

#define _7segment_TurnOffAllPins \
	GPIO_WritePin(A_PORT, A_PIN, !SEGMENT_ON);\
	GPIO_WritePin(B_PORT, B_PIN, !SEGMENT_ON);\
	GPIO_WritePin(C_PORT, C_PIN, !SEGMENT_ON);\
	GPIO_WritePin(D_PORT, D_PIN, !SEGMENT_ON);\
	GPIO_WritePin(E_PORT, E_PIN, !SEGMENT_ON);\
	GPIO_WritePin(F_PORT, F_PIN, !SEGMENT_ON);\
	GPIO_WritePin(DP_PORT, DP_PIN, !SEGMENT_ON);\
	GPIO_WritePin(DIGIT0_PORT, DIGIT0_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT1_PORT, DIGIT1_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT2_PORT, DIGIT2_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT3_PORT, DIGIT3_PIN, !DIGIT_ON);
	
#define _7segment_TurnOffDigitsPins \
	GPIO_WritePin(DIGIT0_PORT, DIGIT0_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT1_PORT, DIGIT1_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT2_PORT, DIGIT2_PIN, !DIGIT_ON);\
	GPIO_WritePin(DIGIT3_PORT, DIGIT3_PIN, !DIGIT_ON);
	
#define _7segment_DriveData(data) \
	GPIO_WritePin(A_PORT, A_PIN, GetBit(data,0));\
	GPIO_WritePin(B_PORT, B_PIN, GetBit(data,1));\
	GPIO_WritePin(C_PORT, C_PIN, GetBit(data,2));\
	GPIO_WritePin(D_PORT, D_PIN, GetBit(data,3));\
	GPIO_WritePin(E_PORT, E_PIN, GetBit(data,4));\
	GPIO_WritePin(F_PORT, F_PIN, GetBit(data,5));\
	GPIO_WritePin(G_PORT, G_PIN, GetBit(data,6));\
	GPIO_WritePin(DP_PORT, DP_PIN, GetBit(data,7));

//********************************
 void _7segment_EnableBusForPorts(void){
	if(	A_PORT 			==	GPIOA || \
			B_PORT 			==	GPIOA || \
			C_PORT 			==	GPIOA || \
			D_PORT 			==	GPIOA || \
			E_PORT 			==	GPIOA || \
			F_PORT 			==	GPIOA || \
			G_PORT 			==	GPIOA || \
			DP_PORT 		==	GPIOA || \
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
			DP_PORT 		==	GPIOA || \
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
			DP_PORT 		==	GPIOA || \
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
			DP_PORT 		==	GPIOA || \
			DIGIT0_PORT	==	GPIOD || \
			DIGIT1_PORT	==	GPIOD || \
			DIGIT2_PORT	==	GPIOD || \
			DIGIT3_PORT	==	GPIOD)
		{BUS_GPIOD_EnableOrDisable(1);}	
}

//***************************************************
void Display7Segment_Config(void){
	_7segment_EnableBusForPorts();
	
	_7Segment_SetPinForOutputMode(A_PORT, A_PIN);
	_7Segment_SetPinForOutputMode(B_PORT, B_PIN);
	_7Segment_SetPinForOutputMode(C_PORT, C_PIN);
	_7Segment_SetPinForOutputMode(D_PORT, D_PIN);
	_7Segment_SetPinForOutputMode(E_PORT, E_PIN);
	_7Segment_SetPinForOutputMode(F_PORT, F_PIN);
	_7Segment_SetPinForOutputMode(G_PORT, G_PIN);
	_7Segment_SetPinForOutputMode(DP_PORT, DP_PIN);

	_7Segment_SetPinForOutputMode(DIGIT0_PORT, DIGIT0_PIN);
	_7Segment_SetPinForOutputMode(DIGIT1_PORT, DIGIT1_PIN);
	_7Segment_SetPinForOutputMode(DIGIT2_PORT, DIGIT2_PIN);
	_7Segment_SetPinForOutputMode(DIGIT3_PORT, DIGIT3_PIN);
	
	_7segment_TurnOffAllPins;
}

//********************************************
void Display7Segment_SetOnOff(char Status){
	_display_onoff = Status & 0b1;
}

//***************************************************
void Display7Segment_SetValue_uint(unsigned int value){
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
	
	if(_display_decimal==0){
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
	else if(_display_decimal==1){SetBit(_display_data[1],7);}
		else if(_display_decimal==2){SetBit(_display_data[2],7);}
			else if(_display_decimal==3){SetBit(_display_data[3],7);}
	
	if(value>9999){
			_display_data[0] = _7segment_table[16];
			_display_data[1] = _7segment_table[16];
			_display_data[2] = _7segment_table[16];
			_display_data[3] = _7segment_table[16];		
	};
	
	#if SEGMENT_ON == 0
		_display_data[0] = ~_display_data[0];
		_display_data[1] = ~_display_data[1];
		_display_data[2] = ~_display_data[2];
		_display_data[3] = ~_display_data[3];
	#endif
}

//***************************************************
void Display7Segment_SetValue_float(float value){
	unsigned int value_int=0;
	
	if(value<10){value_int=value*1000; _display_decimal=3;}
		else if(value<100){value_int=value*100; _display_decimal=2;}
			else if(value<1000){value_int=value*10; _display_decimal=1;}
				else {value_int=value; _display_decimal=0;}
	
	Display7Segment_SetValue_uint(value_int);
}

//***************************************************
char _4Digit_RefreshRightToLeft(void){
	static unsigned char i=0; 
	
	_7segment_TurnOffDigitsPins;
	_7segment_DriveData(_display_data[i]);

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
	
	return i;
}

//***************************************************
char _4Digit_RefreshLefToRight(void){
	static unsigned char i=3; 
	
	_7segment_TurnOffDigitsPins;
	_7segment_DriveData(_display_data[i]);
	
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
	
	return 3-i;
}

//********************************************
void Display7Segment_DisplayValue(void){
	static unsigned int i=0;
	
	++i;
	if(i>DISPLAY_LAG){
		i=0;
		if(_display_onoff){_4Digit_RefreshLefToRight();}
	}
}

