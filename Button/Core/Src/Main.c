// GitHub Account: GitHub.com/AliRezaJoodi

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <delay.h>

uint32_t value=3;

#include <button.h>

void BcdDisplay_Config(void);

int main(void){
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // System interrupt init
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0)); // SysTick_IRQn interrupt configuration
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWJ_SWD);
  RCC_ConfigSystemClock();

	Button_Config();
	BcdDisplay_Config();
	
  while(1){
		if(Button1_OneStep()){++value;}
		if(Button2_Continuous()){++value;} 
		if(Button3_OneStep()){value=0;}
		
		GPIO_Write4Pin(GPIOA,3, value);
  }
}

//**************************************
void BcdDisplay_Config(void){
	BUS_GPIOA_EnableOrDisable(1);
	
	GPIO_ConfigPinForPushPullOutputMode(GPIOA,3);
	GPIO_ConfigPinForPushPullOutputMode(GPIOA,4);
	GPIO_ConfigPinForPushPullOutputMode(GPIOA,5);
	GPIO_ConfigPinForPushPullOutputMode(GPIOA,6);
}





