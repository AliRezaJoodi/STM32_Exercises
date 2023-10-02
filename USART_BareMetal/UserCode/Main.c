// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdio.h>

#include "Utility.h"
#include "STM32F1xx_System_BareMetal.h"
#include "STM32F1xx_RCC_BareMetal.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "STM32F1xx_USART_BareMetal.h"

char usart1_txt[16]= "";
volatile char usart1_task=0;

int main(void){
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // System interrupt init
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	AFIO_SetSerialWireDebugPort(FULL_SWJ);
  SystemClock_Configuration();
  USART1_Configuration();
	//LL_mDelay(500);

	USART1_PutChar('A');USART1_PutNewLine;	
	
	USART1_PutString("Test1\r\n");	
	
	const char txt2[]= "Test2\r\n";
	USART1_PutStringFromFlash(txt2);
	
	char txt3[]= "Test3\r\n";
	USART_ClearString(txt3);
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
			USART_ClearString(usart1_txt);
		}	
  }
}





