// GitHub Account: GitHub.com/AliRezaJoodi

#include "utility.h"
#include "stm32f1xx_bm_system.h"
#include "stm32f1xx_bm_rcc.h"
#include "stm32f1xx_bm_bus.h"
#include "stm32f1xx_bm_gpio.h"
#include "delay.h"

#include "_SystemClock.h"
//void SystemClock_Config(void);
void LED_Config(void);

int main(void){
	char status0=0;

  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // System interrupt init
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0)); // SysTick_IRQn interrupt configuration
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	AFIO_SetSerialWireDebugPort(JTAG_DISABLED_AND_SWD_ENABLED);
	
  SystemClock_Config();
	LED_Config();
	
  while(1){	
		//GPIO_TogglePin(GPIOC,13); Delay_ms(1000);
		//if(Refresh()){GPIO_TogglePin(GPIOA,1);}
		GPIO_ResetPin(GPIOC,13); Delay_ms(10);
		GPIO_SetPin(GPIOC,13); Delay_ms(1000); 
  }
}

//**************************************
void LED_Config(void){
	BUS_GPIOC_EnableOrDisable(1);
	
	GPIO_SetInputOrOutputMode(GPIOC,13, MODE_OUTPUT_2MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOC,13, OUTPUT_GPIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOC,13, OUTPUT_PUSHPULL);
	GPIO_SetPin(GPIOC,13);
	
}
