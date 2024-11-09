// GitHub Account: GitHub.com/AliRezaJoodi

#include "main.h"

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_exti.h>

#include <stm32f1xx_bm_it.h>

void OutputPin_Config(void);

int main(void){
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugMode(SWJ_SWD);
	RCC_SystemClock_ConfigDefault1();
  EXTI_ConfigDefault1();
	NVIC_Config();
	
	OutputPin_Config();
	
  while(1){

  }
}

//*************************************************
void OutputPin_Config(void){
	BUS_GPIOC_EnableOrDisable(1);
	GPIO_OutputWithPushPullMode_ConfigPin(GPIOC,13);
	GPIO_ResetPin(GPIOC,13);
}

