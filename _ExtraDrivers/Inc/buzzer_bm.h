// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

#ifndef _BUZZER_BM_INCLUDED
#define _BUZZER_BM_INCLUDED

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

#ifndef BUZZER_HARDWARE
#define BUZZER_HARDWARE 
	#define BUZZER_ACTIVE       1     
  #define BUZZER_PIN          1
  #define BUZZER_GPIO         GPIOA
#endif

#define BEEP_UP         0
#define BEEP_DOWN       1
#define BEEP_SET        2
#define BEEP_ERROR      3

//***************************************************
void Buzzer_Config(void);
void Buzzer_MakeBeep(char);

#ifdef __cplusplus
}
#endif

#endif		// _BUZZER_BM_INCLUDED