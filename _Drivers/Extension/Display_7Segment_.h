// GitHub Account: GitHub.com/AliRezaJoodi

#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "Utility.h"

#ifndef _7SEGMENT_INCLOUDED
    #define _7SEGMENT_INCLOUDED

#ifndef _7SEGMENT_PORT
    #define _7SEGMENT_PORT 
    
    #define DISPLAYLAG          5 //Display Lag
    #define ACTIVATE_DIGIT      0
    #define ACTIVATE_SEGMENT    1
      
    #define DIGIT0_GPIO         GPIOA
    #define DIGIT0_PIN          10
    
    #define A_GPIO              GPIOA
    #define A_PIN               0
    
    #define B_GPIO              GPIOA
    #define B_PIN               1
    
    #define C_GPIO              GPIOA
    #define C_PIN               2
    
    #define D_GPIO              GPIOA
    #define D_PIN               3
    
    #define E_GPIO              GPIOA
    #define E_PIN               4
    
    #define F_GPIO              GPIOA
    #define F_PIN               5
    
    #define G_GPIO              GPIOA
    #define G_PIN               6
    
    #define DP_GPIO             GPIOA
    #define DP_PIN              7
#endif

//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
//A , B , C , D , E , F,
// - , Dp
unsigned char table_7segment[18]={
    0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111,
    0b01110111 , 0b01111100 , 0b00111001 , 0b01011110 , 0b01111001 , 0b01110001 ,
    0b01000000 , 0b10000000,
 };
 	
#define _ConvertNumberTo7SegmentData(VALUE)   (table_7segment[VALUE])
#define _ToggleValue(VALUE)                		VALUE = ~VALUE;

#define _TurnOffDigits \
	WritePinFromOutput(DIGIT0_GPIO,DIGIT0_PIN,!ACTIVATE_DIGIT);\
 
#define _TurnOff7Segment \
	WritePinFromOutput(A_GPIO,A_PIN,!ACTIVATE_SEGMENT);\
	WritePinFromOutput(B_GPIO,B_PIN,!ACTIVATE_SEGMENT);\
	WritePinFromOutput(C_GPIO,C_PIN,!ACTIVATE_SEGMENT);\
	WritePinFromOutput(D_GPIO,D_PIN,!ACTIVATE_SEGMENT);\
	WritePinFromOutput(E_GPIO,E_PIN,!ACTIVATE_SEGMENT);\
	WritePinFromOutput(F_GPIO,F_PIN,!ACTIVATE_SEGMENT);\
	WritePinFromOutput(G_GPIO,G_PIN,!ACTIVATE_SEGMENT);\
	WritePinFromOutput(DP_GPIO,DP_PIN,!ACTIVATE_SEGMENT);
 
#define Configure7Segment \
	EnableOrDisableClockSourceForPortA(1);\
 	ConfigurePinForDirection(DIGIT0_GPIO,DIGIT0_PIN,OUTPUT_MODE_2MHz);\
	ConfigurePinForOutputMode(DIGIT0_GPIO,DIGIT0_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);\
	_TurnOffDigits;\
	ConfigurePinForDirection(A_GPIO,A_PIN,OUTPUT_MODE_2MHz);\
	ConfigurePinForOutputMode(A_GPIO,A_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);\
	ConfigurePinForDirection(B_GPIO,B_PIN,OUTPUT_MODE_2MHz);\
	ConfigurePinForOutputMode(B_GPIO,B_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);\
	ConfigurePinForDirection(C_GPIO,C_PIN,OUTPUT_MODE_2MHz);\
	ConfigurePinForOutputMode(C_GPIO,C_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);\
	ConfigurePinForDirection(D_GPIO,D_PIN,OUTPUT_MODE_2MHz);\
	ConfigurePinForOutputMode(D_GPIO,D_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);\
	ConfigurePinForDirection(E_GPIO,E_PIN,OUTPUT_MODE_2MHz);\
	ConfigurePinForOutputMode(E_GPIO,E_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);\
	ConfigurePinForDirection(F_GPIO,F_PIN,OUTPUT_MODE_2MHz);\
	ConfigurePinForOutputMode(F_GPIO,F_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);\
	ConfigurePinForDirection(G_GPIO,G_PIN,OUTPUT_MODE_2MHz);\
	ConfigurePinForOutputMode(G_GPIO,G_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);\
	ConfigurePinForDirection(DP_GPIO,DP_PIN,OUTPUT_MODE_2MHz);\
	ConfigurePinForOutputMode(DP_GPIO,DP_PIN,GENERAL_PURPOSE_OUTPUT_PUSHPULL);\
	_TurnOff7Segment;
 
#define _DriveDataOnSegments(data) \
	WritePinFromOutput(A_GPIO,A_PIN,GetBit(value,0));\
	WritePinFromOutput(B_GPIO,B_PIN,GetBit(value,1));\
	WritePinFromOutput(C_GPIO,C_PIN,GetBit(value,2));\
	WritePinFromOutput(D_GPIO,D_PIN,GetBit(value,3));\
	WritePinFromOutput(E_GPIO,E_PIN,GetBit(value,4));\
	WritePinFromOutput(F_GPIO,F_PIN,GetBit(value,5));\
	WritePinFromOutput(G_GPIO,G_PIN,GetBit(value,6));\
	WritePinFromOutput(DP_GPIO,DP_PIN,GetBit(value,7));
 
#endif
