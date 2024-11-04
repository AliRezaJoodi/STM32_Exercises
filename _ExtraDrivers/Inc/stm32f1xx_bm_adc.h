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
#include <stm32f1xx_bm_bus.h>

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
ADC_CR1, Bit 23
AWDEN: 	Analog watchdog enable on regular channels
				This bit is set/reset by software.
				0: Analog watchdog disabled on regular channels
				1: Analog watchdog enabled on regular channels
*/

__STATIC_INLINE uint32_t _AnalogWatchdogOnRegularChannels_GetEnableStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR1, ADC_CR1_AWDEN_Pos) );
}

__STATIC_INLINE uint8_t ADC_AnalogWatchdogOnRegularChannels_EnableOrDisable(ADC_TypeDef *ADCx, uint32_t status){
	WriteBit(ADCx->CR1, ADC_CR1_AWDEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_AnalogWatchdogOnRegularChannels_GetEnableStatus, ADCx, status);
	#else
		return 0;
	#endif
}


/*
ADC_CR1, Bit 22
JAWDEN: Analog watchdog enable on injected channels
				This bit is set/reset by software.
				0: Analog watchdog disabled on injected channels
				1: Analog watchdog enabled on injected channels
*/

__STATIC_INLINE uint32_t _AnalogWatchdogOnInjectedChannels_GetEnableStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR1, ADC_CR1_JAWDEN_Pos) );
}

__STATIC_INLINE uint8_t ADC_AnalogWatchdogOnInjectedChannels_EnableOrDisable(ADC_TypeDef *ADCx, uint32_t status){
	WriteBit(ADCx->CR1, ADC_CR1_JAWDEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_AnalogWatchdogOnInjectedChannels_GetEnableStatus, ADCx, status);
	#else
		return 0;
	#endif
}


/*
ADC_CR1, Bits 19:16
DUALMOD[3:0]: Dual mode selection
							These bits are written by software to select the operating mode.
							0000: Independent mode.
							0001: Combined regular simultaneous + injected simultaneous mode
							0010: Combined regular simultaneous + alternate trigger mode
							0011: Combined injected simultaneous + fast interleaved mode
							0100: Combined injected simultaneous + slow Interleaved mode
							0101: Injected simultaneous mode only
							0110: Regular simultaneous mode only
							0111: Fast interleaved mode only
							1000: Slow interleaved mode only
							1001: Alternate trigger mode only

							Note: These bits are reserved in ADC2 and ADC3.
							In dual mode, a change of channel configuration generates a restart that can produce a loss of synchronization. 
							It is recommended to disable dual mode before any configuration change.
*/

#define ADC_INDEPENDENT				0b0000
#define ADC_DUAL_MODE1				0b0001
#define ADC_DUAL_MODE2				0b0010
#define ADC_DUAL_MODE3				0b0011
#define ADC_DUAL_MODE4				0b0100
#define ADC_DUAL_MODE5				0b0101
#define ADC_DUAL_MODE6				0b0110
#define ADC_DUAL_MODE7				0b0111
#define ADC_DUAL_MODE8				0b1000
#define ADC_DUAL_MODE9				0b1001

__STATIC_INLINE uint32_t _DualMode_GetMode(ADC_TypeDef *ADCx){
	return ( Get4Bit(ADCx->CR1, ADC_CR1_DUALMOD_Pos) );
}

__STATIC_INLINE uint8_t ADC_DualMode_SetMode(ADC_TypeDef *ADCx, uint32_t mode){
	Write4Bit(ADCx->CR1, ADC_CR1_DUALMOD_Pos, mode);
	
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_DualMode_GetMode, ADCx, mode);
	#else
		return 0;
	#endif
}


/*
ADC_CR1, 15:13
DISCNUM[2:0]: Discontinuous mode channel count
							These bits are written by software to define the number of regular channels_
							to be converted in discontinuous mode, after receiving an external trigger.
							000: 1 channel
							001: 2 channels
							.......
							111: 8 channels
*/

