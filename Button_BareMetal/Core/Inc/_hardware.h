
#ifndef _HARDWARE_INCLUDED
#define _HARDWARE_INCLUDED

//#define STM32F1XX_BM_TIMER_SYSTICK_HARDWARE
//	#define HCLK_VALUE		8000000
	
//#define BUTTON_HARDWARE
	#define BUTTON_PRESSED      0
  #define BUTTON_LAG1         30        //ms 
  #define BUTTON_LAG2         5000      //Button Lag
	
	#define BUTTON1_GPIO				GPIOA
  #define BUTTON1_PIN					0
    
  #define BUTTON2_GPIO				GPIOA
  #define BUTTON2_PIN         1
	
	#define BUTTON3_GPIO				GPIOA
  #define BUTTON3_PIN         2      

#endif		// _HARDWARE_INCLUDED