// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

/*
	Abbreviations:
	EXTI: External Interrupt
*/

#include <stm32f1xx.h>

#include <utility.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
//#include <stm32f1xx_bm_nvic.h>

#ifndef _STM32F1xx_BM_EXTI_INCLUDED
#define _STM32F1xx_BM_EXTI_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#define EXTI_PORTA	0b0000U
#define EXTI_PORTB	0b0001U
#define EXTI_PORTC	0b0010U
#define EXTI_PORTD	0b0011U
#define EXTI_PORTE	0b0100U
#define EXTI_PORTF	0b0101U
#define EXTI_PORTG	0b0110U

#define EXTI_INT0		((0U<<8)  | (0U<<4) | (0U<<0))  // LINE0, EXTICR[0], EXTI0_Pos
#define EXTI_INT1		((1U<<8)  | (0U<<4) | (4U<<0))  // LINE1, EXTICR[0], EXTI1_Pos
#define EXTI_INT2		((2U<<8)  | (0U<<4) | (8U<<0))  // LINE2, EXTICR[0], EXTI2_Pos
#define EXTI_INT3		((3U<<8)  | (0U<<4) | (12U<<0)) // LINE3, EXTICR[0], EXTI3_Pos
#define EXTI_INT4		((4U<<8)  | (1U<<4) | (0U<<0))  // LINE4, EXTICR[1], EXTI4_Pos
#define EXTI_INT5		((5U<<8)  | (1U<<4) | (4U<<0))  // LINE5, EXTICR[1], EXTI5_Pos
#define EXTI_INT6		((6U<<8)  | (1U<<4) | (8U<<0))  // LINE6, EXTICR[1], EXTI6_Pos
#define EXTI_INT7		((7U<<8)  | (1U<<4) | (12U<<0)) // LINE7, EXTICR[1], EXTI7_Pos
#define EXTI_INT8		((8U<<8)  | (2U<<4) | (0U<<0))  // LINE8, EXTICR[2], EXTI8_Pos
#define EXTI_INT9		((9U<<8)  | (2U<<4) | (4U<<0))  // LINE9, EXTICR[2], EXTI9_Pos
#define EXTI_INT10	((10U<<8) | (2U<<4) | (8U<<0))  // LINE10, EXTICR[2], EXTI10_Pos
#define EXTI_INT11	((11U<<8) | (2U<<4) | (12U<<0)) // LINE11, EXTICR[2], EXTI11_Pos
#define EXTI_INT12	((12U<<8) | (3U<<4) | (0U<<0))  // LINE12, EXTICR[3], EXTI12_Pos
#define EXTI_INT13	((13U<<8) | (3U<<4) | (4U<<0))  // LINE13, EXTICR[3], EXTI13_Pos
#define EXTI_INT14  ((14U<<8) | (3U<<4) | (8U<<0))  // LINE14, EXTICR[3], EXTI4_Pos
#define EXTI_INT15	((15U<<8) | (3U<<4) | (12U<<0)) // LINE15, EXTICR[3], EXTI15_Pos

__STATIC_INLINE void EXTI_SetSource(uint32_t LINE, uint32_t PORT){
	Write4Bit(AFIO->EXTICR[Get4Bit(LINE,4)], Get4Bit(LINE,0), PORT);
}
/*#define EXTI_SetSource(LINE, PORT) \
	Write4Bit(AFIO->EXTICR[Get4Bit(LINE,4)], Get4Bit(LINE,0), PORT);*/

__STATIC_INLINE uint32_t EXTI_InterruptMode_GetEnableStatus(uint32_t LINE){
		return ( GetBit(EXTI->IMR, Get4Bit(LINE,8)) );
}
/*#define EXTI_InterruptMode_GetEnableStatus(LINE) \
	GetBit(EXTI->IMR, Get4Bit(LINE,8))*/