__STATIC_INLINE uint32_t _DiscontinuousModeOnRegularChannels_GetCountChannels(ADC_TypeDef *ADCx){
	return ( Get3Bit(ADCx->CR1, ADC_CR1_DISCNUM_Pos) );
}

__STATIC_INLINE uint8_t ADC_DiscontinuousModeOnRegularChannels_SetCountChannels(ADC_TypeDef *ADCx, uint32_t count){
	if(count<1 || 8<count){return 1;}
	
	Write3Bit(ADCx->CR1, ADC_CR1_DISCNUM_Pos, (count-1));
	
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_DiscontinuousModeOnRegularChannels_GetCountChannels, ADCx, (count-1));
	#else
		return 0;
	#endif
}


/*
ADC_CR1, Bit 12
JDISCEN: 	Discontinuous mode on injected channels
					This bit set and cleared by software to enable/disable discontinuous mode on injected group channels
					0: Discontinuous mode on injected channels disabled
					1: Discontinuous mode on injected channels enabled
*/

__STATIC_INLINE uint32_t _DiscontinuousModeOnInjectedChannels_GetEnableStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR1, ADC_CR1_JDISCEN_Pos) );
}

__STATIC_INLINE uint8_t ADC_DiscontinuousModeOnInjectedChannels_EnableOrDisable(ADC_TypeDef *ADCx, uint32_t status){
	WriteBit(ADCx->CR1, ADC_CR1_JDISCEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_DiscontinuousModeOnInjectedChannels_GetEnableStatus, ADCx, status);
	#else
		return 0;
	#endif
}


/*
ADC_CR1, Bit 11
DISCEN: Discontinuous mode on regular channels
				This bit set and cleared by software to enable/disable Discontinuous mode on regular channels.
				0: Discontinuous mode on regular channels disabled
				1: Discontinuous mode on regular channels enabled
*/

__STATIC_INLINE uint32_t _DiscontinuousModeOnRegularChannels_GetEnableStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR1, ADC_CR1_DISCEN_Pos) );
}

__STATIC_INLINE uint8_t ADC_DiscontinuousModeOnRegularChannels_EnableOrDisable(ADC_TypeDef *ADCx, uint32_t status){
	WriteBit(ADCx->CR1, ADC_CR1_DISCEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_DiscontinuousModeOnRegularChannels_GetEnableStatus, ADCx, status);
	#else
		return 0;
	#endif
}


/*
ADC_CR1, Bit 10
JAUTO: 	Automatic Injected Group conversion
				This bit set and cleared by software to enable/disable automatic injected group conversion after regular group conversion.
				0: Automatic injected group conversion disabled
				1: Automatic injected group conversion enabled
*/


/*
ADC_CR1, Bit 9
AWDSGL: Enable the watchdog on a single channel in scan mode
				This bit set and cleared by software to enable/disable the analog watchdog on the channel identified by the AWDCH[4:0] bits.
				0: Analog watchdog enabled on all channels
				1: Analog watchdog enabled on a single channel
*/


/*
ADC_CR1, Bit 8
SCAN: Scan mode
			This bit is set and cleared by software to enable/disable Scan mode.
			In Scan mode, the inputs selected through the ADC_SQRx or ADC_JSQRx registers are converted.
			0: Scan mode disabled
			1: Scan mode enabled

			Note: An EOC or JEOC interrupt is generated only on the end of conversion of the last
			channel if the corresponding EOCIE or JEOCIE bit is set
*/

__STATIC_INLINE uint32_t _ScanMode_GetEnableStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR1, ADC_CR1_SCAN_Pos) );
}

__STATIC_INLINE uint8_t ADC_ScanMode_EnableOrDisable(ADC_TypeDef *ADCx, uint32_t status){
	WriteBit(ADCx->CR1, ADC_CR1_SCAN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_ScanMode_GetEnableStatus, ADCx, status);
	#else
		return 0;
	#endif
}


