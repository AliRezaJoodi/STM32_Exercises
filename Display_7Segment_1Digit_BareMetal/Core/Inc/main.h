
#ifndef _MAIN_INCLUDED
#define _MAIN_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f1xx.h>

#ifndef HCLK_VALUE
	#define HCLK_VALUE			8000000
#endif

#ifndef PCLK1_VALUE
	#define PCLK1_VALUE			8000000
#endif

#ifndef PCLK2_VALUE
	#define PCLK2_VALUE			8000000
#endif

#ifndef TIMEOUT_VALUE
	#define TIMEOUT_VALUE		1000000
#endif

#ifndef DELAY_NOP_LAG
	#define DELAY_NOP_LAG		250000
#endif

#ifndef DISPLAY_7SEGMENT_1DIGIT_HARDWARE
#define DISPLAY_7SEGMENT_1DIGIT_HARDWARE 
	#define SEGMENT_ON		0
  #define DIGIT_ON      1
  
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
	
	#define DIGIT0_GPIO   GPIOA
  #define DIGIT0_PIN		15
#endif


#ifdef __cplusplus
}
#endif

#endif		//_MAIN_INCLUDED