__STATIC_INLINE void EXTI_InterruptMode_EnableOrDisable(uint32_t LINE, uint32_t STATUS){
		WriteBit(EXTI->IMR, Get4Bit(LINE,8), STATUS);
}
/*#define EXTI_InterruptMode_EnableOrDisable(LINE, STATUS) \
	WriteBit(EXTI->IMR, Get4Bit(LINE,8), STATUS);*/
/*
#define EXTI0_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT0, STATUS);
#define EXTI1_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT1, STATUS);
#define EXTI2_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT2, STATUS);
#define EXTI3_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT3, STATUS);
#define EXTI4_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT4, STATUS);
#define EXTI5_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT5, STATUS);
#define EXTI6_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT6, STATUS);
#define EXTI7_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT7, STATUS);
#define EXTI8_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT8, STATUS);
#define EXTI9_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT9, STATUS);
#define EXTI10_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT10, STATUS);
#define EXTI11_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT11, STATUS);
#define EXTI12_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT12, STATUS);
#define EXTI13_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT13, STATUS);
#define EXTI14_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT14, STATUS);
#define EXTI15_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT15, STATUS);
*/

__STATIC_INLINE uint32_t EXTI_EventMode_GetEnableStatus(uint32_t LINE){
	return ( GetBit(EXTI->EMR,Get4Bit(LINE,8)) );
}
__STATIC_INLINE void EXTI_EventMode_EnableOrDisable(uint32_t LINE, uint32_t STATUS){
	WriteBit(EXTI->EMR,Get4Bit(LINE,8), STATUS);
}
/*#define EXTI_EventMode_GetEnableStatus(LINE) \
	GetBit(EXTI->EMR,Get4Bit(LINE,8))*/
/*#define EXTI_EventMode_EnableOrDisable(LINE, STATUS) \
	WriteBit(EXTI->EMR,Get4Bit(LINE,8), STATUS);*/
/*
#define EXTI0_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT0, STATUS);
#define EXTI1_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT1, STATUS);
#define EXTI2_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT2, STATUS);
#define EXTI3_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT3, STATUS);
#define EXTI4_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT4, STATUS);
#define EXTI5_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT5, STATUS);
#define EXTI6_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT6, STATUS);
#define EXTI7_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT7, STATUS);
#define EXTI8_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT8, STATUS);
#define EXTI9_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT9, STATUS);
#define EXTI10_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT10, STATUS);
#define EXTI11_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT11, STATUS);
#define EXTI12_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT12, STATUS);
#define EXTI13_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT13, STATUS);
#define EXTI14_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT14, STATUS);
#define EXTI15_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT15, STATUS);
*/

__STATIC_INLINE uint32_t EXTI_RisingTrigger_GetEnableStatus(uint32_t LINE){
	return ( GetBit(EXTI->RTSR, Get4Bit(LINE,8)) );
}
__STATIC_INLINE void EXTI_RisingTrigger_EnableOrDisable(uint32_t LINE, uint32_t STATUS){
	WriteBit(EXTI->RTSR, Get4Bit(LINE,8),STATUS);
}
/*#define EXTI_RisingTrigger_GetEnableStatus(LINE) \
	GetBit(EXTI->RTSR, Get4Bit(LINE,8))
#define EXTI_RisingTrigger_EnableOrDisable(LINE, STATUS) \
	WriteBit(EXTI->RTSR, Get4Bit(LINE,8),STATUS);*/
/*
#define EXTI0_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT0, STATUS);
#define EXTI1_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT1, STATUS);
#define EXTI2_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT2, STATUS);
#define EXTI3_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT3, STATUS);
#define EXTI4_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT4, STATUS);
#define EXTI5_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT5, STATUS);
#define EXTI6_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT6, STATUS);
#define EXTI7_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT7, STATUS);
#define EXTI8_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT8, STATUS);
#define EXTI9_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT9, STATUS);
#define EXTI10_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT10, STATUS);
#define EXTI11_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT11, STATUS);
#define EXTI12_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT12, STATUS);
#define EXTI13_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT13, STATUS);
#define EXTI14_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT14, STATUS);
#define EXTI15_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT15, STATUS);
*/

