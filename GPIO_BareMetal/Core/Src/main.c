
#include "main.h"

#include "Utility.h"
#include "STM32F1xx_System_BareMetal.h"
#include "STM32F1xx_RCC_BareMetal.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

void ConfigureRelays(void);
void ConfigureButtons(void);
void ConfigureBcdInput(void);
void ConfigureBcdDisplay(void);

int main(void){
	char status0=0;
	
	BUS_EnableOrDisableClockForAlternateFunction(0);
	BUS_EnableOrDisableClockForPowerInterface(1);

  /* System interrupt init*/
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* SysTick_IRQn interrupt configuration */
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));

  SystemClock_Config();
	AFIO_ConfigureSerialWireDebugPort(FULL_SWJ);
	ConfigureButtons();
	ConfigureRelays();
	ConfigureBcdInput();
	ConfigureBcdDisplay();
	
  while(1){
		GPIO_WritePin(GPIOA,3,GPIO_GetPin(GPIOA,0));	
		
		if(GPIO_GetPin(GPIOA,1)==1){GPIO_SetPin(GPIOA,4);}
		if(GPIO_GetPin(GPIOA,2)==0){GPIO_ResetPin(GPIOA,4);}
		
		uint32_t value= GPIO_Get4Pin(GPIOA,5);
		GPIO_Write4Pin(GPIOA,9,value);
  }
}

//**************************************
void ConfigureBcdInput(void){
	GPIO_ConfigurePinDirection(GPIOA,5,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(GPIOA,5,FLOATING_INPUT);
	
	GPIO_ConfigurePinDirection(GPIOA,6,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(GPIOA,6,FLOATING_INPUT);
	
	GPIO_ConfigurePinDirection(GPIOA,7,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(GPIOA,7,FLOATING_INPUT);
	
	GPIO_ConfigurePinDirection(GPIOA,8,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(GPIOA,8,FLOATING_INPUT);
}

//**************************************
void ConfigureBcdDisplay(void){
	GPIO_ConfigurePinDirection(GPIOA,9,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,9,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,9);
	
	GPIO_ConfigurePinDirection(GPIOA,10,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,10,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,10);
	
	GPIO_ConfigurePinDirection(GPIOA,11,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,11,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,11);
	
	GPIO_ConfigurePinDirection(GPIOA,12,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,12,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,12);
}

//**************************************
void ConfigureButtons(void){
	BUS_EnableOrDisableClockForPortA(1); 
	BUS_WaitTillEnableClockForPortA;
	
	GPIO_ConfigurePinDirection(GPIOA,0,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(GPIOA,0,INPUT_WITH_PULLUP_PULLDOWN);
	GPIO_ConfigurePullUpOrPullDown(GPIOA,0,PULLUP);
	
	GPIO_ConfigurePinDirection(GPIOA,1,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(GPIOA,1,INPUT_WITH_PULLUP_PULLDOWN);
	GPIO_ConfigurePullUpOrPullDown(GPIOA,1,PULLDOWN);
	
	GPIO_ConfigurePinDirection(GPIOA,2,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(GPIOA,2,INPUT_WITH_PULLUP_PULLDOWN);
	GPIO_ConfigurePullUpOrPullDown(GPIOA,2,PULLUP);
}

//**************************************
void ConfigureRelays(void){
	BUS_EnableOrDisableClockForPortA(1); BUS_WaitTillEnableClockForPortA;
	
	GPIO_ConfigurePinDirection(GPIOA,3,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,3,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,3);
	
	GPIO_ConfigurePinDirection(GPIOA,4,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,4,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,4);
}

//****************************************************
void SystemClock_Config(void){
	FLASH_ConfigureLatency(FLASH_LATENCY0);
	FLASH_WaitTillRightLatency(FLASH_LATENCY0);
	RCC_SetCalibTrimmingFromHSI(16);
	RCC_EnableOrDisableClockFromHSI(1);
	RCC_WaitTillStableClockSourceFromHSI
		
	RCC_ConfigurePrescalerForAHB(AHB_DIV1);
	RCC_ConfigurePrescalerForAPB1(APB1_DIV1);
	RCC_ConfigurePrescalerForAPB2(APB2_DIV1);
	RCC_ConfigureSourceForSYSCLK(SYSCLK_HSI);
	RCC_WaitTillRightSourceForSYSCLK(SYSCLK_HSI);
	
	SystemCoreClockUpdate();	
  LL_Init1msTick(8000000);
	SetDirectlySystemCoreClock(8000000);
}

