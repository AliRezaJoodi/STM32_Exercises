// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_timer_systick.h>

void SysTick_ConfigDefault1_INT(void){
	SysTick_SetClockSource(SYSTICK_CLKSOURCE_HCLK);
	SysTick_SetLoadValue(HCLK_VALUE/2);		// 0.5s
	SysTick_ResetCounter();
	SysTick_EnableOrDisable(1);
	SysTick_INT_EnableOrDisable(1);	
}

