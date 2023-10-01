// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdio.h>

#include "stm32f1xx_ll_utils.h"

#include "Utility.h"
#include "STM32F1xx_System_BareMetal.h"
#include "STM32F1xx_RCC_BareMetal.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "STM32F1xx_USART_BareMetal.h"
#include "_USART.h"

#ifndef NVIC_PRIORITYGROUP_0
	#define NVIC_PRIORITYGROUP_0	((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority, 4 bits for subpriority */
	#define NVIC_PRIORITYGROUP_1	((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority, 3 bits for subpriority */
	#define NVIC_PRIORITYGROUP_2	((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority, 2 bits for subpriority */
	#define NVIC_PRIORITYGROUP_3	((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority, 1 bit  for subpriority */
	#define NVIC_PRIORITYGROUP_4	((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority,                                                                0 bit  for subpriority */
#endif

char usart1_txt[16]= "";
volatile char usart1_task=0;

void ConfigureSystemClock(void);
void ClearString(char *str);

int main(void){
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // System interrupt init
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	AFIO_SetSerialWireDebugPort(FULL_SWJ);
  ConfigureSystemClock();
  USART1_Configuration();
	//LL_mDelay(500);

	USART1_PutChar('A');USART1_PutNewLine;	
	
	USART1_PutString("Test1\r\n");	
	
	const char txt2[]= "Test2\r\n";
	USART1_PutStringFromFlash(txt2);
	
	char txt3[]= "Test3\r\n";
	ClearString(txt3);
	USART1_PutString(txt3);
	
	sprintf(txt3, "a=%3d", 12);
	USART1_PutString(txt3); USART1_PutNewLine;
	
	sprintf(txt3, "a=%.3f", 12.3456);
	USART1_PutString(txt3); USART1_PutNewLine;
	
	unsigned int a1=0;
	a1=USART1->BRR;
	//a1 = _DIV_SAMPLING16(8000000, 9600);
	sprintf(txt3, "BRR=%d", a1);
	USART1_PutString(txt3); USART1_PutNewLine;
	
  while(1){
		if(usart1_task==1){
			usart1_task=0;
			
			USART1_PutString(usart1_txt);
			USART1_PutNewLine;
			ClearString(usart1_txt);
		}	
  }
}

//********************************
void ClearString(char *str){
  while(*str != 0){
		*str=0;
    ++str;
  }
}

//****************************************************
void ConfigureSystemClock(void){
	FLASH_SetLatency(LATENCY0);
	RCC_HSI_SetCalibTrimming(16);
	RCC_HSI_EnableOrDisable(1);
	RCC_SYSCLK_SetClockSource(SYSCLK_HSI);
	RCC_AHB_SetPrescaler(AHB_DIV1);
	RCC_APB1_SetPrescaler(APB1_DIV1);
	RCC_APB2_SetPrescaler(APB2_DIV1);
		
	SystemCoreClockUpdate();	
  LL_Init1msTick(8000000);
	System_SetCoreClockFrequency(8000000);
}



