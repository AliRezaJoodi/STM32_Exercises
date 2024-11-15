
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

#include <stm32f1xx_bm_adc.h>
#include <stm32f1xx_bm_it.h>

extern uint16_t adc_value;

static void ADC1_ConfigDefault(void);

int main(void){
	char txt[20]="";
	float mv;
			
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugMode(SWJ_SWD);
	
	RCC_SystemClock_ConfigDefault1();
	USART1_ConfigDefault2();
	USART_PutStringFromFlash(USART1, "ADC Test");
	
  ADC1_ConfigDefault();
	ADC_SoftwareStartInRegularChannels_Start(ADC1);
	
	NVIC_Config();
	
  while(1){
		mv = (float)(adc_value * ADC_GAIN);
		sprintf(txt, "Voltage(mv): %.1f", mv);
		USART_PutString(USART1, txt);
		
		SysTick_Delay_1ms(500);
  }
}

//************************************************************
static void ADC1_ConfigDefault(void){
	BUS_ADC1_EnableOrDisable(1);
	
	GPIO_ADC_ConfigCh(ADC_IN3);
	ADC_SamplingTime_SetCycle(ADC1, ADC_IN3, ADC_SAMPLINGTIME_239CYCLE_5);
	
	ADC_DataAlignment_SetLeftOrRight(ADC1, ADC_ALIGNMENT_RIGHT);
	ADC_DualMode_SetMode(ADC1, ADC_INDEPENDENT);
	ADC_ScanMode_EnableOrDisable(ADC1, 0);
	ADC_ContinuousOrSingleMode_SetMode(ADC1, ADC_CONTINUOUS);	
	ADC_SequenceInRegularChannels_SetLength(ADC1, 1);
	ADC_SequenceInRegularChannels_SetSequence(ADC1, ADC_RANK1, ADC_IN3);
		
	ADC_ExternalEventInRegularChannels_SetMode(ADC1, ADC_EXTSEL_SOFTWARE);	
	ADC_DiscontinuousModeInRegularChannels_SetChannelCount(ADC1, 1);
	ADC_DiscontinuousModeInRegularChannels_EnableOrDisable(ADC1, 0);
	ADC_DMA_EnableOrDisable(ADC1, 0);

	ADC_EnableOrDisable(ADC1, 1);
	ADC_Calibration_Start(ADC1);
	ADC_InterruptInRegularChannels_EnableOrDisable(ADC1, 1);
}
