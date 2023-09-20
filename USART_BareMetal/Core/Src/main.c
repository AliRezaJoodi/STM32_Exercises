// GitHub Account: GitHub.com/AliRezaJoodi

#include "main.h"

//#include <stdio.h>
#include "Utility.h"
#include "STM32F1xx_RCC_BareMetal.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "STM32F1xx_USART_BareMetal.h"

//uint8_t i2=0;
uint8_t j=0;
volatile uint8_t task_usart1=0;
char txt[16]= "";

void ConfigureSystemClock(void);
static void ConfigureUSART1(void);


int main(void){
  /* System interrupt init*/
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	
	BUS_EnableClockForPWR;
	BUS_EnableClockForAFIO;
	AFIO_ConfigureSerialWireDebugPort(FULL_SWJ);

  ConfigureSystemClock();
  ConfigureUSART1();
	
	LL_USART_EnableIT_RXNE(USART1);
	LL_mDelay(500);
	
	USART1_PutStringFromFlash("Test1\r\n");
	
	const char txt2[]= "Test2\r\n";
	USART1_PutStringFromFlash(txt2);
	
	char txt3[]= "Test3\r\n";
	USART1_PutString(txt3);
	/*
	while(i2<6){
		LL_USART_TransmitData8(USART1, NAME[i2++]);
		while(!LL_USART_IsActiveFlag_TXE(USART1)){};
	}
	*/
	
	//LL_USART_TransmitData8(USART1, 13);
	//while(!LL_USART_IsActiveFlag_TXE(USART1))
	
  while(1){
		if(task_usart1==1){
			task_usart1=0;
			//USART1_PutChar(13);
			USART1_PutString(txt);
			USART1_PutStringFromFlash("\r\n");
			for(j=0;j<16;++j){txt[j]=0;};
			//while(txt[j] != 0){txt[j]=0;}
		}
		/*
		if (j<5 && x==1){
			LL_USART_TransmitData8(USART1, Value_RX[j++]);
			while(!LL_USART_IsActiveFlag_TXE(USART1)){};
		}
		if(j==5){j=0; x=0;}
		*/
  }
}

//****************************************************
void ConfigureSystemClock(void){
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0){}
  LL_RCC_HSI_SetCalibTrimming(16);
  LL_RCC_HSI_Enable();

   /* Wait till HSI is ready */
  while(LL_RCC_HSI_IsReady() != 1){}
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI){}
  LL_Init1msTick(8000000);
  LL_SetSystemCoreClock(8000000);
}

//****************************************************
//PA9 -> USART1_TX
//PA10 -> USART1_RX
static void ConfigureUSART1(void){
	BUS_EnableClockForPortA;
	GPIO_ConfigureOutputMode_50MHz(GPIOA,9);
	GPIO_OutputMode_ConfigureAFIO(GPIOA,9);
	GPIO_OutputMode_ConfigurePushPull(GPIOA,9);
	GPIO_ConfigureInputMode(GPIOA,10);
	GPIO_InputMode_ConfigureFloatingInput(GPIOA,10);
	//GPIO_ConfigureInputOrOutputMode(GPIOA,9,OUTPUT_MODE_50MHz);
	//GPIO_ConfigureFeatureOfOutputPin(GPIOA,9,ALTERNATE_FUNCTION_OUTPUT_PUSHPULL);
	//GPIO_ConfigureInputOrOutputMode(GPIOA,10,INPUT_MODE);
	//GPIO_ConfigureFeatureOfInputPin(GPIOA,10,FLOATING_INPUT);
	
	USART1_ConfigureNVIC();
	BUS_EnableClockForUSART1;
	
  LL_USART_InitTypeDef USART_InitStruct = {0};

  USART_InitStruct.BaudRate = 9600;
  USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
  USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
  USART_InitStruct.Parity = LL_USART_PARITY_NONE;
  USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
  USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
  USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
  LL_USART_Init(USART1, &USART_InitStruct);
  LL_USART_ConfigAsyncMode(USART1);
  LL_USART_Enable(USART1);
}

