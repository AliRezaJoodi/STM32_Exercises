// GitHub Account: GitHub.com/AliRezaJoodi

#include "main.h"

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>

#include <stm32f1xx_bm_timer_systick.h>
#include <delay_nop.h>
#define Delay_us(VALUE)		DelayNop_us(VALUE)
#define Delay_ms(VALUE)		DelayNop_ms(VALUE)

#include <buzzer_bm.h>

int main(void){
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugMode(SWJ_SWD);
  RCC_SystemClock_ConfigDefault1();

	Buzzer_Config();
	Buzzer_MakeBeep(BEEP_SET);
	
  while(1){	
  }
}


