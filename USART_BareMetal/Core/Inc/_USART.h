// GitHub Account: GitHub.com/AliRezaJoodi

#include "stm32f1xx_ll_rcc.h"
#include "stm32f1xx_ll_utils.h"
#include "stm32f1xx_ll_usart.h"

#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "STM32F1xx_USART_BareMetal.h"

#ifndef _USART_H
	#define _USART_H

#ifdef __cplusplus
	extern "C" {
#endif

void USART1_Configure(void);
void USART1_IRQHandler(void);

#ifdef __cplusplus
	}
#endif

#endif
