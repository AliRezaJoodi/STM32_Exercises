
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
	uint16_t adc_value[5]={0,0,0,0,0};
	float adc_mv[5]={0,0,0,0,0};
	float adc_temp=0;
	float adc_vref=0;
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugMode(SWJ_SWD);
	
	RCC_SystemClock_ConfigDefault1();
	USART1_ConfigDefault2();
	USART_PutStringFromFlash(USART1, "ADC Test");
	
  ADC_ConfigDefault(ADC1);
	
  while(1){
		adc_value[0]=ADC_SingleMode_Read(ADC1, ADC_IN3);
		adc_mv[0]=ADC_ConvertValueToMiliVolt(adc_value[0]);
		sprintf(txt, "IN3(mv): %.1f", adc_mv[0]);
		USART_PutString(USART1, txt);
		
		adc_value[1]=ADC_SingleMode_Read(ADC1, ADC_IN8);
		adc_mv[1]=ADC_ConvertValueToMiliVolt(adc_value[1]);
		sprintf(txt, "IN8(mv): %.1f", adc_mv[1]);
		USART_PutString(USART1, txt);
		
		adc_value[2]=ADC_SingleMode_Read(ADC1, ADC_IN9);
		adc_mv[2]=ADC_ConvertValueToMiliVolt(adc_value[2]);
		sprintf(txt, "IN9(mv): %.1f", adc_mv[2]);
		USART_PutString(USART1, txt);
		
		adc_value[3]=ADC_SingleMode_Read(ADC1, ADC_TEMPSENSOR);
		adc_mv[3]=ADC_ConvertValueToMiliVolt(adc_value[3]);
		adc_temp=ADC_ConvertMiliVoltToInternalTemp(adc_mv[3]);
		sprintf(txt, "Temp(^C): %.3f", adc_temp);
		USART_PutString(USART1, txt);
		
		adc_value[4]=ADC_SingleMode_Read(ADC1, ADC_VREFINT);
		adc_vref=ADC_ConvertValueToMiliVolt(adc_value[4]);
		sprintf(txt, "Vref(mv): %.1f", adc_vref);
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
	ADC_SamplingTime_SetCycle(ADCx, ADC_TEMPSENSOR, ADC_SAMPLINGTIME_239CYCLE_5);
	ADC_SamplingTime_SetCycle(ADCx, ADC_VREFINT, ADC_SAMPLINGTIME_239CYCLE_5);
	ADC_InternalChannels_EnableOrDisable(1);
	
	ADC_DataAlignment_SetLeftOrRight(ADCx, ADC_ALIGNMENT_RIGHT);
	ADC_DualMode_SetMode(ADCx, ADC_INDEPENDENT);
	ADC_ScanMode_EnableOrDisable(ADCx, 0);	
	ADC_ContinuousOrSingleMode_SetMode(ADCx, ADC_SINGLE);
	
	ADC_SequenceForRegularChannels_SetLength(ADCx, 1);
	ADC_SequenceForRegularChannels_SetSequence(ADC1, ADC_RANK1, ADC_IN3);
	ADC_ExternalEventForRegularChannels_SetMode(ADCx, ADC_EXTSEL_SOFTWARE);	
	ADC_DiscontinuousModeForRegularChannels_SetChannelCount(ADCx, 1);
	ADC_DiscontinuousModeForRegularChannels_EnableOrDisable(ADCx, 0);
	
	ADC_DMA_EnableOrDisable(ADCx, 0);

	ADC_EnableOrDisable(ADCx, 1);
	ADC_Calibration_Start(ADCx);
	ADC_InterruptForRegularChannels_EnableOrDisable(ADCx, 0);
}



