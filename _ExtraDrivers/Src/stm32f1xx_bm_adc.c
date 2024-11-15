// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_adc.h>

//************************************************************
uint8_t ADC_SequenceInRegularChannels_SetSequence(ADC_TypeDef *ADCx, uint8_t rank, uint8_t ch){
	uint8_t error=ADC_ERROR;
	
	switch (rank){
		case ADC_RANK1:
			error = ADC_SequenceInRegularChannels_Set1stSequence(ADCx, ch);
			break;
		case ADC_RANK2:
			error = ADC_SequenceInRegularChannels_Set2ndSequence(ADCx, ch);
			break;
		case ADC_RANK3:
			error = ADC_SequenceInRegularChannels_Set3rdSequence(ADCx, ch);
			break;
		case ADC_RANK4:
			error = ADC_SequenceInRegularChannels_Set4thSequence(ADCx, ch);
			break;
		case ADC_RANK5:
			error = ADC_SequenceInRegularChannels_Set5thSequence(ADCx, ch);
			break;
		case ADC_RANK6:
			error = ADC_SequenceInRegularChannels_Set6thSequence(ADCx, ch);
			break;
		case ADC_RANK7:
			error = ADC_SequenceInRegularChannels_Set7thSequence(ADCx, ch);
			break;
		case ADC_RANK8:
			error = ADC_SequenceInRegularChannels_Set8thSequence(ADCx, ch);
			break;
		case ADC_RANK9:
			error = ADC_SequenceInRegularChannels_Set9thSequence(ADCx, ch);
			break;
		case ADC_RANK10:
			error = ADC_SequenceInRegularChannels_Set10thSequence(ADCx, ch);
			break;
		case ADC_RANK11:
			error = ADC_SequenceInRegularChannels_Set11thSequence(ADCx, ch);
			break;
		case ADC_RANK12:
			error = ADC_SequenceInRegularChannels_Set12thSequence(ADCx, ch);
			break;
		case ADC_RANK13:
			error = ADC_SequenceInRegularChannels_Set13thSequence(ADCx, ch);
			break;
		case ADC_RANK14:
			error = ADC_SequenceInRegularChannels_Set14thSequence(ADCx, ch);
			break;
		case ADC_RANK15:
			error = ADC_SequenceInRegularChannels_Set15thSequence(ADCx, ch);
			break;
		case ADC_RANK16:
			error = ADC_SequenceInRegularChannels_Set16thSequence(ADCx, ch);
			break;
	}
	
	return error;
}

//************************************************************
uint8_t ADC_SamplingTime_SetCycle(ADC_TypeDef *ADCx, uint8_t ch, uint8_t cycle){
uint8_t error=ADC_ERROR;

	switch (ch){
		case ADC_IN0:
			error = ADC_SamplingTime_SetCycleForCh0(ADCx, cycle);
			break;
		case ADC_IN1:
			error = ADC_SamplingTime_SetCycleForCh1(ADCx, cycle);
			break;
		case ADC_IN2:
			error = ADC_SamplingTime_SetCycleForCh2(ADCx, cycle);
			break;
		case ADC_IN3:
			error = ADC_SamplingTime_SetCycleForCh3(ADCx, cycle);
			break;
		case ADC_IN4:
			error = ADC_SamplingTime_SetCycleForCh4(ADCx, cycle);
			break;
		case ADC_IN5:
			error = ADC_SamplingTime_SetCycleForCh5(ADCx, cycle);
			break;
		case ADC_IN6:
			error = ADC_SamplingTime_SetCycleForCh6(ADCx, cycle);
			break;
		case ADC_IN7:
			error = ADC_SamplingTime_SetCycleForCh7(ADCx, cycle);
			break;
		case ADC_IN8:
			error = ADC_SamplingTime_SetCycleForCh8(ADCx, cycle);
			break;
		case ADC_IN9:
			error = ADC_SamplingTime_SetCycleForCh9(ADCx, cycle);
			break;
		case ADC_IN10:
			error = ADC_SamplingTime_SetCycleForCh10(ADCx, cycle);
			break;
		case ADC_IN11:
			error = ADC_SamplingTime_SetCycleForCh11(ADCx, cycle);
			break;
		case ADC_IN12:
			error = ADC_SamplingTime_SetCycleForCh12(ADCx, cycle);
			break;
		case ADC_IN13:
			error = ADC_SamplingTime_SetCycleForCh13(ADCx, cycle);
			break;
		case ADC_IN14:
			error = ADC_SamplingTime_SetCycleForCh14(ADCx, cycle);
			break;
		case ADC_IN15:
			error = ADC_SamplingTime_SetCycleForCh15(ADCx, cycle);
			break;
		case ADC_IN16:
			error = ADC_SamplingTime_SetCycleForCh16(ADCx, cycle);
			break;
		case ADC_IN17:
			error = ADC_SamplingTime_SetCycleForCh17(ADCx, cycle);
			break;
	}		
	
return error;	
}

//************************************************************
float ADC_SingleMode_Read(ADC_TypeDef *ADCx, uint8_t ch){
	uint16_t adc_value=0;
	float adc_mv=0;
	
	ADC_SequenceInRegularChannels_Set1stSequence(ADCx, ch);
	
	ADC_StartConversionInRegularChannels(ADCx);
	if(Timeout_ADC_WaitUntil(ADC_EndOfConversion_GetFlag, ADCx, 1) == ADC_SUCCESS){
		ADC_EndOfConversion_ClearFlag(ADCx); 
		adc_value = ADC_ConversionResultInRegularChannels_ReadData(ADCx);
		adc_mv = (float)(adc_value * ADC_GAIN);
	}
	
	return adc_mv;
}

//************************************************************
float ADC_ConvertVoltageToInternalTemp(float mv){	
	float temp = ( (mv - ADC_V25) / ADC_AVG_SLOPE ) + 25.0;
	
	return temp;
}


