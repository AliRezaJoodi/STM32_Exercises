	
#ifndef _HARDWARE_INCLUDED
#define _HARDWARE_INCLUDED

//#define STM32F1XX_BM_TIMER_SYSTICK_HARDWARE
//	#define HCLK_VALUE		8000000

//#define TIMEOUT_HARDWARE
//	#define TIMEOUT_DURATION		1000000

//#define LCD_HARDWARE
	#define LCD_RS_GPIO				GPIOA
	#define LCD_RS_PIN  			0
	#define LCD_RW_GPIO  			GPIOA		// Optional
	#define LCD_RW_PIN  			1				// Optional
	#define LCD_EN_GPIO  			GPIOA
	#define LCD_EN_PIN  			2

	#define LCD_D4_GPIO  			GPIOA
	#define LCD_D4_PIN  			4
	#define LCD_D5_GPIO  			GPIOA
	#define LCD_D5_PIN  			5
	#define LCD_D6_GPIO  			GPIOA
	#define LCD_D6_PIN  			6	
	#define LCD_D7_GPIO  			GPIOA
	#define LCD_D7_PIN  			7


#endif		// _HARDWARE_INCLUDED