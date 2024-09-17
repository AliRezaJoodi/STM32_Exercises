// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include <Utility.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>

#ifndef _7SEGMENT_4DIGIT_INCLUDED
#define _7SEGMENT_4DIGIT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _7SEGMENT_PORT
	#define _7SEGMENT_PORT 

	#define DISPLAY_LAG   3000 //Display Lag
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
	
	#define DIGIT0_PORT		GPIOB
  #define DIGIT0_PIN    3
		
	#define DIGIT1_PORT		GPIOB
  #define DIGIT1_PIN    2
		
	#define DIGIT2_PORT		GPIOB
  #define DIGIT2_PIN    1
		
	#define DIGIT3_PORT		GPIOB
  #define DIGIT3_PIN    0
#endif

void SevenSegment_Configuration(void);
void SevenSegment_SetOnOff(char status);
void SevenSegment_SetValue_uint(unsigned int value);
void SevenSegment_SetValue_float(float value);
void SevenSegment_DisplayValue(void);

#define SevenSegment_SetValue(value)				SevenSegment_SetValue_float(value)

#ifdef __cplusplus
}
#endif

#endif	// _7SEGMENT_4DIGIT_INCLUDED