/*
ADC_CR1, Bit 7
JEOCIE: Interrupt enable for injected channels
				This bit is set and cleared by software to enable/disable the end of conversion interrupt for injected channels.
				0: JEOC interrupt disabled
				1: JEOC interrupt enabled. An interrupt is generated when the JEOC bit is set.
*/


/*
ADC_CR1, Bit 6
AWDIE: Analog watchdog interrupt enable
			This bit is set and cleared by software to enable/disable the analog watchdog interrupt.
			0: Analog watchdog interrupt disabled
			1: Analog watchdog interrupt enabled
*/


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

__STATIC_INLINE uint8_t ADC_EndOfConversionInterrupt_EnableOrDisable(ADC_TypeDef *ADCx, uint32_t status){
	WriteBit(ADCx->CR1, ADC_CR1_EOSIE_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_EndOfConversionInterrupt_GetEnableStatus, ADCx, status);
	#else
		return 0;
	#endif
}


/*
ADC_CR1, Bits 4:0
AWDCH[4:0]: Analog watchdog channel select bits
						These bits are set and cleared by software.
						They select the input channel to be guarded by the Analog watchdog.
						00000: ADC analog Channel 0
						00001: ADC analog Channel 1
						....
						01111: ADC analog Channel 15
						10000: ADC analog Channel 16
						10001: ADC analog Channel 17
						Other values: reserved.

						Note: ADC1 analog Channel 16 and Channel 17 are internally connected to the temperature
						sensor and to VREFINT, respectively.
						Note: ADC2 analog inputs Channel 16 and Channel 17 are internally connected to VSS.
						Note: ADC3 analog inputs Channel 9, Channel 14, Channel 15, Channel 16 and Channel 17 are connected to VSS.
*/


/*
ADC_CR2, Bit 23
TSVREFE: Temperature sensor and VREFINT enable
					This bit is set and cleared by software to enable/disable the temperature sensor and VREFINT channel.
					In devices with dual ADCs this bit is present only in ADC1.
					0: Temperature sensor and VREFINT channel disabled
					1: Temperature sensor and VREFINT channel enabled
*/


/*
ADC_CR2, Bit 22
SWSTART: 	Start conversion of regular channels
					This bit is set by software to start conversion and cleared by hardware as soon as conversion starts.
					It starts a conversion of a group of regular channels if SWSTART is selected as trigger event by the EXTSEL[2:0] bits.
					0: Reset state
					1: Starts conversion of regular channels
*/

__STATIC_INLINE uint32_t _StartConversionOfRegularChannels_GetStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR2, ADC_CR2_SWSTART_Pos) );
}

__STATIC_INLINE uint8_t ADC_StartConversionOfRegularChannels_Start(ADC_TypeDef *ADCx){
	SetBit(ADCx->CR2, ADC_CR2_SWSTART_Pos);
	
	//while(_StartConversionOfRegularChannels_GetStatus(ADC1) != 0){}
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_StartConversionOfRegularChannels_GetStatus, ADCx, 0);
	#else
		return 0;
	#endif
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

__STATIC_INLINE uint8_t ADC_StartConversionOfInjectedChannels_Start(ADC_TypeDef *ADCx){
	SetBit(ADCx->CR2, ADC_CR2_JSWSTART_Pos);
	
	//while(_StartConversionOfInjectedChannels_GetStatus(ADC1) != 0){}
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_StartConversionOfInjectedChannels_GetStatus, ADCx, 0);
	#else
		return 0;
	#endif
}


/*
ADC_CR2, Bit 20
EXTTRIG: 	External trigger conversion mode for regular channels
					This bit is set and cleared by software to enable/disable the external trigger used to start
					conversion of a regular channel group.
					0: Conversion on external event disabled
					1: Conversion on external event enabled
*/

__STATIC_INLINE uint32_t _ExternalTriggerForRegularChannels_GetEnableStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR2, ADC_CR2_EXTTRIG_Pos) );
}

