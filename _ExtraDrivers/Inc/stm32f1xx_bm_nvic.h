// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>

#ifndef _STM32F1xx_BM_NVIC_INCLUDED_INCLUDED
    #define _STM32F1xx_BM_NVIC_INCLUDED_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

void NVIC_ConfigGroup(void);

void NVIC_USART1_Config(void);
void NVIC_USART2_Config(void);

void NVIC_EXTI0_Config(void);
void NVIC_EXTI1_Config(void);
void NVIC_EXTI2_Config(void);
void NVIC_EXTI3_Config(void);
void NVIC_EXTI4_Config(void);
void NVIC_EXTI9To5_Config(void);
void NVIC_EXTI15To10_Config(void);

#ifdef __cplusplus
}
#endif

#endif		// _STM32F1xx_BM_NVIC_INCLUDED_INCLUDED