
#include "main.h"

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
	AFIO_ConfigureSerialWireDebugPort(JTAG_DISABLED_AND_SWD_DISABLED);
	ConfigureButtons();
	ConfigureRelays();
	ConfigureBcdInput();
	ConfigureBcdDisplay();
	
  while(1){
		//if(GPIO_GetPin(GPIOA,1)){GPIO_SetPin(GPIOA,15);}
			//else{GPIO_ResetPin(GPIOA,15);}
		GPIO_WritePin(GPIOA,15,GPIO_GetPin(GPIOA,0));	
		
		if(GPIO_GetPin(GPIOA,1)==1){GPIO_SetPin(GPIOA,3);}
		if(GPIO_GetPin(GPIOA,2)==0){GPIO_ResetPin(GPIOA,3);}
		
		uint32_t value= GPIO_Get4Pin(GPIOA,7);
		GPIO_Write4Pin(GPIOA,11,value);
		
		//GPIO_SetPin(GPIOA,15); delay_ms(1000);
		//GPIO_ResetPin(GPIOA,15); delay_ms(1000);
  }
}

//**************************************
void ConfigureBcdInput(void){
	GPIO_ConfigurePinDirection(GPIOA,7,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(GPIOA,7,FLOATING_INPUT);
	
	GPIO_ConfigurePinDirection(GPIOA,8,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(GPIOA,8,FLOATING_INPUT);
	
	GPIO_ConfigurePinDirection(GPIOA,9,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(GPIOA,9,FLOATING_INPUT);
	
	GPIO_ConfigurePinDirection(GPIOA,10,INPUT_MODE);
	GPIO_ConfigureInputTypeForPin(GPIOA,10,FLOATING_INPUT);
}

//**************************************
void ConfigureBcdDisplay(void){
	GPIO_ConfigurePinDirection(GPIOA,11,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,11,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,11);
	
	GPIO_ConfigurePinDirection(GPIOA,12,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,12,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,12);
	
	GPIO_ConfigurePinDirection(GPIOA,13,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,13,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,13);
	
	GPIO_ConfigurePinDirection(GPIOA,14,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,14,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,14);
}

//**************************************
void ConfigureButtons(void){
	EnableOrDisableClockSourceForPortA(1); LL_mDelay(10);
	
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
	EnableOrDisableClockSourceForPortA(1); LL_mDelay(10);
	
	GPIO_ConfigurePinDirection(GPIOA,15,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,15,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,15);
	
	GPIO_ConfigurePinDirection(GPIOA,3,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,3,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,3);
}

//****************************************************
void SystemClock_Config(void){
  //LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
	ConfigureLatencyForFLASH(FLASH_LATENCY0);
  //while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0){}
	WaitTillRightLatency(FLASH_LATENCY0);
  //LL_RCC_HSI_SetCalibTrimming(16);
	RCC_SetCalibTrimmingFromHSI(16);
  //LL_RCC_HSI_Enable();
	RCC_EnableOrDisableClockFromHSI(1);
   /* Wait till HSI is ready */
  //while(LL_RCC_HSI_IsReady() != 1){}
	RCC_WaitTillStableClockSourceFromHSI
		
  //LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
	RCC_ConfigurePrescalerForAHB(AHB_DIV1);
  //LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
	RCC_ConfigurePrescalerForAPB1(APB1_DIV1);
  //LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
	RCC_ConfigurePrescalerForAPB2(APB2_DIV1);
  //LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);
	RCC_ConfigureSystemClockSource(SYSCLK_HSI);
   /* Wait till System clock is ready */
  //while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI){}
	//while(GetSystemClockSource != SYSCLK_HSI){}
	RCC_WaitTillRightClockSource(SYSCLK_HSI);
	
	SystemCoreClockUpdate();	
  LL_Init1msTick(8000000);
  //LL_SetSystemCoreClock(8000000);
	SetDirectlySystemCoreClock(8000000);
}

