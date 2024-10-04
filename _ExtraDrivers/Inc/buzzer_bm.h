// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

#include <stm32f1xx.h>

#include <utility.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_timer_systick.h>

#ifdef HARDWARE_LOCAL
	#include "_hardware.h"
#endif

#ifndef _BUZZER_BM_INCLUDED
#define _BUZZER_BM_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BUZZER_BM_HARDWARE
#define BUZZER_BM_HARDWARE
	#define BUZZER_ACTIVE       1     
  #define BUZZER_PIN          1
  #define BUZZER_GPIO         GPIOA
#endif

void Buzzer_Config(void);

#define BEEP_UP         0
#define BEEP_DOWN       1
#define BEEP_SET        2
#define BEEP_ERROR      3
void Buzzer_MakeBeep(char);

#ifdef __cplusplus
}
#endif

#endif		// _BUZZER_BM_INCLUDED