__STATIC_INLINE uint8_t ADC_ExternalTriggerForRegularChannels_EnableOrDisable(ADC_TypeDef *ADCx, uint32_t status){
	WriteBit(ADCx->CR2, ADC_CR2_EXTTRIG_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_ExternalTriggerForRegularChannels_GetEnableStatus, ADCx, status);
	#else
		return 0;
	#endif
}


/*
ADC_CR2,Bits 19:17
EXTSEL[2:0]: 	External event select for regular group
							These bits select the external event used to trigger the start of conversion of a regular group:
							For ADC1 and ADC2, the assigned triggers are:
							000: Timer 1 CC1 event
							001: Timer 1 CC2 event
							010: Timer 1 CC3 event
							011: Timer 2 CC2 event
							100: Timer 3 TRGO event
							101: Timer 4 CC4 event
							110: EXTI line 11/TIM8_TRGO event (TIM8_TRGO is available only in high-density and XLdensity devices)
							111: SWSTART

							For ADC3, the assigned triggers are:
							000: Timer 3 CC1 event
							001: Timer 2 CC3 event
							010: Timer 1 CC3 event
							011: Timer 8 CC1 event
							100: Timer 8 TRGO event
							101: Timer 5 CC1 event
							110: Timer 5 CC3 event
							111: SWSTART
*/

#define ADC_EXTSEL_TIM1_CH1			0b000
#define ADC_EXTSEL_TIM1_CH2			0b001
#define ADC_EXTSEL_TIM1_CH3			0b010
#define ADC_EXTSEL_TIM2_CH2			0b011
#define ADC_EXTSEL_TIM3_TRGO		0b100
#define ADC_EXTSEL_TIM4_CH4			0b101
#define ADC_EXTSEL_ETRGREG			0b110
#define ADC_EXTSEL_SOFTWARE			0b111 

#define ADC3_EXTSEL_TIM3_CH1		0b000
#define ADC3_EXTSEL_TIM2_CH3		0b001
#define ADC3_EXTSEL_TIM1_CH3		0b010
#define ADC3_EXTSEL_TIM8_CH1		0b011
#define ADC3_EXTSEL_TIM8_TRGO		0b100
#define ADC3_EXTSEL_TIM5_CH1		0b101
#define ADC3_EXTSEL_TIM5_CH3		0b110
#define ADC3_EXTSEL_SOFTWARE		0b111 

__STATIC_INLINE uint32_t _ExternalEventForRegularGroup_GetMode(ADC_TypeDef *ADCx){
	return ( Get3Bit(ADCx->CR2, ADC_CR2_EXTSEL_Pos) );
}

__STATIC_INLINE uint8_t ADC_ExternalEventForRegularGroup_SetMode(ADC_TypeDef *ADCx, uint32_t mode){
	Write3Bit(ADCx->CR2, ADC_CR2_EXTSEL_Pos, mode);
	
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_ExternalEventForRegularGroup_GetMode, ADCx, mode);
	#else
		return 0;
	#endif
}


/*
ADC_CR2, Bit 15
JEXTTRIG: External trigger conversion mode for injected channels
					This bit is set and cleared by software to enable/disable the external trigger used to start conversion of an injected channel group.
					0: Conversion on external event disabled
					1: Conversion on external event enabled
*/


/*
ADC_CR2, Bits 14:12
JEXTSEL[2:0]: External event select for injected group
							These bits select the external event used to trigger the start of conversion of an injected group:
							For ADC1 and ADC2 the assigned triggers are:
							000: Timer 1 TRGO event
							001: Timer 1 CC4 event
							010: Timer 2 TRGO event
							011: Timer 2 CC1 event
							100: Timer 3 CC4 event
							101: Timer 4 TRGO event
							110: EXTI line15/TIM8_CC4 event (TIM8_CC4 is available only in high-density and XLdensity devices)
							111: JSWSTART
							
							For ADC3 the assigned triggers are:
							000: Timer 1 TRGO event
							001: Timer 1 CC4 event
							010: Timer 4 CC3 event
							011: Timer 8 CC2 event
							100: Timer 8 CC4 event
							101: Timer 5 TRGO event
							110: Timer 5 CC4 event
							111: JSWSTART 
*/


