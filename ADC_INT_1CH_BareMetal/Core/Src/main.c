#include "stm32f1xx_ll_usart.h"

#include "main.h"
#include "stdio.h"

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_timer_systick.h>
#include <stm32f1xx_bm_usart.h>
#include <stm32f1xx_bm_exti.h>

#include <stm32f1xx_bm_adc.h>
#include <stm32f1xx_bm_it.h>

extern uint16_t adc_value;

static void MX_ADC1_Init(void);

int main(void){
	char txt[20]="";
	float voltage;
			
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWJ_SWD);
	
	RCC_SystemClock_ConfigDefault1();
	USART1_ConfigDefault2_TX();
  MX_ADC1_Init();

  NVIC_Config();
	
	ADC_EnableOrDisable(ADC1, 1);
	ADC_EndOfConversionInterrupt_EnableOrDisable(ADC1, 1);
	ADC_StartCalibration(ADC1);

	ADC_StartConversionInRegularChannels(ADC1);
	ADC_ExternalTriggerForRegularChannels_EnableOrDisable(ADC1, 0);

	LL_USART_TransmitData8(USART1, 13); SysTick_Delay_1ms(1);
	LL_USART_TransmitData8(USART1, 10); SysTick_Delay_1ms(1);
	
  while(1){
		voltage = (float)(adc_value * 3300) / (4095);
		sprintf(txt, "Voltage(mv): %.1f", voltage);
		USART_PutString(USART1, txt);
		
		SysTick_Delay_1ms(500);
  }
}

static void MX_ADC1_Init(void){
	BUS_ADC1_EnableOrDisable(1);

	BUS_GPIOA_EnableOrDisable(1);
	GPIO_SetInputOrOutputMode(GPIOA, 3, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOA, 3, INPUT_ANALOG);
	
	ADC_DataAlignment_SetLeftOrRight(ADC1, ADC_ALIGNMENT_RIGHT);
	ADC_ScanMode_EnableOrDisable(ADC1, 0);	
	ADC_DualMode_SetMode(ADC1, ADC_INDEPENDENT);
	ADC_ExternalEventForRegularGroup_SetMode(ADC1, ADC_EXTSEL_SOFTWARE);
	
	ADC_DiscontinuousModeInRegularChannels_SetChannelCount(ADC1, 1);
	ADC_DiscontinuousModeInRegularChannels_EnableOrDisable(ADC1, 0);
	
	ADC_DMA_EnableOrDisable(ADC1, 0);
	ADC_ContinuousOrSingleConversionMode_SetMode(ADC1, ADC_CONTINUOUS);

	ADC_SequenceLengthInRegularChannels_SetLength(ADC1, 1);
	ADC_ConversionSequenceInRegularChannelsFor1stSequence_SetChannelNumber(ADC1, ADC_SEQUENCE_CH3);
	ADC_SamplingTimeInCh3_SetCycle(ADC1, ADC_SAMPLINGTIME_239CYCLE_5);
}
