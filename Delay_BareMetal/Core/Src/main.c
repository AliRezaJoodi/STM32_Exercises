
#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

void LED_ConfigurePin(void);

int main(void){
	char status0=0;
	
  //LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_AFIO);
	EnableOrDisableClockSourceForAlternateFunction(0);
  //LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
	EnableOrDisableClockSourceForPowerInterface(1);

  /* System interrupt init*/
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* SysTick_IRQn interrupt configuration */
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));

  SystemClock_Config();
	ConfigureSerialWireDebugPort(FULL_SWJ);
	LED_ConfigurePin();
	
  while(1){	
		TogglePinFromOutput(GPIOA,1); delay_ms(10);
  }
}

//**************************************
void LED_ConfigurePin(void){
	EnableOrDisableClockSourceForPortA(1);
	WaitTillEnableClockSourceForPortA;
	
	ConfigurePinForDirection(GPIOA,1,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(GPIOA,1,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(GPIOA,1);
}

//****************************************************
void SystemClock_Config(void){
  //LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
	ConfigureLatencyForFLASH(FLASH_LATENCY0);
  //while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0){}
	WaitTillRightLatency(FLASH_LATENCY0);
  //LL_RCC_HSI_SetCalibTrimming(16);
	SetCalibTrimmingFromHSI(16);
  //LL_RCC_HSI_Enable();
	EnableOrDisableClockFromHSI(1);
   /* Wait till HSI is ready */
  //while(LL_RCC_HSI_IsReady() != 1){}
	WaitTillStableClockSourceFromHSI
		
  //LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
	ConfigurePrescalerForAHB(AHB_DIV1);
  //LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
	ConfigurePrescalerForAPB1(APB1_DIV1);
  //LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
	ConfigurePrescalerForAPB2(APB2_DIV1);
  //LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);
	ConfigureSystemClockSource(SYSCLK_HSI);
   /* Wait till System clock is ready */
  //while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI){}
	//while(GetSystemClockSource != SYSCLK_HSI){}
	WaitTillRightClockSource(SYSCLK_HSI);
	
	SystemCoreClockUpdate();	
  LL_Init1msTick(8000000);
  //LL_SetSystemCoreClock(8000000);
	SetDirectlySystemCoreClock(8000000);
}

