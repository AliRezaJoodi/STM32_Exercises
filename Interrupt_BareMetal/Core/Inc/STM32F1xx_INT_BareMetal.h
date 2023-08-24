// GitHub Account: GitHub.com/AliRezaJoodi

#include "Utility.h"
#include "stm32f1xx.h"

#ifndef _INT_INCLUDED
    #define _INT_INCLUDED

#define EXTI_PORTA	0b0000U
#define EXTI_PORTB	0b0001U
#define EXTI_PORTC	0b0010U
#define EXTI_PORTD	0b0011U
#define EXTI_PORTE	0b0100U
#define EXTI_PORTF	0b0101U
#define EXTI_PORTG	0b0110U

#define INT0				((0U<<8)  | (0U<<4) | (0U<<0))  // LINE0, EXTICR[0], EXTI0_Pos
#define INT1				((1U<<8)  | (0U<<4) | (4U<<0))  // LINE1, EXTICR[0], EXTI1_Pos
#define INT2				((2U<<8)  | (0U<<4) | (8U<<0))  // LINE2, EXTICR[0], EXTI2_Pos
#define INT3				((3U<<8)  | (0U<<4) | (12U<<0)) // LINE3, EXTICR[0], EXTI3_Pos
#define INT4				((4U<<8)  | (1U<<4) | (0U<<0))  // LINE4, EXTICR[1], EXTI4_Pos
#define INT5				((5U<<8)  | (1U<<4) | (4U<<0))  // LINE5, EXTICR[1], EXTI5_Pos
#define INT6				((6U<<8)  | (1U<<4) | (8U<<0))  // LINE6, EXTICR[1], EXTI6_Pos
#define INT7				((7U<<8)  | (1U<<4) | (12U<<0)) // LINE7, EXTICR[1], EXTI7_Pos
#define INT8				((8U<<8)  | (2U<<4) | (0U<<0))  // LINE8, EXTICR[2], EXTI8_Pos
#define INT9				((9U<<8)  | (2U<<4) | (4U<<0))  // LINE9, EXTICR[2], EXTI9_Pos
#define INT10				((10U<<8) | (2U<<4) | (8U<<0))  // LINE10, EXTICR[2], EXTI10_Pos
#define INT11				((11U<<8) | (2U<<4) | (12U<<0)) // LINE11, EXTICR[2], EXTI11_Pos
#define INT12				((12U<<8) | (3U<<4) | (0U<<0))  // LINE12, EXTICR[3], EXTI12_Pos
#define INT13				((13U<<8) | (3U<<4) | (4U<<0))  // LINE13, EXTICR[3], EXTI13_Pos
#define INT14   		((14U<<8) | (3U<<4) | (8U<<0))  // LINE14, EXTICR[3], EXTI4_Pos
#define INT15				((15U<<8) | (3U<<4) | (12U<<0)) // LINE15, EXTICR[3], EXTI15_Pos

#define ConfigureSourceForEXTI(PORT,LINE) \
	Write4Bit(AFIO->EXTICR[Get4Bit(LINE,4)],Get4Bit(LINE,0),PORT);
	//AFIO->EXTICR[(LINE>>4)&0xF]= \
	//(AFIO->EXTICR[(LINE>>4)&0xF] & (~(0xFU<<(LINE&0xF)))) |\
	//((PORT&0b1111U) << (LINE&0xF));

#define EnableOrDisableInterruptModeForEXTI(LINE,STATUS) \
	WriteBit(EXTI->IMR,Get4Bit(LINE,8),STATUS);
	//EXTI->IMR= (EXTI->IMR & (~(0b1U << ((LINE>>8)&0xF)))) |\
	//((STATUS&0b1U) << ((LINE>>8)&0xF));
#define EnableInterruptModeForEXTI(LINE) \
	SetBit(EXTI->IMR,Get4Bit(LINE,8));
	//EXTI->IMR= (EXTI->IMR) | (0b1U << ((LINE>>8)&0xF));
#define DisableInterruptModeForEXTI(LINE) \
	ClearBit(EXTI->IMR,Get4Bit(LINE,8));
	//EXTI->IMR= (EXTI->IMR) & (~(0b1U << ((LINE>>8)&0xF)));
