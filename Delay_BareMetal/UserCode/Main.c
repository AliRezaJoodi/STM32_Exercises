// GitHub Account: GitHub.com/AliRezaJoodi

#include "Utility.h"
#include "STM32F1xx_System_BareMetal.h"
#include "STM32F1xx_RCC_BareMetal.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "Delay.h"

void SystemClock_Config(void);
void LED_ConfigurePin(void);

int main(void){
	char status0=0;

  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // System interrupt init
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0)); // SysTick_IRQn interrupt configuration
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	AFIO_SetSerialWireDebugPort(FULL_SWJ);
	
  SystemClock_Configuration();
	LED_ConfigurePin();
	
  while(1){	
		GPIO_TogglePin(GPIOA,1); Delay_ms(10);
		//if(Refresh()){GPIO_TogglePin(GPIOA,1);}
  }
}

//**************************************
void LED_ConfigurePin(void){
	BUS_GPIOA_EnableOrDisable(1);
	
	GPIO_SetInputOrOutputMode(GPIOA,1, MODE_OUTPUT_2MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOA,1, OUTPUT_GPIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,1, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,1);
	
}
