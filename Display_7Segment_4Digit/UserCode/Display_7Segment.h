// GitHub Account: GitHub.com/AliRezaJoodi

#include "stm32f1xx.h"
#include "Utility.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"

#ifndef _7SEGMENT_INCLUDED
    #define _7SEGMENT_INCLUDED

#ifdef __cplusplus
	extern "C" {
#endif

#ifndef _7SEGMENT_PORT
	#define _7SEGMENT_PORT 

	#define SEGMENT_ON		0
    
	#define A_PORT				GPIOA
  #define A_PIN					0
    
  #define B_PORT				GPIOA
  #define B_PIN         1
    
  #define C_PORT        GPIOA
  #define C_PIN         2
    
  #define D_PORT        GPIOA
  #define D_PIN         3
    
  #define E_PORT        GPIOA
  #define E_PIN         4
    
  #define F_PORT        GPIOA
  #define F_PIN         5
    
  #define G_PORT        GPIOA
  #define G_PIN         6
    
  #define DP_PORT       GPIOA
  #define DP_PIN        7
#endif

#define _7Segment_SetPinForOutputMode(GPIOx, PIN); \
	GPIO_SetInputOrOutputMode(GPIOx, PIN, MODE_OUTPUT_2MHz);\
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOx, PIN, OUTPUT_GPIO);\
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOx, PIN, OUTPUT_PUSHPULL);

#define _7segment_SegmentsPins_Configuration \
	_7Segment_SetPinForOutputMode(A_PORT, A_PIN);\
	_7Segment_SetPinForOutputMode(B_PORT, B_PIN);\
	_7Segment_SetPinForOutputMode(C_PORT, C_PIN);\
	_7Segment_SetPinForOutputMode(D_PORT, D_PIN);\
	_7Segment_SetPinForOutputMode(E_PORT, E_PIN);\
	_7Segment_SetPinForOutputMode(F_PORT, F_PIN);\
	_7Segment_SetPinForOutputMode(G_PORT, G_PIN);\
	_7Segment_SetPinForOutputMode(DP_PORT, DP_PIN);

#define _7segment_SegmentsPins_TurnOff \
	GPIO_WritePin(A_PORT, A_PIN, !SEGMENT_ON);\
	GPIO_WritePin(B_PORT, B_PIN, !SEGMENT_ON);\
	GPIO_WritePin(C_PORT, C_PIN, !SEGMENT_ON);\
	GPIO_WritePin(D_PORT, D_PIN, !SEGMENT_ON);\
	GPIO_WritePin(E_PORT, E_PIN, !SEGMENT_ON);\
	GPIO_WritePin(F_PORT, F_PIN, !SEGMENT_ON);\
	GPIO_WritePin(DP_PORT, DP_PIN, !SEGMENT_ON);
	
#define _DriveDataOn7Segment(data) \
	GPIO_WritePin(A_PORT, A_PIN, GetBit(data,0));\
	GPIO_WritePin(B_PORT, B_PIN, GetBit(data,1));\
	GPIO_WritePin(C_PORT, C_PIN, GetBit(data,2));\
	GPIO_WritePin(D_PORT, D_PIN, GetBit(data,3));\
	GPIO_WritePin(E_PORT, E_PIN, GetBit(data,4));\
	GPIO_WritePin(F_PORT, F_PIN, GetBit(data,5));\
	GPIO_WritePin(G_PORT, G_PIN, GetBit(data,6));\
	GPIO_WritePin(DP_PORT, DP_PIN, GetBit(data,7));

void SevenSegment_1Digit_Configuration(void);
void SevenSegment_1Digit_Number(unsigned char value);
void SevenSegment_4Digit_Configuration(void);
void SevenSegment_4Digit_UpdateNumbers_uint(unsigned int value);
void SevenSegment_4Digit_UpdateNumbers_float(float value);
void SevenSegment_4Digit_Refresh(char onoff);


#ifdef __cplusplus
	}
#endif

#endif