// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_exti.h>
#include <stm32f1xx_bm_nvic.h>

void OutputPin_Config(void);

int main(void){
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWJ_SWD);
  
	RCC_ConfigSystemClock();
  EXTI_Config();
	
	NVIC_ConfigGroup(NVIC_PRIORITYGROUP_4);
	NVIC_EXTI0_Config();
	NVIC_EXTI9To5_Config();
	NVIC_EXTI15To10_Config();
	
	OutputPin_Config();
	
  while(1){

  }
}

//*************************************************
void OutputPin_Config(void){
	BUS_GPIOC_EnableOrDisable(1);
	GPIO_ConfigPinForPushPullOutputMode(GPIOC,13);
	GPIO_ResetPin(GPIOC,13);
}