#define IsEnableInterruptModeForEXTI(LINE) \
	GetBit(EXTI->IMR,Get4Bit(LINE,8))

#define EnableOrDisableEventModeForEXTI(LINE,STATUS) \
	WriteBit(EXTI->EMR,Get4Bit(LINE,8),STATUS);
	//EXTI->EMR= (EXTI->EMR & (~(0b1U << ((LINE>>8)&0xF)))) |\
	//((STATUS&0b1U) << ((LINE>>8)&0xF));
#define EnableEventModeForEXTI(LINE) \
	SetBit(EXTI->EMR,Get4Bit(LINE,8));
	//EXTI->EMR= (EXTI->EMR) | (0b1U << ((LINE>>8)&0xF));
#define DisableEventModeForEXTI(LINE) \
	ClearBit(EXTI->EMR,Get4Bit(LINE,8));
	//EXTI->EMR= (EXTI->EMR) & (~(0b1U << ((LINE>>8)&0xF)));
#define IsEnableEventModeForEXTI(LINE) \
	GetBit(EXTI->EMR,Get4Bit(LINE,8))
	
#define EnableOrDisableRisingTriggerForEXTI(LINE,STATUS) \
	WriteBit(EXTI->RTSR,Get4Bit(LINE,8),STATUS);
	//EXTI->RTSR= (EXTI->RTSR & (~(0b1U << ((LINE>>8)&0xF)))) |\
	//((STATUS&0b1U) << ((LINE>>8)&0xF));
#define EnableRisingTriggerForEXTI(LINE) \
	SetBit(EXTI->RTSR,Get4Bit(LINE,8));
	//EXTI->RTSR= (EXTI->RTSR) | (0b1U << ((LINE>>8)&0xF));
#define DisableRisingTriggerForEXTI(LINE) \
	ClearBit(EXTI->RTSR,Get4Bit(LINE,8));
	//EXTI->RTSR= (EXTI->RTSR) & (~(0b1U << ((LINE>>8)&0xF)));
#define IsEnableRisingTriggerForEXTI(LINE) \
	GetBit(EXTI->RTSR,Get4Bit(LINE,8))
	
#define EnableOrDisableFallingTriggerForEXTI(LINE,STATUS) \
	WriteBit(EXTI->FTSR,Get4Bit(LINE,8),STATUS);
	//EXTI->FTSR= (EXTI->FTSR & (~(0b1U << ((LINE>>8)&0xF)))) |\
	//((STATUS&0b1U) << ((LINE>>8)&0xF));
#define EnableFallingTriggerForEXTI(LINE) \
	SetBit(EXTI->FTSR,Get4Bit(LINE,8));
	//EXTI->FTSR= (EXTI->FTSR) | (0b1U << ((LINE>>8)&0xF));
#define DisableFallingTriggerForEXTI(LINE) \
	ClearBit(EXTI->FTSR,Get4Bit(LINE,8));
	//EXTI->FTSR= (EXTI->FTSR) & (~(0b1U << ((LINE>>8)&0xF)));
#define IsEnableFallingTriggerForEXTI(LINE) \
	GetBit(EXTI->FTSR,Get4Bit(LINE,8));

#define EnableOrDisableSoftwareInterruptForEXTI(LINE,STATUS) \
	WriteBit(EXTI->SWIER,Get4Bit(LINE,8),STATUS);
#define EnableSoftwareInterruptForEXTI(LINE) \
	SetBit(EXTI->SWIER,Get4Bit(LINE,8));
#define DisableSoftwareInterruptForEXTI(LINE) \
	ClearBit(EXTI->SWIER,Get4Bit(LINE,8));
#define IsEnableSoftwareInterruptForEXTI(LINE) \
	GetBit(EXTI->SWIER,Get4Bit(LINE,8))

#define ClearPendingRegisterForEXTI(LINE) \
	SetBit_NoLastStatus(EXTI->PR,Get4Bit(LINE,8));
#define IsActiveFlagForEXTI(LINE) \
	GetBit(EXTI->PR,Get4Bit(LINE,8))
	
#endif

		