
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

static void ADC1_ConfigDefault(void);

int main(void){
	uint16_t adc_value;
	char txt[20]="";
	float mv;
			
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugMode(SWJ_SWD);
	
	RCC_SystemClock_ConfigDefault1();
	USART1_ConfigDefault2();
	USART_PutStringFromFlash(USART1, "ADC Test");
	
  ADC1_ConfigDefault();
	
  while(1){
		ADC_StartConversionInRegularChannels(ADC1);
		//while(ADC_EndOfConversion_GetFlag(ADC1) != 1){}
		if(Timeout_ADC_WaitUntil(ADC_EndOfConversion_GetFlag, ADC1, 1) == TIMEOUT_SUCCESS){
			ADC_EndOfConversion_ClearFlag(ADC1); 
			adc_value = ADC_ConversionResultInRegularChannels_ReadData(ADC1);	
		}
		else{
			adc_value=0;
		}
	
		mv = (float)(adc_value * ADC_GAIN);
		sprintf(txt, "Voltage(mv): %.1f", mv);
		USART_PutString(USART1, txt);
		
		SysTick_Delay_1ms(500);
  }
}

//************************************************************
static void ADC1_ConfigDefault(void){
	GPIO_ADC_ConfigCh(ADC_IN3);
	
	BUS_ADC1_EnableOrDisable(1);
	ADC_DataAlignment_SetLeftOrRight(ADC1, ADC_ALIGNMENT_RIGHT);
	ADC_ScanMode_EnableOrDisable(ADC1, 0);	
	ADC_DualMode_SetMode(ADC1, ADC_INDEPENDENT);
	ADC_ExternalEventForRegularGroup_SetMode(ADC1, ADC_EXTSEL_SOFTWARE);	
	ADC_DiscontinuousModeInRegularChannels_SetChannelCount(ADC1, 1);
	ADC_DiscontinuousModeInRegularChannels_EnableOrDisable(ADC1, 0);
	ADC_DMA_EnableOrDisable(ADC1, 0);
	ADC_ContinuousOrSingleConversionMode_SetMode(ADC1, ADC_SINGLE);
	ADC_SequenceLengthInRegularChannels_SetLength(ADC1, 1);
	ADC_ConversionSequenceInRegularChannelsFor1stSequence_SetChannelNumber(ADC1, ADC_IN3);
	ADC_SamplingTimeInCh3_SetCycle(ADC1, ADC_SAMPLINGTIME_239CYCLE_5);
	
	ADC_EnableOrDisable(ADC1, 1);
	ADC_StartCalibration(ADC1);
	ADC_EndOfConversionInterrupt_EnableOrDisable(ADC1, 0);
}
