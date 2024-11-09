// GitHub Account: GitHub.com/AliRezaJoodi

#include "main.h"
#include <stdio.h>

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>

#include <stm32f1xx_bm_usart.h>

char txt[20]="";
uint8_t number=17;

int main(void){
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugMode(SWJ_SWD);
  RCC_SystemClock_ConfigDefault1();
	
  USART1_ConfigDefault2();
	USART_PutStringFromFlash(USART1, "Test USART1");
	
	sprintf(txt, "Number(DEC)=%3d", number);
	USART_PutString(USART1, txt);
	sprintf(txt, "Number(Hex)=0x%X", number);
	USART_PutString(USART1, txt);	
	
  while(1){

  }
}





