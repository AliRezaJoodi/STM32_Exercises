// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_timer_systick.h>

#define SYSTICK_CLKSOURCE_HCLK_DIV8		0b0UL		// HCLK Frequency/8
#define SYSTICK_CLKSOURCE_HCLK				0b1UL		// HCLK Frequency

//**************************************************
void SysTick_Delay_1us(uint32_t us){
	SysTick_SetClockSource(SYSTICK_CLKSOURCE_HCLK);
	SysTick_SetLoadValue(HCLK_VALUE/1000000);
	SysTick_ResetCounter();
	SysTick_EnableOrDisable(1);
	
	for (uint32_t i=0; i<us; ++i){
		while( GetBit(SysTick->CTRL,SysTick_CTRL_COUNTFLAG_Pos)==0 );
  }
	
	SysTick_EnableOrDisable(0);
}

//**************************************************
void SysTick_Delay_1ms(uint32_t ms){
	SysTick_SetClockSource(SYSTICK_CLKSOURCE_HCLK);
	SysTick_SetLoadValue(HCLK_VALUE/1000);
	SysTick_ResetCounter();
	SysTick_EnableOrDisable(1);
	
	for (uint32_t i=0; i<ms; ++i){
		while( GetBit(SysTick->CTRL,SysTick_CTRL_COUNTFLAG_Pos)==0 );
  }
	
	SysTick_EnableOrDisable(0);
}

//**************************************************
void SysTick_ConfigDefault1_1ms(void){
	SysTick_SetClockSource(SYSTICK_CLKSOURCE_HCLK);
	SysTick_SetLoadValue(HCLK_VALUE/1000);
	SysTick_ResetCounter();
	SysTick_EnableOrDisable(1);
	SysTick_INT_EnableOrDisable(0);	
}

//**************************************************
void SysTick_ConfigDefault2_INT(void){
	SysTick_SetClockSource(SYSTICK_CLKSOURCE_HCLK);
	SysTick_SetLoadValue(HCLK_VALUE/2);		// 0.5s
	SysTick_ResetCounter();
	SysTick_EnableOrDisable(1);
	SysTick_INT_EnableOrDisable(1);	
}


