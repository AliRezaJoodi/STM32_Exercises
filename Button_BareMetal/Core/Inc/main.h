
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
#ifndef BUTTON_HARDWARE
#define BUTTON_HARDWARE
	#define BUTTON_PRESSED      0
  #define BUTTON_LAG1         30        //ms 
  #define BUTTON_LAG2         5000      //Button Lag
	
	#define BUTTON1_GPIO				GPIOA
  #define BUTTON1_PIN					0
    
  #define BUTTON2_GPIO				GPIOA
  #define BUTTON2_PIN         1
	
	#define BUTTON3_GPIO				GPIOA
  #define BUTTON3_PIN         2 
#endif


#ifdef __cplusplus
}
#endif


#endif		//_MAIN_INCLUDED
