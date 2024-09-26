// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include <stdio.h>

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_usart.h>
#include <stm32f1xx_bm_nvic.h>

char usart1_txt[16]="";
volatile char usart1_task=0;
float number = 12.3456;

int main(void){
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWJ_SWD);
  RCC_ConfigSystemClock();
  USART1_Config();
	NVIC_Config();

	USART1_PutChar('A'); USART1_PutNewLine;	
	
	USART1_PutString("Test1");	
	
	const char txt2[]= "Test2";
	USART1_PutStringFromFlash(txt2);
	
	char txt3[]= "Test3";
	USART_ClearString(txt3);
	USART1_PutString(txt3);
	
	sprintf(txt3, "a=%3d", 12);
	USART1_PutString(txt3);
	
	///sprintf(txt3, "a=%0.3f", 12.3456);
	//sprintf(txt3, "a=%.3f", number);
	//USART1_PutString(txt3);
	
	unsigned int a1=0;
	a1=USART1->BRR;
	//a1 = _DIV_SAMPLING16(8000000, 9600);
	sprintf(txt3, "BRR=%d", a1);
	USART1_PutString(txt3);

  while(1){
		if(usart1_task==1){
			usart1_task=0;
			USART1_PutNewLine;
			USART1_PutString(usart1_txt);
			USART_ClearString(usart1_txt);
		}	
  }
}





