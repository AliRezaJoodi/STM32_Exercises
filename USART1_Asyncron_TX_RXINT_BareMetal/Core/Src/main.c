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

int main(void){
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWJ_SWD);
  RCC_ConfigSystemClock();
  USART1_Config();
	NVIC_Config();

	USART_PutChar(USART1,'A');
	USART_PutChar(USART1, '\r');		// 0x0D
	USART_PutChar(USART1, '\n');		// 0x0A
	
	char txt1[]= "ABCDEFGH";
	USART_PutString(USART1, txt1);
	USART_PutStringFromFlash(USART1, "0123456789");
	const char txt2[]= "Test2";
	USART_PutStringFromFlash(USART1, txt2);
	
	char txt3[20]= "Test3";
	USART_ClearString(txt3);
	USART_PutString(USART1, txt3);
	
	sprintf(txt3, "Number=%3d", 12);
	USART_PutString(USART1, txt3);

	sprintf(txt3, "Value=%.3f", 1.23456);
	USART_PutString(USART1, txt3);
	
	unsigned int a1=0;
	a1=USART1->BRR;
	//a1 = _DIV_SAMPLING16(8000000, 9600);
	sprintf(txt3, "USART1_BRR=%d", a1);
	USART_PutString(USART1, txt3);
	sprintf(txt3, "USART1_BRR (HEX)=%x", a1);
	USART_PutString(USART1, txt3);
	
  while(1){
		if(usart1_task==1){
			usart1_task=0;
			USART_PutChar(USART1, '\r');
			USART_PutChar(USART1, '\n');
			USART_PutString(USART1, usart1_txt);
			USART_ClearString(usart1_txt);
		}	
  }
}





