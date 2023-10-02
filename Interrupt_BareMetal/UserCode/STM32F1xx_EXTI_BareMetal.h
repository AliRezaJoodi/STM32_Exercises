// GitHub Account: GitHub.com/AliRezaJoodi

/*
	Abbreviations:
	EXTI: External Interrupt
*/

#include "stm32f1xx.h"
#include "Utility.h"
#include "STM32F1xx_GPIO_BareMetal.h"

#ifndef _EXTI_INCLUDED
	#define _EXTI_INCLUDED

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

#define EXTI_SetSource(PORT, LINE) \
	Write4Bit(AFIO->EXTICR[Get4Bit(LINE,4)], Get4Bit(LINE,0), PORT);

#define EXTI_InterruptMode_GetEnableStatus(LINE) \
	GetBit(EXTI->IMR, Get4Bit(LINE,8))
#define EXTI_InterruptMode_EnableOrDisable(LINE, STATUS) \
	WriteBit(EXTI->IMR, Get4Bit(LINE,8), STATUS);
#define EXTI_INT0_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT0, STATUS);
#define EXTI_INT1_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT1, STATUS);
#define EXTI_INT2_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT2, STATUS);
#define EXTI_INT3_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT3, STATUS);
#define EXTI_INT4_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT4, STATUS);
#define EXTI_INT5_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT5, STATUS);
#define EXTI_INT6_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT6, STATUS);
#define EXTI_INT7_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT7, STATUS);
#define EXTI_INT8_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT8, STATUS);
#define EXTI_INT9_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT9, STATUS);
#define EXTI_INT10_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT10, STATUS);
#define EXTI_INT11_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT11, STATUS);
#define EXTI_INT12_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT12, STATUS);
#define EXTI_INT13_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT13, STATUS);
#define EXTI_INT14_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT14, STATUS);
#define EXTI_INT15_InterruptMode_EnableOrDisable(STATUS) \
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT15, STATUS);

#define EXTI_EventMode_GetEnableStatus(LINE) \
	GetBit(EXTI->EMR,Get4Bit(LINE,8))
#define EXTI_EventMode_EnableOrDisable(LINE, STATUS) \
	WriteBit(EXTI->EMR,Get4Bit(LINE,8), STATUS);
#define EXTI_INT0_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT0, STATUS);
#define EXTI_INT1_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT1, STATUS);
#define EXTI_INT2_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT2, STATUS);
#define EXTI_INT3_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT3, STATUS);
#define EXTI_INT4_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT4, STATUS);
#define EXTI_INT5_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT5, STATUS);
#define EXTI_INT6_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT6, STATUS);
#define EXTI_INT7_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT7, STATUS);
#define EXTI_INT8_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT8, STATUS);
#define EXTI_INT9_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT9, STATUS);
#define EXTI_INT10_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT10, STATUS);
#define EXTI_INT11_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT11, STATUS);
#define EXTI_INT12_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT12, STATUS);
#define EXTI_INT13_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT13, STATUS);
#define EXTI_INT14_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT14, STATUS);
#define EXTI_INT15_EventMode_EnableOrDisable(STATUS) \
	EXTI_EventMode_EnableOrDisable(EXTI_INT15, STATUS);

#define EXTI_RisingTrigger_GetEnableStatus(LINE) \
	GetBit(EXTI->RTSR, Get4Bit(LINE,8))
#define EXTI_RisingTrigger_EnableOrDisable(LINE, STATUS) \
	WriteBit(EXTI->RTSR, Get4Bit(LINE,8),STATUS);
#define EXTI_INT0_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT0, STATUS);
#define EXTI_INT1_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT1, STATUS);
#define EXTI_INT2_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT2, STATUS);
#define EXTI_INT3_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT3, STATUS);
#define EXTI_INT4_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT4, STATUS);
#define EXTI_INT5_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT5, STATUS);
#define EXTI_INT6_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT6, STATUS);
#define EXTI_INT7_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT7, STATUS);
#define EXTI_INT8_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT8, STATUS);
#define EXTI_INT9_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT9, STATUS);
#define EXTI_INT10_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT10, STATUS);
#define EXTI_INT11_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT11, STATUS);
#define EXTI_INT12_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT12, STATUS);
#define EXTI_INT13_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT13, STATUS);
#define EXTI_INT14_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT14, STATUS);
#define EXTI_INT15_RisingTrigger_EnableOrDisable(STATUS) \
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT15, STATUS);

#define EXTI_FallingTrigger_GetEnableStatus(LINE) \
	GetBit(EXTI->FTSR, Get4Bit(LINE,8))
#define EXTI_FallingTrigger_EnableOrDisable(LINE, STATUS) \
	WriteBit(EXTI->FTSR, Get4Bit(LINE,8),STATUS);
#define EXTI_INT0_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT0, STATUS);
#define EXTI_INT1_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT1, STATUS);
#define EXTI_INT2_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT2, STATUS);
#define EXTI_INT3_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT3, STATUS);
#define EXTI_INT4_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT4, STATUS);
#define EXTI_INT5_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT5, STATUS);
#define EXTI_INT6_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT6, STATUS);
#define EXTI_INT7_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT7, STATUS);
#define EXTI_INT8_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT8, STATUS);
#define EXTI_INT9_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT9, STATUS);
#define EXTI_INT10_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT10, STATUS);
#define EXTI_INT11_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT11, STATUS);
#define EXTI_INT12_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT12, STATUS);
#define EXTI_INT13_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT13, STATUS);
#define EXTI_INT14_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT14, STATUS);
#define EXTI_INT15_FallingTrigger_EnableOrDisable(STATUS) \
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT15, STATUS);

#define EXTI_SoftwareInterrupt_GetEnableStatus(LINE) \
	GetBit(EXTI->SWIER, Get4Bit(LINE,8))
#define EXTI_SoftwareInterrupt_EnableOrDisable(LINE, STATUS) \
	WriteBit(EXTI->SWIER, Get4Bit(LINE,8),STATUS);
#define EXTI_INT0_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT0, STATUS);
#define EXTI_INT1_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT1, STATUS);
#define EXTI_INT2_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT2, STATUS);
#define EXTI_INT3_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT3, STATUS);
#define EXTI_INT4_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT4, STATUS);
#define EXTI_INT5_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT5, STATUS);
#define EXTI_INT6_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT6, STATUS);
#define EXTI_INT7_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT7, STATUS);
#define EXTI_INT8_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT8, STATUS);
#define EXTI_INT9_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT9, STATUS);
#define EXTI_INT10_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT10, STATUS);
#define EXTI_INT11_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT11, STATUS);
#define EXTI_INT12_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT12, STATUS);
#define EXTI_INT13_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT13, STATUS);
#define EXTI_INT14_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT14, STATUS);
#define EXTI_INT15_SoftwareInterrupt_EnableOrDisable(STATUS) \
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT15, STATUS);

#define EXTI_GetActiveFlag(LINE) \
	GetBit(EXTI->PR, Get4Bit(LINE,8))
#define EXTI_ClearPendingRegister(LINE) \
	SetBit_NoLastStatus(EXTI->PR, Get4Bit(LINE,8));

void EXTI_INT0_ConfigureNVIC(void);
void EXTI_INT1_ConfigureNVIC(void);
void EXTI_INT2_ConfigureNVIC(void);
void EXTI_INT3_ConfigureNVIC(void);
void EXTI_INT4_ConfigureNVIC(void);
void EXTI_INT5To9_ConfigureNVIC(void);
void EXTI_INT10To15_ConfigureNVIC(void);

// _EXTI.c
void EXTI_Configuration(void);
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

#endif

		