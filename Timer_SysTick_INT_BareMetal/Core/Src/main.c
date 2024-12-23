// GitHub Account: GitHub.com/AliRezaJoodi

#include "main.h"

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>

#include <stm32f1xx_bm_timer_systick.h>
#include <stm32f1xx_bm_it.h>

void LED_Config(void);

int main(void){
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugMode(SWJ_SWD);
  RCC_SystemClock_ConfigDefault1();
	SysTick_ConfigDefault2_INT();
	NVIC_Config();
	
	LED_Config();
	
  while(1){	
		//GPIO_TogglePin(GPIOC,13); SysTick_Delay_1ms(1000);
		
		//GPIO_WritePin(GPIOC,13,0); SysTick_Delay_1ms(10);
		//GPIO_WritePin(GPIOC,13,1); SysTick_Delay_1ms(1000);
  }
}

//**************************************
void LED_Config(void){
	BUS_GPIOC_EnableOrDisable(1);
	GPIO_OutputWithPushPullMode_ConfigPin(GPIOC,13);
	GPIO_SetPin(GPIOC,13);
	
}
