// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

#ifndef DISPLAY_7SEGMENT_4DIGIT_INCLUDED
#define DISPLAY_7SEGMENT_4DIGIT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <utility.h>

#if defined(STM32F1)
	#include <stm32f1xx.h>
	#include <stm32f1xx_bm_bus.h>
	#include <stm32f1xx_bm_gpio.h>
//#elif defined(STM32F4)
#else
	#error "Error: STM32 type is not defined!"
#endif

#ifdef HARDWARE_LOCAL
	#include "_hardware.h"
#else
	#define MULTIPLEX_MODE	0		// 0: Lef To Right, 1: Right To Lef
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

void Display7Segment4Digit_Config(void);
void Display7Segment4Digit_SetOnOff(char status);
void Display7Segment4Digit_SetValue_float(float value);
void Display7Segment4Digit_SetValue_int(int value);
void Display7Segment4Digit_Refresh(void);
char Display7Segment4Digit_MultiplexLefToRight(void);
char Display7Segment4Digit_MultiplexRightToLeft(void);

#define Display7Segment4Digit_SetValue(value)		Display7Segment4Digit_SetValue_float(value)

#ifdef __cplusplus
}
#endif

#endif	// _7SEGMENT_4DIGIT_INCLUDED