__STATIC_INLINE uint32_t EXTI_FallingTrigger_GetEnableStatus(uint32_t LINE){
	return ( GetBit(EXTI->FTSR, Get4Bit(LINE,8)) );
}
__STATIC_INLINE void EXTI_FallingTrigger_EnableOrDisable(uint32_t LINE, uint32_t STATUS){
	WriteBit(EXTI->FTSR, Get4Bit(LINE,8),STATUS);
}

/*#define EXTI_FallingTrigger_GetEnableStatus(LINE) \
	GetBit(EXTI->FTSR, Get4Bit(LINE,8))
#define EXTI_FallingTrigger_EnableOrDisable(LINE, STATUS) \
	WriteBit(EXTI->FTSR, Get4Bit(LINE,8),STATUS);*/
/*
#define EXTI0_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT0, STATUS);
#define EXTI1_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT1, STATUS);
#define EXTI2_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT2, STATUS);
#define EXTI3_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT3, STATUS);
#define EXTI4_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT4, STATUS);
#define EXTI5_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT5, STATUS);
#define EXTI6_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT6, STATUS);
#define EXTI7_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT7, STATUS);
#define EXTI8_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT8, STATUS);
#define EXTI9_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT9, STATUS);
#define EXTI10_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT10, STATUS);
#define EXTI11_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT11, STATUS);
#define EXTI12_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT12, STATUS);
#define EXTI13_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT13, STATUS);
#define EXTI14_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT14, STATUS);
#define EXTI15_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT15, STATUS);
*/

__STATIC_INLINE uint32_t EXTI_SoftwareInterrupt_GetEnableStatus(uint32_t LINE){
	return ( GetBit(EXTI->SWIER, Get4Bit(LINE,8)) );
}
__STATIC_INLINE void EXTI_SoftwareInterrupt_EnableOrDisable(uint32_t LINE, uint32_t STATUS){
	WriteBit(EXTI->SWIER, Get4Bit(LINE,8),STATUS);
}

/*#define EXTI_SoftwareInterrupt_GetEnableStatus(LINE) \
	GetBit(EXTI->SWIER, Get4Bit(LINE,8))
#define EXTI_SoftwareInterrupt_EnableOrDisable(LINE, STATUS) \
	WriteBit(EXTI->SWIER, Get4Bit(LINE,8),STATUS);*/
/*
#define EXTI0_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT0, STATUS);
#define EXTI1_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT1, STATUS);
#define EXTI2_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT2, STATUS);
#define EXTI3_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT3, STATUS);
#define EXTI4_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT4, STATUS);
#define EXTI5_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT5, STATUS);
#define EXTI6_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT6, STATUS);
#define EXTI7_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT7, STATUS);
#define EXTI8_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT8, STATUS);
#define EXTI9_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT9, STATUS);
#define EXTI10_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT10, STATUS);
#define EXTI11_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT11, STATUS);
#define EXTI12_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT12, STATUS);
#define EXTI13_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT13, STATUS);
#define EXTI14_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT14, STATUS);
#define EXTI15_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT15, STATUS);
*/

__STATIC_INLINE uint32_t EXTI_GetActiveFlag(uint32_t LINE){
	return ( GetBit(EXTI->PR, Get4Bit(LINE,8)) );
}
__STATIC_INLINE void EXTI_ClearPendingRegister(uint32_t LINE){
	SetBit_NoLastStatus(EXTI->PR, Get4Bit(LINE,8));
}
/*#define EXTI_GetActiveFlag(LINE) \
	GetBit(EXTI->PR, Get4Bit(LINE,8))
#define EXTI_ClearPendingRegister(LINE) \
	SetBit_NoLastStatus(EXTI->PR, Get4Bit(LINE,8));*/

// stm32f1xx_bm_exti_local.c
void EXTI_Config(void);
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler(void);


#ifdef __cplusplus
}
#endif

#endif	// _STM32F1xx_BM_EXTI_INCLUDED

		