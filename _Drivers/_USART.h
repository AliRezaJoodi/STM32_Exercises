// GitHub Account: GitHub.com/AliRezaJoodi

#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "STM32F1xx_USART_BareMetal.h"

#ifndef _USART_H
	#define _USART_H

#ifdef __cplusplus
	extern "C" {
#endif

//#define USART_CR1_OVER16

void USART1_Configuration(void);
void USART1_IRQHandler(void);

#ifdef __cplusplus
	}
#endif

#endif
