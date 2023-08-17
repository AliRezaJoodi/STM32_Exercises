
#include "main.h"

#include "STM32F103_System_BareMetal.h"
#include "STM32F103_RCC_BareMetal.h"
#include "STM32F103_BUS_BareMetal.h"
#include "STM32F103_GPIO_BareMetal.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

void ConfigureRelays(void);
void ConfigureButtons(void);
void ConfigureBcdInput(void);
void ConfigureBcdDisplay(void);

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

  /** DISABLE: JTAG-DP Disabled and SW-DP Disabled
  */
  //LL_GPIO_AF_DisableRemap_SWJ();

  SystemClock_Config();
  MX_GPIO_Init();

	ConfigureSerialWireDebugPort(JTAG_DISABLED_AND_SWD_DISABLED);
	ConfigureButtons();
	ConfigureRelays();
	
	//GPIO_ConfigurePinDirection(GPIOA,14,INPUT_MODE);
	//GPIO_ConfigureInputMode(GPIOA,15,INPUT_WITH_PULLUP_PULLDOWN);
	//GPIO_ConfigurePullUpOrPullDown(GPIOA,15,PULLDOWN);
	//GPIO_SetOutputPinWithODR(GPIOA,0);
	
	//if(IsEnableClockSourceForPortA==1){GPIO_SetOutputPin(GPIOB,0);}
			//else if(IsEnableClockSourceForPortA==0){GPIO_ResetOutputPin(GPIOB,0);}
	//ResetClockSourceForPortA;
	GPIO_ToggleOutputPin(GPIOA,15); //GPIO_ToggleOutputPin(GPIOA,15);		
  while(1){
		/*
		if(GPIO_GetInputPin(GPIOA,5)==0 && status0==1){
				status0=0;
				GPIO_ToggleOutputPin(GPIOA,15);
		}
		*/
		if(GPIO_GetInputPin(GPIOA,5)==0){status0=1; GPIO_ResetOutputPin(GPIOA,15);}
		//GPIO_ToggleOutputPin(GPIOA,0); LL_mDelay(1000);
		//GPIO_WriteOutputPin(GPIOA,0,GPIO_GetInputPin(GPIOA,2));
		if(GPIO_GetInputPin(GPIOA,1)==1){GPIO_SetOutputPin(GPIOA,3);}
		if(GPIO_GetInputPin(GPIOA,2)==0){GPIO_ResetOutputPin(GPIOA,3);}
  }
}

//**************************************
void ConfigureButtons(void){
	EnableOrDisableClockSourceForPortA(1); LL_mDelay(10);
	
	GPIO_ConfigurePinDirection(GPIOA,5,INPUT_MODE);
	//GPIO_ConfigureInputMode(GPIOA,5,FLOATING_INPUT);
	GPIO_ConfigureInputMode(GPIOA,5,INPUT_WITH_PULLUP_PULLDOWN);
	GPIO_ConfigurePullUpOrPullDown(GPIOA,5,PULLUP);
	
	GPIO_ConfigurePinDirection(GPIOA,1,INPUT_MODE);
	GPIO_ConfigureInputMode(GPIOA,1,INPUT_WITH_PULLUP_PULLDOWN);
	GPIO_ConfigurePullUpOrPullDown(GPIOA,1,PULLDOWN);
	
	GPIO_ConfigurePinDirection(GPIOA,2,INPUT_MODE);
	GPIO_ConfigureInputMode(GPIOA,2,INPUT_WITH_PULLUP_PULLDOWN);
	GPIO_ConfigurePullUpOrPullDown(GPIOA,2,PULLUP);
}

//**************************************
void ConfigureRelays(void){
	EnableOrDisableClockSourceForPortA(1); LL_mDelay(10);
	
	GPIO_ConfigurePinDirection(GPIOA,15,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputMode(GPIOA,15,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetOutputPin(GPIOA,15);
	
	GPIO_ConfigurePinDirection(GPIOA,3,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputMode(GPIOA,3,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetOutputPin(GPIOA,3);
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

//****************************************************
static void MX_GPIO_Init(void){
  //LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  //LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);
	
	//DisableClockSourceFromPortA; LL_mDelay(10);
	//EnableOrDisableClockSourceForPortA(0); LL_mDelay(10);
	//RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPAEN);
	//while(IsEnableClockSourceForPortA){}
  /**/
  //LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_0);
	//GPIOA->BSRR=(0x1UL<<0);
	//GPIOA->BRR=(0x1UL<<0);

	//GPIO_ResetOutputPin(GPIOA, 0);
	//GPIO_ResetOutputPinWithBSRR(GPIOA,0);
	//GPIO_SetOutputPinWithODR(GPIOA,0);
	//GPIO_ResetOutputPinWithODR(GPIOA,0);
	//GPIO_ToggleOutputPin(GPIOA,0);
	//GPIO_WriteOutputPin(GPIOA,0,0);	
	
	//if(GPIO_GetOutputPin(GPIOA,0)){GPIO_SetOutputPinWithODR(GPIOA,1);}
		//else{GPIO_ResetOutputPinWithODR(GPIOA,1);}
  /**/
  //LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_1);
	//GPIO_SetOutputPin(GPIOA,1);
	//GPIO_ResetOutputPin(GPIOA, 1);
	//GPIO_ResetOutputPinWithBSRR(GPIOA,1);
	//GPIO_SetOutputPinWithODR(GPIOA,1);
	//GPIO_ResetOutputPinWithODR(GPIOA,1);
	
  /**/
/*	
  GPIO_InitStruct.Pin = LL_GPIO_PIN_14;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
*/
  /**/
	/*
  GPIO_InitStruct.Pin = LL_GPIO_PIN_15;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
*/
  /**/
	/*
  GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
*/
  //LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOB);
	/*
	EnableOrDisableClockSourceForPortB(ENABLE);
  GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	*/
	//EnableOrDisableClockSourceForPortB(1); LL_mDelay(10);
	//GPIO_ConfigurePinDirection(GPIOB,0,OUTPUT_MODE_2MHz);
	//GPIO_ConfigureOutputMode(GPIOB,0,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	//GPIO_SetOutputPin(GPIOB,0);
}

