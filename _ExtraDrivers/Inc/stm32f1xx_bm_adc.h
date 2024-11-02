// GitHub Account: GitHub.com/AliRezaJoodi

/*
It's about:
	ADC_SR:		ADC status register
	ADC_JDRx:	ADC injected data register x
	ADC_DR:		ADC regular data register
	ADC_CR1:	ADC control register 1
	ADC_CR2:	ADC control register 2
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
#include <timeout.h>

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


/*
ADC_CR1, Bit 5
EOCIE: Interrupt enable for EOC
			This bit is set and cleared by software to enable/disable the End of Conversion interrupt.
			0: EOC interrupt disabled
			1: EOC interrupt enabled. An interrupt is generated when the EOC bit is set.
*/

__STATIC_INLINE uint32_t _EndOfConversionInterrupt_GetEnableStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR1, ADC_CR1_EOSIE_Pos) );
}

__STATIC_INLINE void ADC_EndOfConversionInterrupt_EnableOrDisable(ADC_TypeDef *ADCx, uint32_t status){
	WriteBit(ADCx->CR1, ADC_CR1_EOSIE_Pos, status);
}


/*
ADC_CR2, Bit 22
SWSTART: 	Start conversion of regular channels
					This bit is set by software to start conversion and cleared by hardware as soon as conversion starts. 
					It starts a conversion of a group of regular channels 
					if SWSTART is selected as trigger event by the EXTSEL[2:0] bits.
					0: Reset state
					1: Starts conversion of regular channels
*/

__STATIC_INLINE uint32_t _StartConversionOfRegularChannels_GetStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR2, ADC_CR2_SWSTART_Pos) );
}

__STATIC_INLINE void ADC_StartConversionOfRegularChannels_Start(ADC_TypeDef *ADCx){
	SetBit(ADCx->CR2, ADC_CR2_SWSTART_Pos);
	
	while(_StartConversionOfRegularChannels_GetStatus(ADC1) != 0){}
}


/*
ADC_CR2, Bit 21
JSWSTART: Start conversion of injected channels
					This bit is set by software and cleared by software or by hardware as soon as the conversion starts.
					It starts a conversion of a group of injected channels (if JSWSTART is selected as trigger event by the JEXTSEL[2:0] bits.
					0: Reset state
					1: Starts conversion of injected channels
*/

__STATIC_INLINE uint32_t _StartConversionOfInjectedChannels_GetStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR2, ADC_CR2_JSWSTART_Pos) );
}

__STATIC_INLINE void ADC_StartConversionOfInjectedChannels_Start(ADC_TypeDef *ADCx){
	SetBit(ADCx->CR2, ADC_CR2_JSWSTART_Pos);
	
	while(_StartConversionOfInjectedChannels_GetStatus(ADC1) != 0){}
}


/*
ADC_CR2, Bit 20
EXTTRIG: 	External trigger conversion mode for regular channels
					This bit is set and cleared by software to enable/disable the external trigger used to start
					conversion of a regular channel group.
					0: Conversion on external event disabled
					1: Conversion on external event enabled
*/

__STATIC_INLINE uint32_t _ExternalTriggerConversionModeForRegularChannels_GetEnableStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR2, ADC_CR2_EXTTRIG_Pos) );
}

__STATIC_INLINE void ADC_ExternalTriggerConversionModeForRegularChannels_EnableOrDisable(ADC_TypeDef *ADCx, uint32_t status){
	WriteBit(ADCx->CR2, ADC_CR2_EXTTRIG_Pos, status);
}


/*
ADC_CR2, Bit 2
Bit 2 CAL: 	A/D Calibration
						This bit is set by software to start the calibration.
						It is reset by hardware after calibration is complete.
						0: Calibration completed
						1: Enable calibration
*/

__STATIC_INLINE uint32_t _Calibration_GetCompleteStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR2, ADC_CR2_CAL_Pos) );
}

__STATIC_INLINE void ADC_StartCalibration(ADC_TypeDef *ADCx){
	SetBit(ADCx->CR2, ADC_CR2_CAL_Pos);
	
	while(_Calibration_GetCompleteStatus(ADC1) != 0){}
	__NOP();
}


/*
ADC_CR2, Bit 0
ADON: A/D converter ON / OFF
			This bit is set and cleared by software.
			If this bit holds a value of zero and a 1 is written to it then it wakes up the ADC from Power Down state.
			Conversion starts when this bit holds a value of 1 and a 1 is written to it.
			The application should allow a delay of tSTAB between power up and start of conversion.
			0: Disable ADC conversion/calibration and go to power down mode.
			1: Enable ADC and to start conversion.

			Note: If any other bit in this register apart from ADON is changed at the same time,
			then conversion is not triggered. 
			This is to prevent triggering an erroneous conversion.
*/

__STATIC_INLINE uint32_t ADC_GetEnableStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR2, ADC_CR2_ADON_Pos) );
}

__STATIC_INLINE void ADC_EnableOrDisable(ADC_TypeDef *ADCx, uint32_t status){
	WriteBit(ADCx->CR2, ADC_CR2_ADON_Pos, status);	
}


#ifdef __cplusplus
}
#endif

#endif		// _STM32F1XX_BM_ADC_INCLUDED