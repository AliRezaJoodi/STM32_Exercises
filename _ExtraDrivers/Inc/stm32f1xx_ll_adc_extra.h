// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _STM32F1xx_LL_ADC_EXTRA_INCLUDED
#define _STM32F1xx_LL_ADC_EXTRA_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f1xx.h>
#include <stm32f1xx_ll_adc.h>
#include <utility.h>

/*
Power-up time
tSTAB:	1uS
*/
#ifndef ADC_TSTAB
	#define ADC_TSTAB		1
#endif

#ifndef ADC_GAIN
	#define ADC_GAIN		0.80586080    // 3300mv / 2^10 = 3300/4095
#endif

/*
V25 = VSENSE value for 25° C and	
unit: mv
*/	
#ifndef ADC_V25
	#define ADC_V25        1430
#endif

/*
Avg_Slope = Average Slope for curve between Temperature and VSENSE.
unit: mv
*/
#ifndef ADC_AVG_SLOPE
	#define ADC_AVG_SLOPE  4.3
#endif


float LL_ADC_ConvertValueToMiliVolt(uint16_t value);
float LL_ADC_ConvertMiliVoltToInternalTemp(float mv);


#ifdef __cplusplus
}
#endif

#endif		// _STM32F1xx_LL_ADC_EXTRA_INCLUDED