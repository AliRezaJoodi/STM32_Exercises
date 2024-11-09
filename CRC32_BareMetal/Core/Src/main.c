// GitHub Account: GitHub.com/AliRezaJoodi

#include "main.h"
#include <stdio.h>
#include <utility.h>

#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_usart.h>
#include <stm32f1xx_bm_crc32.h>


int main(void){
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugMode(SWJ_SWD);
  RCC_SystemClock_ConfigDefault1();
		
  USART1_ConfigDefault2();
	
	uint32_t data[3]={0x10,0x43,0x63};	
	char txt[20];
	uint32_t crc32=0;
	
	for(uint8_t i=0; i<3; i++){
		sprintf(txt, "Data[%1d]=0x%2X", i, data[i]);
		USART_PutString(USART1, txt);
	}

	crc32 = CRC32_Calculate(data, 3);
	sprintf(txt, "CRC32=0x%2X", crc32);
	USART_PutString(USART1, txt);
	
  while(1){
  }
}





