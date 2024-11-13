// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_adc.h>

//************************************************************
void ADC_ConfigDefault1(ADC_TypeDef *ADCx){
	BUS_ADCx_EnableOrDisable(ADCx, 1);
	
	ADC_DataAlignment_SetLeftOrRight(ADCx, ADC_ALIGNMENT_RIGHT);
	ADC_ScanMode_EnableOrDisable(ADCx, 0);	
	ADC_DualMode_SetMode(ADCx, ADC_INDEPENDENT);
	ADC_ExternalEventForRegularGroup_SetMode(ADCx, ADC_EXTSEL_SOFTWARE);	
	ADC_DiscontinuousModeInRegularChannels_SetChannelCount(ADCx, 1);
	ADC_DiscontinuousModeInRegularChannels_EnableOrDisable(ADCx, 0);
	ADC_DMA_EnableOrDisable(ADCx, 0);
	ADC_ContinuousOrSingleConversionMode_SetMode(ADCx, ADC_SINGLE);
	ADC_SequenceLengthInRegularChannels_SetLength(ADCx, 1);
	ADC_ConversionSequenceInRegularChannelsFor1stSequence_SetChannelNumber(ADCx, ADC_IN0);
	ADC_SamplingTimeInCh3_SetCycle(ADCx, ADC_SAMPLINGTIME_239CYCLE_5);
	
	ADC_EnableOrDisable(ADCx, 1);
	ADC_StartCalibration(ADCx);
	ADC_EndOfConversionInterrupt_EnableOrDisable(ADCx, 0);
}

//************************************************************
float ADC_SingleConversionMode_Read(ADC_TypeDef *ADCx, uint8_t ch){
	uint16_t value_adc=0;
	float value_mv=0;
	
	ADC_ConversionSequenceInRegularChannelsFor1stSequence_SetChannelNumber(ADCx, ch);
	
	ADC_StartConversionInRegularChannels(ADCx);
	if(Timeout_ADC_WaitUntil(ADC_EndOfConversion_GetFlag, ADCx, 1) == TIMEOUT_SUCCESS){
		ADC_EndOfConversion_ClearFlag(ADCx); 
		value_adc = ADC_ConversionResultInRegularChannels_ReadData(ADCx);
		value_mv = (float)(value_adc * ADC_GAIN);
	}
	
	return value_mv;
}


