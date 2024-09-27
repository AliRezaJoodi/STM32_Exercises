// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include <stdio.h>

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_usart.h>
#include <delay.h>
#include <keypad4x4.h>

char txt[20]="";
uint8_t number=17;

int main(void){
	uint8_t number_last=0;
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWJ_SWD);
  RCC_ConfigSystemClock();
	
  USART1_Config();
	USART_PutStringFromFlash(USART1, "Test USART1");
	
	sprintf(txt, "Number(DEC)=%3d", number);
	USART_PutString(USART1, txt);
	sprintf(txt, "Number(Hex)=%X", number);
	USART_PutString(USART1, txt);	
	
  while(1){
		//number= _Keypad4x4_GetInitialNumber();
		number= Keypad4x4_GetNumber();
		
		if(number != number_last && number != 16){
			number_last=number;
			sprintf(txt, "Number(DEC)=%3d", number);
			USART_PutString(USART1, txt);
		}
  }
}





