
#include "main.h"

#include "STM32F1xx_System_BareMetal.h"
#include "STM32F1xx_RCC_BareMetal.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "Utility.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

void ConfigureRelays(void);
void ConfigureButtons(void);
void ConfigureBcdInput(void);
void ConfigureBcdDisplay(void);

void delay_ms(int i){
	int j=500*i;
	for(i=0;i<j;i++){};
}

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
	ConfigureSerialWireDebugPort(JTAG_DISABLED_AND_SWD_DISABLED);
	ConfigureButtons();
	ConfigureRelays();
	ConfigureBcdInput();
	ConfigureBcdDisplay();
	
	//SetPinFromOutput(GPIOA,15);
  while(1){
		//if(GetPinFromInput(GPIOA,1)){SetPinFromOutput(GPIOA,15);}
			//else{ResetPinFromOutput(GPIOA,15);}
		WritePinFromOutput(GPIOA,15,GetPinFromInput(GPIOA,0));	
		
		if(GetPinFromInput(GPIOA,1)==1){SetPinFromOutput(GPIOA,3);}
		if(GetPinFromInput(GPIOA,2)==0){ResetPinFromOutput(GPIOA,3);}
		
		uint32_t value= Get4PinFromInput(GPIOA,7);
		Write4PinFromOutput(GPIOA,11,value);
		
		//SetPinFromOutput(GPIOA,15); delay_ms(1000);
		//ResetPinFromOutput(GPIOA,15); delay_ms(1000);
  }
}

//**************************************
void ConfigureBcdInput(void){
	ConfigurePinForDirection(GPIOA,7,INPUT_MODE);
	ConfigurePinForInputMode(GPIOA,7,FLOATING_INPUT);
	
	ConfigurePinForDirection(GPIOA,8,INPUT_MODE);
	ConfigurePinForInputMode(GPIOA,8,FLOATING_INPUT);
	
	ConfigurePinForDirection(GPIOA,9,INPUT_MODE);
	ConfigurePinForInputMode(GPIOA,9,FLOATING_INPUT);
	
	ConfigurePinForDirection(GPIOA,10,INPUT_MODE);
	ConfigurePinForInputMode(GPIOA,10,FLOATING_INPUT);
}

//**************************************
void ConfigureBcdDisplay(void){
	ConfigurePinForDirection(GPIOA,11,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(GPIOA,11,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(GPIOA,11);
	
	ConfigurePinForDirection(GPIOA,12,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(GPIOA,12,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(GPIOA,12);
	
	ConfigurePinForDirection(GPIOA,13,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(GPIOA,13,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(GPIOA,13);
	
	ConfigurePinForDirection(GPIOA,14,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(GPIOA,14,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(GPIOA,14);
}

//**************************************
void ConfigureButtons(void){
	EnableOrDisableClockSourceForPortA(1); LL_mDelay(10);
	
	ResetPinFromOutput(GPIOA,0);
	ConfigurePinForDirection(GPIOA,0,INPUT_MODE);
	ConfigurePinForInputMode(GPIOA,0,FLOATING_INPUT);
	//ConfigurePinForInputMode(GPIOA,5,INPUT_WITH_PULLUP_PULLDOWN);
	//ConfigurePinForPullUpOrDown(GPIOA,5,PULLUP);
	
	ConfigurePinForDirection(GPIOA,1,INPUT_MODE);
	ConfigurePinForInputMode(GPIOA,1,INPUT_WITH_PULLUP_PULLDOWN);
	ConfigurePinForPullUpOrDown(GPIOA,1,PULLDOWN);
	
	ConfigurePinForDirection(GPIOA,2,INPUT_MODE);
	ConfigurePinForInputMode(GPIOA,2,INPUT_WITH_PULLUP_PULLDOWN);
	ConfigurePinForPullUpOrDown(GPIOA,2,PULLUP);
}

//**************************************
void ConfigureRelays(void){
	EnableOrDisableClockSourceForPortA(1); LL_mDelay(10);
	
	ConfigurePinForDirection(GPIOA,15,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(GPIOA,15,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(GPIOA,15);
	
	ConfigurePinForDirection(GPIOA,3,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(GPIOA,3,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(GPIOA,3);
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

