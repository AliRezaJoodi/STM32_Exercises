
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
	
	uint16_t adc_value1=0;
	float adc_mv1=0;
	
	uint16_t adc_value2=0;
	float adc_mv2=0;
	
	uint16_t adc_value3=0;
	float adc_mv3=0;
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugMode(SWJ_SWD);
	
	RCC_SystemClock_ConfigDefault1();
	USART1_ConfigDefault2();
	USART_PutStringFromFlash(USART1, "ADC1");

  ADC_ConfigDefault(ADC1);
	//ADC_SoftwareStartInRegularChannels_Start(ADC1);
	
	sprintf(txt, "Conversion: %d", _ContinuousOrSingleMode_GetMode(ADC1)); USART_PutString(USART1, txt);
	sprintf(txt, "Scan: %d", _ScanMode_GetEnableStatus(ADC1)); USART_PutString(USART1, txt);
	sprintf(txt, "Length: %d", _SequenceInRegularChannels_GetLength(ADC1)+1); USART_PutString(USART1, txt);
	sprintf(txt, "1st Sequence: %d", _SequenceInRegularChannels_Get1stSequence(ADC1)); USART_PutString(USART1, txt);
	sprintf(txt, "2nd Sequence: %d", _SequenceInRegularChannels_Get2ndSequence(ADC1)); USART_PutString(USART1, txt);
	sprintf(txt, "3rd Sequence: %d", _SequenceInRegularChannels_Get3rdSequence(ADC1)); USART_PutString(USART1, txt);
	sprintf(txt, "EXTSEL: %d", _ExternalEventInRegularChannels_GetMode(ADC1)); USART_PutString(USART1, txt);
	sprintf(txt, "EXTTRIG: %d", _ExternalTriggerForRegularChannels_GetEnableStatus(ADC1)); USART_PutString(USART1, txt);
	sprintf(txt, "ADON: %d", ADC_GetEnableStatus(ADC1)); USART_PutString(USART1, txt);
	USART_PutStringFromFlash(USART1, "");
	
  while(1){
		ADC_SoftwareStartInRegularChannels_Start(ADC1);
		
		while(ADC_EndOfConversion_GetFlag(ADC1) != 1);
		ADC_EndOfConversion_ClearFlag(ADC1); 
		adc_value1 = ADC_ConversionResultInRegularChannels_ReadData(ADC1);
		//SysTick_Delay_1ms(3);
		USART_PutStringFromFlash(USART1, "R1");
		
		while(ADC_EndOfConversion_GetFlag(ADC1) != 1);
		ADC_EndOfConversion_ClearFlag(ADC1); 
		adc_value2 = ADC_ConversionResultInRegularChannels_ReadData(ADC1);
		//SysTick_Delay_1ms(3);
		USART_PutStringFromFlash(USART1, "R2");
		
		while(ADC_EndOfConversion_GetFlag(ADC1) != 1);
		ADC_EndOfConversion_ClearFlag(ADC1); 
		adc_value3 = ADC_ConversionResultInRegularChannels_ReadData(ADC1);
		//SysTick_Delay_1ms(3);
		USART_PutStringFromFlash(USART1, "R3");
		
		adc_mv1 = ADC_ConvertValueToMiliVolt(adc_value1);
		adc_mv2 = ADC_ConvertValueToMiliVolt(adc_value2);
		adc_mv3 = ADC_ConvertValueToMiliVolt(adc_value3);
		
//		adc_mv1 = (float)(adc_value1 * ADC_GAIN);
//		adc_mv2 = (float)(adc_value2 * ADC_GAIN);
//		adc_in3 = (float)(adc_value3 * ADC_GAIN);
		
//		if(Timeout_ADC_WaitUntil(ADC_EndOfConversion_GetFlag, ADC1, 1) == TIMEOUT_SUCCESS){
//			ADC_EndOfConversion_ClearFlag(ADC1); 
//			adc_value = ADC_ConversionResultInRegularChannels_ReadData(ADC1);
//			adc_mv1 = (float)(adc_value * ADC_GAIN);
//		}
//		else{
//			adc_mv1=0;
//		}

//		if(Timeout_ADC_WaitUntil(ADC_EndOfConversion_GetFlag, ADC1, 1) == TIMEOUT_SUCCESS){
//			ADC_EndOfConversion_ClearFlag(ADC1); 
//			adc_value = ADC_ConversionResultInRegularChannels_ReadData(ADC1);
//			adc_mv2 = (float)(adc_value * ADC_GAIN);
//		}
//		else{
//			adc_mv2=0;
//		}
//		
//		if(Timeout_ADC_WaitUntil(ADC_EndOfConversion_GetFlag, ADC1, 1) == TIMEOUT_SUCCESS){
//			ADC_EndOfConversion_ClearFlag(ADC1); 
//			adc_value = ADC_ConversionResultInRegularChannels_ReadData(ADC1);
//			adc_in3 = (float)(adc_value * ADC_GAIN);
//		}
//		else{
//			adc_in3=0;
//		}
		
//		in1=ADC_SingleMode_Read(ADC1, ADC_IN3);
//		in2=ADC_SingleMode_Read(ADC1, ADC_IN8);
//		in3=ADC_SingleMode_Read(ADC1, ADC_IN9);
		
		sprintf(txt, "Input1(mv): %.1f", adc_mv1);
		USART_PutString(USART1, txt);
		sprintf(txt, "Input2(mv): %.1f", adc_mv2);
		USART_PutString(USART1, txt);
		sprintf(txt, "Input3(mv): %.1f", adc_mv3);
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
	ADC_ContinuousOrSingleMode_SetMode(ADCx, ADC_SINGLE);	
	ADC_ScanMode_EnableOrDisable(ADCx, 1);

	ADC_DMA_EnableOrDisable(ADCx, 0);
	
	ADC_SequenceInRegularChannels_SetLength(ADCx, 3);		
	ADC_SequenceInRegularChannels_SetSequence(ADC1, ADC_RANK1, ADC_IN3);
	ADC_SequenceInRegularChannels_SetSequence(ADC1, ADC_RANK2, ADC_IN8);
	ADC_SequenceInRegularChannels_SetSequence(ADC1, ADC_RANK3, ADC_IN9);
	
	ADC_ExternalEventInRegularChannels_SetMode(ADCx, ADC_EXTSEL_SOFTWARE);	
	ADC_DiscontinuousModeInRegularChannels_SetChannelCount(ADCx, 1);
	ADC_DiscontinuousModeInRegularChannels_EnableOrDisable(ADCx, 0);
		
	ADC_EnableOrDisable(ADCx, 1);
	ADC_Calibration_Start(ADCx);
	ADC_InterruptInRegularChannels_EnableOrDisable(ADCx, 0);
}



