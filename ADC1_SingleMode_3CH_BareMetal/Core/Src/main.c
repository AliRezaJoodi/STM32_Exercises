
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

void ADC_ConfigDefault(ADC_TypeDef *ADCx);

int main(void){
	char txt[20]="";
	float adc_in1=0;
	float adc_in2=0;
	float adc_in3=0;
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugMode(SWJ_SWD);
	
	RCC_SystemClock_ConfigDefault1();
	USART1_ConfigDefault2();
	USART_PutStringFromFlash(USART1, "ADC Test");
	
  ADC_ConfigDefault(ADC1);
	
  while(1){
		adc_in1=ADC_SingleMode_Read(ADC1, ADC_IN3);
		adc_in2=ADC_SingleMode_Read(ADC1, ADC_IN8);
		adc_in3=ADC_SingleMode_Read(ADC1, ADC_IN9);
		
		sprintf(txt, "Input1(mv): %.1f", adc_in1);
		USART_PutString(USART1, txt);
		sprintf(txt, "Input2(mv): %.1f", adc_in2);
		USART_PutString(USART1, txt);
		sprintf(txt, "Input3(mv): %.1f", adc_in3);
		USART_PutString(USART1, txt);
		USART_PutStringFromFlash(USART1, "");
		
		SysTick_Delay_1ms(500);
  }
}

//************************************************************
void ADC_ConfigDefault(ADC_TypeDef *ADCx){
	BUS_ADCx_EnableOrDisable(ADCx, 1);
	
	GPIO_ADC_ConfigCh(ADC_IN3);
	GPIO_ADC_ConfigCh(ADC_IN8);
	GPIO_ADC_ConfigCh(ADC_IN9);
	
	ADC_SamplingTime_SetCycle(ADCx, ADC_IN3, ADC_SAMPLINGTIME_239CYCLE_5);
	ADC_SamplingTime_SetCycle(ADCx, ADC_IN8, ADC_SAMPLINGTIME_239CYCLE_5);
	ADC_SamplingTime_SetCycle(ADCx, ADC_IN9, ADC_SAMPLINGTIME_239CYCLE_5);
	
	ADC_DataAlignment_SetLeftOrRight(ADCx, ADC_ALIGNMENT_RIGHT);
	ADC_DualMode_SetMode(ADCx, ADC_INDEPENDENT);
	ADC_ScanMode_EnableOrDisable(ADCx, 0);	
	ADC_ContinuousOrSingleMode_SetMode(ADCx, ADC_SINGLE);
	ADC_SequenceLengthInRegularChannels_SetLength(ADCx, 1);
	ADC_SequenceInRegularChannels_SetSequence(ADC1, ADC_RANK1, ADC_IN3);

	ADC_ExternalEventForRegularGroup_SetMode(ADCx, ADC_EXTSEL_SOFTWARE);	
	ADC_DiscontinuousModeInRegularChannels_SetChannelCount(ADCx, 1);
	ADC_DiscontinuousModeInRegularChannels_EnableOrDisable(ADCx, 0);
	ADC_DMA_EnableOrDisable(ADCx, 0);

	ADC_EnableOrDisable(ADCx, 1);
	ADC_StartCalibration(ADCx);
	ADC_EndOfConversionInterrupt_EnableOrDisable(ADCx, 0);
}



