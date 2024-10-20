
#define STM32F1XX_BM_TIMER_SYSTICK_HARDWARE
	#define HCLK_VALUE		8000000
	
#ifndef _HARDWARE_INCLUDED
#define _HARDWARE_INCLUDED

#define TIMEOUT_HARDWARE
	#define TIMEOUT_DURATION		1000000

#define LCD_HARDWARE
	#define RS_GPIO  			GPIOA
	#define RS_PIN  			0
	#define RW_GPIO  			GPIOA		// Optional
	#define RW_PIN  			1				// Optional
	#define EN_GPIO  			GPIOA
	#define EN_PIN  			2

	#define D4_GPIO  			GPIOA
	#define D4_PIN  			4
	#define D5_GPIO  			GPIOA
	#define D5_PIN  			5
	#define D6_GPIO  			GPIOA
	#define D6_PIN  			6	
	#define D7_GPIO  			GPIOA
	#define D7_PIN  			7

#endif		// _HARDWARE_INCLUDED