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
    
	#define DISPLAYLAG    5 //Display Lag
	#define SEGMENT_ON		0
    
	#define A_GPIO				GPIOA
  #define A_PIN					0
    
  #define B_GPIO				GPIOA
  #define B_PIN         1
    
  #define C_GPIO        GPIOA
  #define C_PIN         2
    
  #define D_GPIO        GPIOA
  #define D_PIN         3
    
  #define E_GPIO        GPIOA
  #define E_PIN         4
    
  #define F_GPIO        GPIOA
  #define F_PIN         5
    
  #define G_GPIO        GPIOA
  #define G_PIN         6
    
  #define DP_GPIO       GPIOA
  #define DP_PIN        7
#endif

#define _ConfigurePinFor7Segment(GPIOx, PIN); \
	GPIO_SetInputOrOutputMode(GPIOx, PIN, MODE_OUTPUT_2MHz);\
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOx, PIN, OUTPUT_GPIO);\
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOx, PIN, OUTPUT_PUSHPULL);

#define _ConfigureSegmentsPins \
	_ConfigurePinFor7Segment(A_GPIO, A_PIN);\
	_ConfigurePinFor7Segment(B_GPIO, B_PIN);\
	_ConfigurePinFor7Segment(C_GPIO, C_PIN);\
	_ConfigurePinFor7Segment(D_GPIO, D_PIN);\
	_ConfigurePinFor7Segment(E_GPIO, E_PIN);\
	_ConfigurePinFor7Segment(F_GPIO, F_PIN);\
	_ConfigurePinFor7Segment(G_GPIO, G_PIN);\
	_ConfigurePinFor7Segment(DP_GPIO, DP_PIN);

#define _OffSegmentsPins \
	GPIO_WritePin(A_GPIO, A_PIN, !SEGMENT_ON);\
	GPIO_WritePin(B_GPIO, B_PIN, !SEGMENT_ON);\
	GPIO_WritePin(C_GPIO, C_PIN, !SEGMENT_ON);\
	GPIO_WritePin(D_GPIO, D_PIN, !SEGMENT_ON);\
	GPIO_WritePin(E_GPIO, E_PIN, !SEGMENT_ON);\
	GPIO_WritePin(F_GPIO, F_PIN, !SEGMENT_ON);\
	GPIO_WritePin(DP_GPIO, DP_PIN, !SEGMENT_ON);
	
#define _DriveDataOn7Segment(data) \
	GPIO_WritePin(A_GPIO, A_PIN, GetBit(data,0));\
	GPIO_WritePin(B_GPIO, B_PIN, GetBit(data,1));\
	GPIO_WritePin(C_GPIO, C_PIN, GetBit(data,2));\
	GPIO_WritePin(D_GPIO, D_PIN, GetBit(data,3));\
	GPIO_WritePin(E_GPIO, E_PIN, GetBit(data,4));\
	GPIO_WritePin(F_GPIO, F_PIN, GetBit(data,5));\
	GPIO_WritePin(G_GPIO, G_PIN, GetBit(data,6));\
	GPIO_WritePin(DP_GPIO, DP_PIN, GetBit(data,7));

void SevenSegment_1Digit_Configuration(void);
void SevenSegment_1Digit_Number(unsigned char value);
void SevenSegment_4Digit_Configuration(void);
void SevenSegment_4Digit_UpdateNumbers_uint(unsigned int value);
void SevenSegment_4Digit_RefreshRightToLeft_uint(void);

#ifdef __cplusplus
	}
#endif

#endif