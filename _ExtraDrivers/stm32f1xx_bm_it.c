// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_it.h>

/* 
IRG List:
	USART1_IRQn
	USART2_IRQn
	USART3_IRQn
	ADC1_2_IRQn	
	EXTI0_IRQn
	EXTI1_IRQn
	EXTI2_IRQn
	EXTI3_IRQn
	EXTI4_IRQn
	EXTI9_5_IRQn
	EXTI15_10_IRQn
	SysTick_IRQn
	RTC_IRQn
	RTC_Alarm_IRQn
*/
//**********************************************************
void NVIC_Config(void){	
	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
//	__disable_irq();
//	__enable_irq();
	
//	NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
//	NVIC_EnableIRQ(USART1_IRQn);

//	NVIC_SetPriority(USART2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
//	NVIC_EnableIRQ(USART2_IRQn);

//	NVIC_SetPriority(USART3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
//	NVIC_EnableIRQ(USART3_IRQn);

//	NVIC_SetPriority(ADC1_2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
//	NVIC_EnableIRQ(ADC1_2_IRQn);
	
//	NVIC_SetPriority(EXTI0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
//	NVIC_EnableIRQ(EXTI0_IRQn);
	
//	NVIC_SetPriority(EXTI9_5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),1, 0));
//	NVIC_EnableIRQ(EXTI9_5_IRQn);

//	NVIC_SetPriority(EXTI15_10_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),2, 0));
//	NVIC_EnableIRQ(EXTI15_10_IRQn);

//	NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));
//	NVIC_EnableIRQ(SysTick_IRQn);

	NVIC_SetPriority(RTC_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),1, 0));
	NVIC_EnableIRQ(RTC_IRQn);
	
	NVIC_SetPriority(RTC_Alarm_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),2, 0));
	NVIC_EnableIRQ(RTC_Alarm_IRQn);
}

////*****************************************
//void SysTick_Handler(void){

//}

////*****************************************
//void USART1_IRQHandler(void){
//	if(USART_RX_GetReceiveFlag(USART1) && USART_RX_INT_GetEnableStatus(USART1)){		
//		char chr = USART_ReceiveData_8Bits(USART1);
//		USART_TransmitData_8Bits(USART1, chr);
//	}
//}

////*****************************************
//void USART2_IRQHandler(void){
//	if(USART_RX_GetReceiveFlag(USART2) && USART_RX_INT_GetEnableStatus(USART2)){		
//		char chr = USART_ReceiveData_8Bits(USART2);
//		USART_TransmitData_8Bits(USART2, chr);
//	}
//}

////*****************************************
//void USART3_IRQHandler(void){
//	if(USART_RX_GetReceiveFlag(USART3) && USART_RX_INT_GetEnableStatus(USART3)){		
//		char chr = USART_ReceiveData_8Bits(USART3);
//		USART_TransmitData_8Bits(USART3, chr);
//	}
//}

//void ADC1_2_IRQHandler(void){
//	if(ADC_EndOfConversion_GetFlag(ADC1)==1){
//		ADC_EndOfConversion_ClearFlag(ADC1); 
//		//adc_value = ADC_RegularData_GetConversionResult(ADC1); 
//	 }
//}

////*****************************************
//void EXTI0_IRQHandler(void){
//	if (EXTI_GetActiveFlag(EXTI_INT0) != RESET){
//		EXTI_ClearPendingRegister(EXTI_INT0);
//  }
//}

////*****************************************
//void EXTI1_IRQHandler(void){
//	if (EXTI_GetActiveFlag(EXTI_INT1) != RESET){
//		EXTI_ClearPendingRegister(EXTI_INT1);
//		
//  }
//}

////*****************************************
//void EXTI2_IRQHandler(void){
//	if (EXTI_GetActiveFlag(EXTI_INT2) != RESET){
//		EXTI_ClearPendingRegister(EXTI_INT2);
//		
//  }
//}

////*****************************************
//void EXTI3_IRQHandler(void){
//	if (EXTI_GetActiveFlag(EXTI_INT3) != RESET){
//		EXTI_ClearPendingRegister(EXTI_INT3);
//		
//  }
//}

////*****************************************
//void EXTI4_IRQHandler(void){
//	if (EXTI_GetActiveFlag(EXTI_INT4) != RESET){
//		EXTI_ClearPendingRegister(EXTI_INT4);
//		
//  }
//}

////*****************************************
//void EXTI9_5_IRQHandler(void){
//	if (EXTI_GetActiveFlag(EXTI_INT6) != RESET){
//		EXTI_ClearPendingRegister(EXTI_INT6);
//  }
//}

////*****************************************
//void EXTI15_10_IRQHandler(void){
//	if (EXTI_GetActiveFlag(EXTI_INT11) != RESET){
//		EXTI_ClearPendingRegister(EXTI_INT11);
//  }
//}

volatile uint8_t rtc_overflow_task=0;
volatile uint8_t rtc_alarm_task=0;
volatile uint8_t rtc_second_task=0;

//*****************************************
void RTC_IRQHandler(void){
	if(RTC_OverflowFlag_GetFlag() == 1){
		RTC_OverflowFlag_ClearFlag();
		
		USART_PutStringFromFlash(USART1, "RTC_IRQHandler, OverflowFlag");
		rtc_overflow_task=1;
	}
	
	if(RTC_AlarmFlag_GetFlag() == 1){
		RTC_AlarmFlag_ClearFlag();
		
		USART_PutStringFromFlash(USART1, "RTC_Alarm_IRQHandler, AlarmFlag");
		rtc_alarm_task=1;
	}
	
	if(RTC_SecondFlag_GetFlag() == 1){
		RTC_SecondFlag_ClearFlag();
		
		//USART_PutStringFromFlash(USART1, "RTC_IRQHandler, SecondFlag");
		rtc_second_task=1;
	}
}

//*****************************************
void RTC_Alarm_IRQHandler(void){
	if(RTC_AlarmFlag_GetFlag() == 1){
		RTC_AlarmFlag_ClearFlag();
		
		USART_PutStringFromFlash(USART1, "RTC_Alarm_IRQHandler");
	}
}


