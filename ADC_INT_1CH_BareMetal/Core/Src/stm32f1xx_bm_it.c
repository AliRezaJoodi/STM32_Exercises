// GitHub Account: GitHub.com/AliRezaJoodi

#include "stm32f1xx_bm_it.h"

//**********************************************************
void NVIC_Config(void){	
	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	
	NVIC_SetPriority(ADC1_2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(ADC1_2_IRQn);
}

volatile uint16_t adc_value;

//**********************************************
void ADC1_2_IRQHandler(void){
	if(ADC_EndOfConversion_GetFlag(ADC1)==1){
		ADC_EndOfConversion_ClearFlag(ADC1); 
		adc_value = ADC_RegularData_ReadConversionResult(ADC1); 
	}
}
