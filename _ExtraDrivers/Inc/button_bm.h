// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

#ifndef _BUTTON_INCLUDED
    #define _BUTTON_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include <utility.h>

#if defined(STM32F1)
	#include <stm32f1xx_bm_bus.h>
	#include <stm32f1xx_bm_gpio.h>
	#include <stm32f1xx_bm_timer_systick.h>
//#elif defined(STM32F4)
#else
	#error "Error: Undefined STM32 Type!"
#endif

#ifndef BUTTON_HARDWARE
#define BUTTON_HARDWARE
	#define BUTTON_PRESSED      0
  #define BUTTON_LAG1         30        //ms 
  #define BUTTON_LAG2         20000      //Button Lag
	
	#define BUTTON1_GPIO				GPIOA
  #define BUTTON1_PIN					0
    
  #define BUTTON2_GPIO				GPIOA
  #define BUTTON2_PIN         1
	
	#define BUTTON3_GPIO				GPIOA
  #define BUTTON3_PIN         2
#endif


void Button_Config(void);

#ifdef BUTTON1_PIN
	char Button1_OneStep(void);
	char Button1_Continuous(void);
#endif

#ifdef BUTTON2_PIN
	char Button2_OneStep(void);
	char Button2_Continuous(void);
#endif

#ifdef BUTTON3_PIN
	char Button3_OneStep(void);
	char Button3_Continuous(void);
#endif

#ifdef __cplusplus
}
#endif

#endif		// _BUTTON_INCLUDED