// GitHub Account: GitHub.com/AliRezaJoodi

#include "stm32f1xx.h"
#include "Utility.h"

#ifndef _GPIO_INCLUDED
    #define _GPIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


// Serial Wire JTAG Configuration
#define FULL_SWJ												0b000U
#define FULL_SWJ_WITHOUT_NJTRST					0b001U
#define JTAG_DISABLED_AND_SWD_ENABLED		0b010U
#define JTAG_DISABLED_AND_SWD_DISABLED	0b100U
#define AFIO_ConfigureSerialWireDebugPort(MODE) \
	Write3Bit(AFIO->MAPR,AFIO_MAPR_SWJ_CFG_Pos,MODE);
	//AFIO->MAPR= (AFIO->MAPR & ~AFIO_MAPR_SWJ_CFG) | (MODE<<AFIO_MAPR_SWJ_CFG_Pos);

// Pin Direction Configuration
#define INPUT_MODE          0b00UL
#define OUTPUT_MODE_10MHz   0b01UL
#define OUTPUT_MODE_2MHz    0b10UL
#define OUTPUT_MODE_50MHz		0b11UL
#define GPIO_ConfigurePinDirection(GPIOx,PIN,MODE) \
	if(PIN<=7){Write2Bit(GPIOx->CRL,PIN*4,MODE);}\
		else{Write2Bit(GPIOx->CRH,(PIN-8)*4,MODE);}
	//if(PIN<=7){(GPIOx->CRL)= ((GPIOx->CRL) & ~(0b11UL<<(PIN*4))) | ((MODE&0b11UL)<<(PIN*4));}\
		//else{(GPIOx->CRH)= ((GPIOx->CRH) & ~(0b11UL<<((PIN-8)*4))) | ((MODE&0b11UL)<<((PIN-8)*4));}
		
// Input Mode Configuration
#define ANALOG_MODE               	0b00UL
#define FLOATING_INPUT							0b01UL
#define INPUT_WITH_PULLUP_PULLDOWN	0b10UL
#define GPIO_ConfigureInputTypeForPin(GPIOx,PIN,MODE) \
	if(PIN<=7){Write2Bit(GPIOx->CRL,(PIN*4)+2,MODE);}\
		else{Write2Bit(GPIOx->CRH,((PIN-8)*4)+2,MODE);}
	//if(PIN<=7){(GPIOx->CRL)= ((GPIOx->CRL) & ~(0b11UL<<((PIN*4)+2))) | ((MODE&0b11UL)<<((PIN*4)+2));}\
		//else{(GPIOx->CRH)= ((GPIOx->CRH) & ~(0b11UL<<(((PIN-8)*4)+2))) | ((MODE&0b11UL)<<(((PIN-8)*4)+2));}
				
//Pull-up or Pull-down Configuration
#define PULLDOWN	0
#define PULLUP		1
#define GPIO_ConfigurePullUpOrPullDown(GPIOx,PIN,MODE) \
	WriteBit(GPIOx->ODR,PIN,MODE);
	//GPIOx->ODR= (GPIOx->ODR & ~(0b1UL << PIN)) | ((MODE&0b1UL) << PIN);

// Output Mode Configuration
#define GENERAL_PURPOSE_OUTPUT_PUSHPULL  		0b00UL
#define GENERAL_PURPOSE_OUTPUT_OPENDRAIN 		0b01UL
#define ALTERNATE_FUNCTION_OUTPUT_PUSHPULL	0b10UL
#define ALTERNATE_FUNCTION_OUTPUT_OPENDRAIN	0b11UL
#define GPIO_ConfigureOutputTypeForPin(GPIOx,PIN,MODE) \
	if(PIN<=7){Write2Bit(GPIOx->CRL,(PIN*4)+2,MODE);}\
		else{Write2Bit(GPIOx->CRH,((PIN-8)*4)+2,MODE);}
	//if(PIN<=7){(GPIOx->CRL)= ((GPIOx->CRL) & ~(0b11UL<<((PIN*4)+2))) | ((MODE&0b11UL)<<((PIN*4)+2));}\
		//else{(GPIOx->CRH)= ((GPIOx->CRH) & ~(0b11UL<<(((PIN-8)*4)+2))) | ((MODE&0b11UL)<<(((PIN-8)*4)+2));}
																										
