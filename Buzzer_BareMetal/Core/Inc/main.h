
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

#ifndef BUZZER_HARDWARE
#define BUZZER_HARDWARE 
	#define BUZZER_ACTIVE       1     
  #define BUZZER_PIN          1
  #define BUZZER_GPIO         GPIOA
#endif


#ifdef __cplusplus
}
#endif

#endif		//_MAIN_INCLUDED
