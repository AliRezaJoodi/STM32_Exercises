// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include <utility.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>

#ifndef _7SEGMENT_1DIGIT_INCLUDED
#define _7SEGMENT_1DIGIT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _7SEGMENT_PORT
	#define _7SEGMENT_PORT 
	
	#define SEGMENT_ON		0
  #define DIGIT_ON      1
  
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
	
	#define DIGIT0_PORT   GPIOA
  #define DIGIT0_PIN		15
#endif

void SevenSegment_Configuration(void);
void SevenSegment_SetOnOff(char status);
void SevenSegment_DisplayValue(unsigned char number);


#ifdef __cplusplus
}
#endif

#endif	// _7SEGMENT1DIGIT_INCLUDED