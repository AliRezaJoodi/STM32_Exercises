
#ifndef _MAIN_INCLUDED
#define _MAIN_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f1xx.h>

//*****************************************
#ifndef TIMEOUT_VALUE
	#define TIMEOUT_VALUE		1000000
#endif

//*****************************************
#ifndef SYSTICK_HCLK_VALUE
	#define SYSTICK_HCLK_VALUE		8000000
#endif

//*****************************************
#ifndef DELAY_NOP_LAG
	#define DELAY_NOP_LAG		250000
#endif

//*****************************************
#ifndef DISPLAY_7SEGMENT_4DIGIT_HARDWARE
#define DISPLAY_7SEGMENT_4DIGIT_HARDWARE 
	#define MULTIPLEX_MODE	0		// 0:	Lef To Right, 1: Right To Lef	
	#define DISPLAY_LAG   	2000 //Display Lag
	#define SEGMENT_ON			0
  #define DIGIT_ON      	1
  
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
	
	#define DIGIT0_GPIO		GPIOB
  #define DIGIT0_PIN    0
		
	#define DIGIT1_GPIO		GPIOB
  #define DIGIT1_PIN    1
		
	#define DIGIT2_GPIO		GPIOB
  #define DIGIT2_PIN    2
		
	#define DIGIT3_GPIO		GPIOB
  #define DIGIT3_PIN    3
#endif


#ifdef __cplusplus
}
#endif

#endif		//_MAIN_INCLUDED
