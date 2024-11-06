
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

#ifndef LCD_HARDWARE
#define LCD_HARDWARE
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
#endif


#ifdef __cplusplus
}
#endif


#endif		//_MAIN_INCLUDED
