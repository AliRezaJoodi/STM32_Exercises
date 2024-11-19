// GitHub Account: GitHub.com/AliRezaJoodi

/*
Single conversion mode:
	In Single conversion mode the ADC does one conversion.
	This mode is started either by setting the ADON bit in the ADC_CR2 register (for a regular channel only)
	or by external trigger (for a regular or injected channel), while the CONT bit is 0.
	
	Once the conversion of the selected channel is complete:
	_If a regular channel was converted:
		__The converted data is stored in the 16-bit ADC_DR register
		__The EOC (End Of Conversion) flag is set
		__and an interrupt is generated if the EOCIE is set.
	_If an injected channel was converted:
		__The converted data is stored in the 16-bit ADC_DRJ1 register
		__The JEOC (End Of Conversion Injected) flag is set
		__and an interrupt is generated if the JEOCIE bit is set.
	
	The ADC is then stopped.
*/

/*
Continuous conversion mode:
	In continuous conversion mode ADC starts another conversion as soon as it finishes one.
	This mode is started either by external trigger or by setting the ADON bit in the ADC_CR2 register, while the CONT bit is 1.
	
	After each conversion:
	_If a regular channel was converted:
		__The converted data is stored in the 16-bit ADC_DR register
		__The EOC (End Of Conversion) flag is set
		__An interrupt is generated if the EOCIE is set.
	_If an injected channel was converted:
		__The converted data is stored in the 16-bit ADC_DRJ1 register
		__The JEOC (End Of Conversion Injected) flag is set
		__An interrupt is generated if the JEOCIE bit is set.
*/

/*
Scan mode:
	This mode is used to scan a group of analog channels.
	Scan mode can be selected by setting the SCAN bit in the ADC_CR1 register.
	Once this bit is set, ADC scans all the channels selected in the ADC_SQRx registers (for regular channels) or in the ADC_JSQR (for injected channels).
	A single conversion is performed for each channel of the group.
	After each end of conversion the next channel of the group is converted automatically.
	If the CONT bit is set, conversion does not stop at the last selected group channel but continues again from the first selected group channel.
	When using scan mode, DMA bit must be set and the direct memory access controller is used to transfer the converted data of regular group channels to SRAM after each update of the ADC_DR register.
	The injected channel converted data is always stored in the ADC_JDRx registers.
*/

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
	
	ADC_SoftwareStartInRegularChannels_Start(ADCx);
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


