// GitHub Account: GitHub.com/AliRezaJoodi
#include "Utility.h"

#ifndef _GPIO_INCLUDED
    #define _GPIO_INCLUDED

// Serial Wire JTAG Configuration
#define FULL_SWJ												0b000U
#define FULL_SWJ_WITHOUT_NJTRST					0b001U
#define JTAG_DISABLED_AND_SWD_ENABLED		0b010U
#define JTAG_DISABLED_AND_SWD_DISABLED	0b100U
#define ConfigureSerialWireDebugPort(MODE) \
	AFIO->MAPR= (AFIO->MAPR & ~AFIO_MAPR_SWJ_CFG) | (MODE<<AFIO_MAPR_SWJ_CFG_Pos);

// Pin Direction Configuration
#define INPUT_MODE          0b00UL
#define OUTPUT_MODE_10MHz   0b01UL
#define OUTPUT_MODE_2MHz    0b10UL
#define OUTPUT_MODE_50MHz		0b11UL
#define GPIO_ConfigurePinDirection(GPIOx,PIN,MODE) \
	if(PIN<=7){(GPIOx->CRL)= ((GPIOx->CRL) & ~(0b11UL<<(PIN*4))) | ((MODE&0b11UL)<<(PIN*4));}\
		else{(GPIOx->CRH)= ((GPIOx->CRH) & ~(0b11UL<<((PIN-8)*4))) | ((MODE&0b11UL)<<((PIN-8)*4));}

// Input Mode Configuration
#define ANALOG_MODE               	0b00UL
#define FLOATING_INPUT							0b01UL
#define INPUT_WITH_PULLUP_PULLDOWN	0b10UL
#define GPIO_ConfigureInputMode(GPIOx,PIN,MODE) \
		if(PIN<=7){(GPIOx->CRL)= ((GPIOx->CRL) & ~(0b11UL<<((PIN*4)+2))) | ((MODE&0b11UL)<<((PIN*4)+2));}\
			else{(GPIOx->CRH)= ((GPIOx->CRH) & ~(0b11UL<<(((PIN-8)*4)+2))) | ((MODE&0b11UL)<<(((PIN-8)*4)+2));}

//Pull-up or Pull-down Configuration
#define PULLDOWN	0
#define PULLUP		1
#define GPIO_ConfigurePullUpOrPullDown(GPIOx,PIN,MODE) \
	GPIOx->ODR= (GPIOx->ODR & ~(0b1UL << PIN)) | ((MODE&0b1UL) << PIN);

// Output Mode Configuration
#define GENERAL_PURPOSE_OUTPUT_PUSHPULL  		0b00UL
#define GENERAL_PURPOSE_OUTPUT_OPENDRAIN 		0b01UL
#define ALTERNATE_FUNCTION_OUTPUT_PUSHPULL	0b10UL
#define ALTERNATE_FUNCTION_OUTPUT_OPENDRAIN	0b11UL
#define GPIO_ConfigureOutputMode(GPIOx,PIN,MODE) \
	if(PIN<=7){(GPIOx->CRL)= ((GPIOx->CRL) & ~(0b11UL<<((PIN*4)+2))) | ((MODE&0b11UL)<<((PIN*4)+2));}\
		else{(GPIOx->CRH)= ((GPIOx->CRH) & ~(0b11UL<<(((PIN-8)*4)+2))) | ((MODE&0b11UL)<<(((PIN-8)*4)+2));}

// Other Commands																												
#define GPIO_GetInputPin(GPIOx,PIN) 									(((GPIOx->IDR) & (0b1UL<<PIN)) >> PIN)
#define GPIO_GetInputPort(GPIOx)											(GPIOx->IDR)
																												
#define GPIO_SetOutputPinWithBSRR(GPIOx,PIN) 					GPIOx->BSRR = 0b1UL<<PIN;	//Fast
#define GPIO_SetOutputPinWithODR(GPIOx,PIN) 					(GPIOx->ODR) |= (0b1UL<<PIN);
#define GPIO_SetOutputPin(GPIOx,PIN) 									GPIO_SetOutputPinWithBSRR(GPIOx,PIN)
#define GPIO_ResetOutputPinWithBRR(GPIOx,PIN) 				(GPIOx->BRR) = (0b1UL<<PIN);	//Fast
#define GPIO_ResetOutputPinWithODR(GPIOx,PIN) 				(GPIOx->ODR) &= ~(0b1U<<PIN);
#define GPIO_ResetOutputPinWithBSRR(GPIOx,PIN) 				(GPIOx->BSRR) = (0b1U<<(PIN+16));
#define GPIO_ResetOutputPin(GPIOx,PIN)								GPIO_ResetOutputPinWithBRR(GPIOx,PIN)
#define GPIO_ToggleOutputPin(GPIOx,PIN)								(GPIOx->ODR) ^= ( 0b1UL<<PIN);
#define GPIO_WriteOutputPin(GPIOx,PIN,STATUS)					GPIOx->ODR= (GPIOx->ODR & ~(0b1UL << PIN)) | ((STATUS&0b1UL) << PIN);
#define GPIO_WriteOutputPort(GPIOx,VALUE)							(GPIOx->ODR) = VALUE;
#define GPIO_GetOutputPin(GPIOx,PIN) 									(((GPIOx->ODR) & (0b1UL<<PIN)) >> PIN)

#endif