#define GPIO_GetPin(GPIOx,PIN) \
	GetBit(GPIOx->IDR,PIN)
	//(((GPIOx->IDR) >> PIN) & 0b1UL)
#define GPIO_Get2Pin(GPIOx,FROM) \
	Get2Bit(GPIOx->IDR,FROM)
	//((GPIOx->IDR >> FROM) & 0b11UL)
#define GPIO_Get3Pin(GPIOx,FROM) \
	Get3Bit(GPIOx->IDR,FROM)
	//((GPIOx->IDR >> FROM) & 0b111UL)
#define GPIO_Get4Pin(GPIOx,FROM) \
	Get4Bit(GPIOx->IDR,FROM)
	//((GPIOx->IDR >> FROM) & 0b1111UL)
#define GPIO_GetPort(GPIOx) \
	(GPIOx->IDR)
																												
#define GPIO_SetPinWithBSRR(GPIOx,PIN) \
	SetBit_NoLastStatus(GPIOx->BSRR,PIN); //Fast
	//GPIOx->BSRR= 0b1UL<<PIN;	//Fast
#define GPIO_SetPinWithODR(GPIOx,PIN) \
	SetBit(GPIOx->ODR,PIN);
	//GPIOx->ODR= (GPIOx->ODR) | (0b1UL<<PIN);
#define GPIO_SetPin(GPIOx,PIN) \
	GPIO_SetPinWithBSRR(GPIOx,PIN);

#define GPIO_ResetPinWithBRR(GPIOx,PIN) \
	SetBit_NoLastStatus(GPIOx->BRR,PIN); //Fast
	//GPIOx->BRR= 0b1UL<<(PIN);	//Fast
#define GPIO_ResetPinWithODR(GPIOx,PIN) \
	ClearBit(GPIOx->ODR,PIN);
	//GPIOx->ODR= (GPIOx->ODR) & (~(0b1U<<PIN));
#define GPIO_ResetPinWithBSRR(GPIOx,PIN) \
	SetBit_NoLastStatus(GPIOx->BSRR,(PIN)+16);
	//(GPIOx->BSRR) = (0b1U<<(PIN+16));
#define GPIO_ResetPin(GPIOx,PIN) \
	GPIO_ResetPinWithBRR(GPIOx,PIN);

#define GPIO_TogglePin(GPIOx,PIN) \
	ToggleBit(GPIOx->ODR,PIN);
	//(GPIOx->ODR) ^= ( 0b1UL<<PIN);

#define GPIO_WritePin(GPIOx,PIN,STATUS) \
	WriteBit(GPIOx->ODR,PIN,STATUS);
	//GPIOx->ODR= (GPIOx->ODR & ~(0b1UL << PIN)) | (((STATUS)&0b1UL) << PIN);
#define GPIO_Write2Pin(GPIOx,FROM,VALUE) \
	Write2Bit(GPIOx->ODR,FROM,VALUE);
	//GPIOx->ODR= ((GPIOx->ODR) & ~(0b11UL << FROM)) | ((VALUE&0b11UL) << FROM);
#define GPIO_Write3Pin(GPIOx,FROM,VALUE) \
	Write3Bit(GPIOx->ODR,FROM,VALUE);
	//GPIOx->ODR= ((GPIOx->ODR) & ~(0b111UL << FROM)) | ((VALUE&0b111UL) << FROM);
#define GPIO_Write4Pin(GPIOx,FROM,VALUE) \
	Write4Bit(GPIOx->ODR,FROM,VALUE);
	//GPIOx->ODR= ((GPIOx->ODR) & ~(0b1111UL << FROM)) | ((VALUE&0b1111UL) << FROM);
#define GPIO_WritePort(GPIOx,VALUE) \
	GPIOx->ODR= VALUE;

//#define GetPinFromOutput(GPIOx,PIN) \
	//(((GPIOx->ODR) >> PIN) & 0b1UL)


#ifdef __cplusplus
}
#endif

#endif
