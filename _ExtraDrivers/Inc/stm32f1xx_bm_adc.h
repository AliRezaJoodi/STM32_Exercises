// GitHub Account: GitHub.com/AliRezaJoodi

/*
It's about:
	ADC_SR:		ADC status register
	ADC_JDRx:	ADC injected data register x
	ADC_DR:		ADC regular data register
*/

/*
Abbreviations:
	ADC:	Analog to digital converter
*/

#ifndef _STM32F1XX_BM_ADC_INCLUDED
#define _STM32F1XX_BM_ADC_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f1xx.h>
#include <utility.h>

/*
ADC_SR, Bit 4
STRT:	Regular channel Start flag
			This bit is set by hardware when regular channel conversion starts.
			It is cleared by software.
			0: No regular channel conversion started
			1: Regular channel conversion has started
*/

__STATIC_INLINE uint32_t ADC_RegularChannelStartFlag_GetFlag(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->SR, ADC_SR_STRT_Pos) );
}

__STATIC_INLINE void ADC_RegularChannelStartFlag_ClearFlag(ADC_TypeDef *ADCx){
	ClearBit(ADCx->SR, ADC_SR_STRT_Pos);
}


/*
ADC_SR, Bit 3
JSTRT: 	Injected channel Start flag
				This bit is set by hardware when injected channel group conversion starts.
				It is cleared by software.
				0: No injected group conversion started
				1: Injected group conversion has started
*/

__STATIC_INLINE uint32_t ADC_InjectedChannelStartFlag_GetFlag(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->SR, ADC_SR_JSTRT_Pos) );
}

__STATIC_INLINE void ADC_InjectedChannelStartFlag_ClearFlag(ADC_TypeDef *ADCx){
	ClearBit(ADCx->SR, ADC_SR_JSTRT_Pos);
}


/*
ADC_SR, Bit 2
JEOC:	Injected channel end of conversion
			This bit is set by hardware at the end of all injected group channel conversion.
			It is cleared by software.
			0: Conversion is not complete
			1: Conversion complete
*/

__STATIC_INLINE uint32_t ADC_InjectedChannelEndOfConversion_GetFlag(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->SR, ADC_SR_JEOS_Pos) );
}

__STATIC_INLINE void ADC_InjectedChannelEndOfConversion_ClearFlag(ADC_TypeDef *ADCx){
	ClearBit(ADCx->SR, ADC_SR_JEOS_Pos);
}


/*
ADC_SR, Bit 1
EOC:	End of conversion
			This bit is set by hardware at the end of a group channel conversion (regular or injected).
			It is cleared by software or by reading the ADC_DR.
			0: Conversion is not complete
			1: Conversion complete
*/

__STATIC_INLINE uint32_t ADC_EndOfConversion_GetFlag(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->SR, ADC_SR_EOS_Pos) );
}

__STATIC_INLINE void ADC_EndOfConversion_ClearFlag(ADC_TypeDef *ADCx){
	ClearBit(ADCx->SR, ADC_SR_EOS_Pos);
}


/*
ADC_SR, Bit 0
AWD:	Analog watchdog flag
			This bit is set by hardware when the converted voltage crosses the values programmed in
			the ADC_LTR and ADC_HTR registers.
			It is cleared by software.
			0: No Analog watchdog event occurred
			1: Analog watchdog event occurred
*/

__STATIC_INLINE uint32_t ADC_AnalogWatchdogFlag_GetFlag(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->SR, ADC_SR_AWD_Pos) );
}

__STATIC_INLINE void ADC_AnalogWatchdogFlag_ClearFlag(ADC_TypeDef *ADCx){
	ClearBit(ADCx->SR, ADC_SR_AWD_Pos);
}


/*
ADC_JDRx, Bits 15:0
JDATA[15:0]: Injected data
							These bits are read only.
							They contain the conversion result from injected channel x.
*/
// Need to check
__STATIC_INLINE uint16_t ADC_InjectedData_GetConversionResult(ADC_TypeDef *ADCx){
	uint16_t data = ADCx->JDR1 & 0xFFFFUL;
	return data;
}


/*
ADC_DR, Bits 31:16
ADC2DATA[15:0]: ADC2 data
								These bits are read only.
								In ADC1: In dual mode, these bits contain the regular data of ADC2.
								In ADC2 and ADC3: these bits are not used.					
*/

__STATIC_INLINE uint16_t ADC_RegularDataInDualMode_GetConversionResult_ADC2Data(void){
	uint16_t data = ((ADC1->DR) >> 16) & 0xFFFFUL;
	return data;
}


/*
ADC_DR, Bits 15:0
DATA[15:0]:	Regular data
						These bits are read only.
						They contain the conversion result from the regular channels.
*/

__STATIC_INLINE uint16_t ADC_RegularData_GetConversionResult(ADC_TypeDef *ADCx){
	uint16_t data = ADCx->DR & 0xFFFFUL;
	return data;
}


#ifdef __cplusplus
}
#endif

#endif		// _STM32F1XX_BM_ADC_INCLUDED