/*
ADC_CR2, Bit 11
ALIGN: 	Data alignment
				This bit is set and cleared by software.
				0: Right Alignment
				1: Left Alignment
*/

#define ADC_ALIGN_RIGHT		0
#define ADC_ALIGN_LEFT		1

__STATIC_INLINE uint32_t _DataAlignment_GetStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR2, ADC_CR2_ALIGN_Pos) );
}

__STATIC_INLINE uint8_t ADC_DataAlignment_LeftOrRight(ADC_TypeDef *ADCx, uint32_t status){
	WriteBit(ADCx->CR2, ADC_CR2_ALIGN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_DataAlignment_GetStatus, ADCx, status);
	#else
		return 0;
	#endif
}


/*
ADC_CR2, Bit 8
DMA: 	Direct memory access mode
			This bit is set and cleared by software. Refer to the DMA controller chapter for more details.
			0: DMA mode disabled
			1: DMA mode enabled

			Note: Only ADC1 and ADC3 can generate a DMA request.
*/

__STATIC_INLINE uint32_t _DMA_GetEnableStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR2, ADC_CR2_DMA_Pos) );
}

__STATIC_INLINE uint8_t ADC_DMA_EnableOrDisable(ADC_TypeDef *ADCx, uint32_t status){
	WriteBit(ADCx->CR2, ADC_CR2_DMA_Pos, status);
		
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_DMA_GetEnableStatus, ADCx, status);
	#else
		return 0;
	#endif
}


/*
ADC_CR2, Bit 3
RSTCAL: Reset calibration
				This bit is set by software and cleared by hardware. It is cleared after the calibration registers are initialized.
				0: Calibration register initialized.
				1: Initialize calibration register.

				Note: If RSTCAL is set when conversion is ongoing, additional cycles are required to clear the calibration registers.
*/


/*
ADC_CR2, Bit 2
CAL: 	A/D Calibration
			This bit is set by software to start the calibration.
			It is reset by hardware after calibration is complete.
			0: Calibration completed
			1: Enable calibration
*/

__STATIC_INLINE uint32_t _Calibration_GetCompleteStatus(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR2, ADC_CR2_CAL_Pos) );
}

__STATIC_INLINE uint8_t ADC_StartCalibration(ADC_TypeDef *ADCx){
	SetBit(ADCx->CR2, ADC_CR2_CAL_Pos);
		
	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_Calibration_GetCompleteStatus, ADCx, 0);
	#else
		return 0;
	#endif
}


/*
ADC_CR2, Bit 1
CONT: Continuous conversion
			This bit is set and cleared by software. If set conversion takes place continuously till this bit is reset.
			0: Single conversion mode
			1: Continuous conversion mode
*/

#define ADC_CONT_SINGLE				0b0
#define ADC_CONT_CONTINUOUS		0b1

__STATIC_INLINE uint32_t _ContinuousOrSingleConversionMode_GetMode(ADC_TypeDef *ADCx){
	return ( GetBit(ADCx->CR2, ADC_CR2_CONT_Pos) );
}

__STATIC_INLINE uint8_t ADC_ContinuousOrSingleConversionMode_SetMode(ADC_TypeDef *ADCx, uint32_t mode){
	WriteBit(ADCx->CR2, ADC_CR2_CONT_Pos, mode);

	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(_ContinuousOrSingleConversionMode_GetMode, ADCx, mode);
	#else
		return 0;
	#endif	
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

__STATIC_INLINE uint8_t ADC_EnableOrDisable(ADC_TypeDef *ADCx, uint32_t status){
	WriteBit(ADCx->CR2, ADC_CR2_ADON_Pos, status);

	#ifdef TIMEOUT_INCLUDED
		return Timeout_ADC_WaitUntil(ADC_GetEnableStatus, ADCx, status);
	#else
		return 0;
	#endif	
}


#ifdef __cplusplus
}
#endif

#endif		// _STM32F1XX_BM_ADC_INCLUDED