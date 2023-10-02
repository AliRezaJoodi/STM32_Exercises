// GitHub Account: GitHub.com/AliRezaJoodi

#include "Utility.h"
#include "STM32F1xx_System_BareMetal.h"
#include "STM32F1xx_RCC_BareMetal.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"

void ConfigureRelays(void);
void ConfigureButtons(void);
void ConfigureBcdInput(void);
void ConfigureBcdDisplay(void);

int main(void){
	char status0=0;

  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // System interrupt init	
	/* SysTick_IRQn interrupt configuration */
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(0);
	AFIO_SetSerialWireDebugPort(FULL_SWJ);

  SystemClock_Configuration();
	ConfigureButtons();
	ConfigureRelays();
	ConfigureBcdInput();
	ConfigureBcdDisplay();
	
  while(1){
		GPIO_WritePin(GPIOA,3, GPIO_GetPin(GPIOA,0));	
		
		if(GPIO_GetPin(GPIOA,1)==1){GPIO_SetPin(GPIOA,4);}
		if(GPIO_GetPin(GPIOA,2)==0){GPIO_ResetPin(GPIOA,4);}
		
		uint32_t value= GPIO_Get4Pin(GPIOA,5);
		GPIO_Write4Pin(GPIOA,9, value);
  }
}

//**************************************
void ConfigureBcdInput(void){
	GPIO_SetInputOrOutputMode(GPIOA,5, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,5, INPUT_FLOATING);
	
	GPIO_SetInputOrOutputMode(GPIOA,6, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,6, INPUT_FLOATING);
	
	GPIO_SetInputOrOutputMode(GPIOA,7, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,7, INPUT_FLOATING);
	
	GPIO_SetInputOrOutputMode(GPIOA,8, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,8, INPUT_FLOATING);
}

//**************************************
void ConfigureBcdDisplay(void){
	GPIO_SetInputOrOutputMode(GPIOA,9, MODE_OUTPUT_2MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOA,9, OUTPUT_GPIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,9, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,9);
	
	GPIO_SetInputOrOutputMode(GPIOA,10, MODE_OUTPUT_2MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOA,10, OUTPUT_GPIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,10, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,10);
	
	GPIO_SetInputOrOutputMode(GPIOA,11, MODE_OUTPUT_2MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOA,11, OUTPUT_GPIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,11, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,11);
	
	GPIO_SetInputOrOutputMode(GPIOA,12, MODE_OUTPUT_2MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOA,12, OUTPUT_GPIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,12, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,12);
}

//**************************************
void ConfigureButtons(void){
	BUS_GPIOA_EnableOrDisable(1); 
	
	GPIO_SetInputOrOutputMode(GPIOA,0, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,0, INPUT_PULLUP);
	
	GPIO_SetInputOrOutputMode(GPIOA,1, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,1,INPUT_PULLDOWN);
	
	GPIO_SetInputOrOutputMode(GPIOA,2, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,2,INPUT_PULLUP);
}

//**************************************
void ConfigureRelays(void){
	BUS_GPIOA_EnableOrDisable(1);
	
	GPIO_SetInputOrOutputMode(GPIOA,3, MODE_OUTPUT_2MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOA,3, OUTPUT_GPIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,3, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,3);
	
	GPIO_SetInputOrOutputMode(GPIOA,4, MODE_OUTPUT_2MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOA,4, OUTPUT_GPIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,4, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,4);
}

