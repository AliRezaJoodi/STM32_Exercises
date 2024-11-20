// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_ll_adc_extra.h>

//************************************************************
float LL_ADC_ConvertValueToMiliVolt(uint16_t value){	
	float adc_mv=0;
	adc_mv = (float)(value * ADC_GAIN);
	return adc_mv;
}

//************************************************************
float LL_ADC_ConvertMiliVoltToInternalTemp(float mv){	
	float temp = ( (mv - ADC_V25) / ADC_AVG_SLOPE ) + 25.0;
	
	return temp;
}