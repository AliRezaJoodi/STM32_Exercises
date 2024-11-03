
#include "main.h"
#include "stm32f1xx_it.h"
#include <stm32f1xx_bm_adc.h>

//extern volatile uint16_t ADC_Value;
volatile uint16_t ADC_Value;

//**********************************************
void ADC1_2_IRQHandler(void){
	if(ADC_EndOfConversion_GetFlag(ADC1)==1){
		ADC_EndOfConversion_ClearFlag(ADC1); 
		ADC_Value = ADC_RegularData_GetConversionResult(ADC1); 
	 }
}
