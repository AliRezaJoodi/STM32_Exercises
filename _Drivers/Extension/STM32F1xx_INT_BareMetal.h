// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _INT_INCLUDED
    #define _INT_INCLUDED

#define EXTI_PORTA	0b0000U
#define EXTI_PORTB	0b0001U
#define EXTI_PORTC	0b0010U
#define EXTI_PORTD	0b0011U
#define EXTI_PORTE	0b0100U
#define EXTI_PORTF	0b0101U
#define EXTI_PORTG	0b0110U
#define INT0				(0U | 0U<<4)  // EXTICR[0], EXTIx_Pos
#define INT1				(0U | 4U<<4)  // EXTICR[0], EXTIx_Pos
#define INT2				(0U | 8U<<4)  // EXTICR[0], EXTIx_Pos
#define INT3				(0U | 12U<<4) // EXTICR[0], EXTIx_Pos
#define INT4				(1U | 0U<<4)  // EXTICR[1], EXTIx_Pos
#define INT5				(1U | 4U<<4)  // EXTICR[1], EXTIx_Pos
#define INT6				(1U | 8U<<4)  // EXTICR[1], EXTIx_Pos
#define INT7				(1U | 12U<<4) // EXTICR[1], EXTIx_Pos
#define INT8				(2U | 0U<<4)  // EXTICR[2], EXTIx_Pos
#define INT9				(2U | 4U<<4)  // EXTICR[2], EXTIx_Pos
#define INT10				(2U | 8U<<4)  // EXTICR[2], EXTIx_Pos
#define INT11				(2U | 12U<<4) // EXTICR[2], EXTIx_Pos
#define INT12				(3U | 0U<<4)  // EXTICR[3], EXTIx_Pos
#define INT13				(3U | 4U<<4)  // EXTICR[3], EXTIx_Pos
#define INT14   		(3U | 8U<<4)  // EXTICR[3], EXTIx_Pos
#define INT15				(3U | 12U<<4) // EXTICR[3], EXTIx_Pos
#define ConfigureSourceForExternalInterrupt(PORT,LINE) \
	AFIO->EXTICR[LINE&0xF]= \
	(AFIO->EXTICR[LINE&0xF] & (~(0b1111U<<(LINE>>4)))) |\
	((PORT&0b1111U) << (LINE>>4));

#endif

		