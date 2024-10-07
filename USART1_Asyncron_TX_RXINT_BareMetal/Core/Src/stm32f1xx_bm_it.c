// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_it.h>

/* List:
	SysTick_IRQn
	USART1_IRQn
	USART2_IRQn
	USART3_IRQn
	EXTI0_IRQn
	EXTI1_IRQn
	EXTI2_IRQn
	EXTI3_IRQn
	EXTI4_IRQn
	EXTI9_5_IRQn
	EXTI15_10_IRQn
*/
//**********************************************************
void NVIC_Config(void){	
	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	
	NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(USART1_IRQn);
}

//*****************************************
void SysTick_Handler(void){

}

//*****************************************
void USART1_IRQHandler(void){
	extern char usart1_txt[16];
	extern char usart1_task;
	char c;
	static unsigned char i=0;

	if(USART_RX_GetReceiveFlag(USART1) && USART_RX_INT_GetEnableStatus(USART1)){		
		c = USART_ReceiveData_8Bits(USART1);
		USART_TransmitData_8Bits(USART1, c);
		if(32<=c && c<127){usart1_txt[i]=c; ++i;}
			else if(c==13){i=0; usart1_task=1;}
	}
}

//*****************************************
void _USART1_IRQHandler(void){
	if(USART_RX_GetReceiveFlag(USART1) && USART_RX_INT_GetEnableStatus(USART1)){		
		char chr = USART_ReceiveData_8Bits(USART1);
		USART_TransmitData_8Bits(USART1, chr);
	}
}

//*****************************************
void USART2_IRQHandler(void){
	if(USART_RX_GetReceiveFlag(USART2) && USART_RX_INT_GetEnableStatus(USART2)){		
		char chr = USART_ReceiveData_8Bits(USART2);
		USART_TransmitData_8Bits(USART2, chr);
	}
}

//*****************************************
void USART3_IRQHandler(void){
	if(USART_RX_GetReceiveFlag(USART3) && USART_RX_INT_GetEnableStatus(USART3)){		
		char chr = USART_ReceiveData_8Bits(USART3);
		USART_TransmitData_8Bits(USART3, chr);
	}
}

//*****************************************
void EXTI0_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT0) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT0);
  }
}

//*****************************************
void EXTI1_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT1) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT1);
		
  }
}

//*****************************************
void EXTI2_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT2) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT2);
		
  }
}

//*****************************************
void EXTI3_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT3) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT3);
		
  }
}

//*****************************************
void EXTI4_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT4) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT4);
		
  }
}

//*****************************************
void EXTI9_5_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT6) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT6);
  }
}

//*****************************************
void EXTI15_10_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT11) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT11);
  }
}

