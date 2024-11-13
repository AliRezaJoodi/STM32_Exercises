
#include "main.h"
#include "stdio.h"

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_timer_systick.h>
#include <stm32f1xx_bm_usart.h>
#include <stm32f1xx_bm_exti.h>
#include <timeout.h>

#include <stm32f1xx_bm_adc.h>

int main(void){
	char txt[20]="";
	float in1=0;
	float in2=0;
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugMode(SWJ_SWD);
	
	RCC_SystemClock_ConfigDefault1();
	USART1_ConfigDefault2();
	USART_PutStringFromFlash(USART1, "ADC Test");
	
  ADC_ConfigDefault1(ADC1);
	GPIO_ADC_ConfigCh(ADC_IN3);
	GPIO_ADC_ConfigCh(ADC_IN9);
	
  while(1){
		in1=ADC_SingleConversionMode_Read(ADC1, ADC_IN3);
		in2=ADC_SingleConversionMode_Read(ADC1, ADC_IN9);
		
		sprintf(txt, "Input1(mv): %.1f", in1);
		USART_PutString(USART1, txt);
		sprintf(txt, "Input2(mv): %.1f", in2);
		USART_PutString(USART1, txt);
		
		SysTick_Delay_1ms(500);
  }
}



