// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

#include <stm32f1xx.h>
#include <utility.h>

#ifndef _STM32F1xx_BM_GPIO_INCLUDED
#define _STM32F1xx_BM_GPIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


/*
#define FULL_SWJ												0b000		//SWD(on),	JTAG(on), 	NJTRST(on)
#define FULL_SWJ_WITHOUT_NJTRST					0b001		//SWD(on), 	JTAG(on), 	NJTRST(off)
#define JTAG_DISABLED_AND_SWD_ENABLED		0b010		//SWD(on), 	JTAG(off), 	NJTRST(off)	
#define JTAG_DISABLED_AND_SWD_DISABLED	0b100		//SWD(off), JTAG(off), 	NJTRST(off)
*/
#define SWD_ON__JTAG_ON__NJTRST_ON				0b000		//Reset State
#define SWD_ON__JTAG_ON__NJTRST_OFF				0b001
#define SWD_ON__JTAG_OFF									0b010
#define SWD_OFF__JTAG_OFF									0b100
#define GPIO_SWJ_SetDebugInterfaces(MODE) \
	Write3Bit(AFIO->MAPR, AFIO_MAPR_SWJ_CFG_Pos, MODE);

#define IO_INPUT          0b00
#define IO_OUTPUT_10MHz   0b01
#define IO_OUTPUT_2MHz    0b10
#define IO_OUTPUT_50MHz		0b11
#define IO_OUTPUT   			IO_OUTPUT_2MHz
#define GPIO_SetInputOrOutputMode(GPIOx, PIN, MODE) \
	if(PIN<=7){Write2Bit(GPIOx->CRL, PIN*4, MODE);}\
		else{Write2Bit(GPIOx->CRH, (PIN-8)*4, MODE);}
/*
#define GPIO_ConfigureInputMode(GPIOx,PIN) \
	GPIO_SetInputOrOutputMode(GPIOx,PIN,MODE_INPUT);
#define GPIO_ConfigureOutputMode(GPIOx,PIN) \
	GPIO_SetInputOrOutputMode(GPIOx,PIN,MODE_OUTPUT);
#define GPIO_ConfigureOutputMode_2MHz(GPIOx,PIN) \
	GPIO_SetInputOrOutputMode(GPIOx,PIN,MODE_OUTPUT_2MHz);
#define GPIO_ConfigureOutputMode_10MHz(GPIOx,PIN) \
	GPIO_SetInputOrOutputMode(GPIOx,PIN,MODE_OUTPUT_10MHz);
#define GPIO_ConfigureOutputMode_50MHz(GPIOx,PIN) \
	GPIO_SetInputOrOutputMode(GPIOx,PIN,MODE_OUTPUT_50MHz);
*/

#define INPUT_ANALOG		0b00
#define INPUT_FLOATING	0b01
#define INPUT_PULLDOWN	0b10 | 0b000
#define INPUT_PULLUP		0b10 | 0b100
#define GPIO_InputMode_SetInputType(GPIOx, PIN, MODE) \
	if(PIN<=7){Write2Bit(GPIOx->CRL, (PIN*4)+2, MODE);}\
		else{Write2Bit(GPIOx->CRH, ((PIN-8)*4)+2, MODE);}\
	WriteBit(GPIOx->ODR, PIN, GetBit(MODE,2));
/*		
#define GPIO_ConfigureFeatureOfInputPin(GPIOx,PIN,MODE) \
	if(PIN<=7){Write2Bit(GPIOx->CRL,(PIN*4)+2,MODE);}\
		else{Write2Bit(GPIOx->CRH,((PIN-8)*4)+2,MODE);}
#define GPIO_InputMode_ConfigureAnalogMode(GPIOx,PIN) \
	GPIO_ConfigureFeatureOfInputPin(GPIOx,PIN,ANALOG_MODE);
#define GPIO_InputMode_ConfigureFloatingInput(GPIOx,PIN) \
	GPIO_ConfigureFeatureOfInputPin(GPIOx,PIN,FLOATING_INPUT);
#define GPIO_InputMode_ConfigurePullUpInput(GPIOx,PIN) \
	if(PIN<=7){Write2Bit(GPIOx->CRL,(PIN*4)+2,INPUT_WITH_PULLUP_PULLDOWN);}\
		else{Write2Bit(GPIOx->CRH,((PIN-8)*4)+2,INPUT_WITH_PULLUP_PULLDOWN);}\
	WriteBit(GPIOx->ODR,PIN,PULLUP);
#define GPIO_InputMode_ConfigurePullDownInput(GPIOx,PIN) \
	if(PIN<=7){Write2Bit(GPIOx->CRL,(PIN*4)+2,INPUT_WITH_PULLUP_PULLDOWN);}\
		else{Write2Bit(GPIOx->CRH,((PIN-8)*4)+2,INPUT_WITH_PULLUP_PULLDOWN);}\
	WriteBit(GPIOx->ODR,PIN,PULLDOWN);	
*/
#define GPIO_InputMode_PullUpPullDown_SetPullUpOrPullDown(GPIOx,PIN,MODE) \
	WriteBit(GPIOx->ODR,PIN,MODE);

#define GENERAL_PURPOSE_OUTPUT_PUSHPULL  		0b00
#define GENERAL_PURPOSE_OUTPUT_OPENDRAIN 		0b01
#define ALTERNATE_FUNCTION_OUTPUT_PUSHPULL	0b10
#define ALTERNATE_FUNCTION_OUTPUT_OPENDRAIN	0b11
#define GPIO_OutputMode_SetFeatures(GPIOx,PIN,MODE) \
	if(PIN<=7){Write2Bit(GPIOx->CRL, (PIN*4)+2, MODE);}\
		else{Write2Bit(GPIOx->CRH, ((PIN-8)*4)+2, MODE);}

#define OUTPUT_GP		0b0		// General Purpose
#define OUTPUT_AF		0b1		// Alternate Function
#define GPIO_OutputMode_SetGeneralPurposeOrAlternateFunction(GPIOx,PIN, MODE) \
	if(PIN<=7){WriteBit(GPIOx->CRL, (PIN*4)+3, MODE);}\
		else{WriteBit(GPIOx->CRH, ((PIN-8)*4)+3, MODE);}
/*
#define _GENERAL_PURPOSE_OUTPUT 		0b0
#define _ALTERNATE_FUNCTION_OUTPUT	0b1
#define GPIO_OutputMode_ConfigureGPIO(GPIOx,PIN) \
	if(PIN<=7){WriteBit(GPIOx->CRL,(PIN*4)+3,_GENERAL_PURPOSE_OUTPUT);}\
		else{WriteBit(GPIOx->CRH,((PIN-8)*4)+3,_GENERAL_PURPOSE_OUTPUT);}
#define GPIO_OutputMode_ConfigureAFIO(GPIOx,PIN) \
	if(PIN<=7){WriteBit(GPIOx->CRL,(PIN*4)+3,_ALTERNATE_FUNCTION_OUTPUT);}\
		else{WriteBit(GPIOx->CRH,((PIN-8)*4)+3,_ALTERNATE_FUNCTION_OUTPUT);}
*/

#define OUTPUT_PUSHPULL		0b0
#define OUTPUT_OPENDRAIN	0b1
#define GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOx, PIN, MODE) \
	if(PIN<=7){WriteBit(GPIOx->CRL, (PIN*4)+2, MODE);}\
		else{WriteBit(GPIOx->CRH, ((PIN-8)*4)+2, MODE);}
/*
#define _PUSHPULL		0b0
#define _OPENDRAIN	0b1
#define GPIO_OutputMode_ConfigurePushPull(GPIOx,PIN) \
	if(PIN<=7){WriteBit(GPIOx->CRL,(PIN*4)+2,_PUSHPULL);}\
		else{WriteBit(GPIOx->CRH,((PIN-8)*4)+2,_PUSHPULL);}
#define GPIO_OutputMode_ConfigureOpenDrain(GPIOx,PIN) \
	if(PIN<=7){WriteBit(GPIOx->CRL,(PIN*4)+2,_OPENDRAIN);}\
		else{WriteBit(GPIOx->CRH,((PIN-8)*4)+2,_OPENDRAIN);}
*/
		
#define GPIO_GetPin(GPIOx, PIN) \
	GetBit(GPIOx->IDR, PIN)
#define GPIO_Get2Pin(GPIOx, FROM) \
	Get2Bit(GPIOx->IDR, FROM)
#define GPIO_Get3Pin(GPIOx, FROM) \
	Get3Bit(GPIOx->IDR, FROM)
#define GPIO_Get4Pin(GPIOx, FROM) \
	Get4Bit(GPIOx->IDR, FROM)
#define GPIO_GetPort(GPIOx) \
	(GPIOx->IDR)

#define GetOutputValueFromPin(GPIOx, PIN) \
	GetBit(GPIOx->ODR,PIN)
	
#define GPIO_SetPinWithBSRR(GPIOx, PIN) \
	SetBit_NoLastStatus(GPIOx->BSRR, PIN); //Fast
#define GPIO_SetPinWithODR(GPIOx, PIN) \
	SetBit(GPIOx->ODR, PIN);
#define GPIO_SetPin(GPIOx, PIN) \
	GPIO_SetPinWithBSRR(GPIOx, PIN);

#define GPIO_ResetPinWithBRR(GPIOx, PIN) \
	SetBit_NoLastStatus(GPIOx->BRR, PIN); //Fast
#define GPIO_ResetPinWithODR(GPIOx, PIN) \
	ClearBit(GPIOx->ODR, PIN);
#define GPIO_ResetPinWithBSRR(GPIOx, PIN) \
	SetBit_NoLastStatus(GPIOx->BSRR,(PIN)+16);
#define GPIO_ResetPin(GPIOx, PIN) \
	GPIO_ResetPinWithBRR(GPIOx, PIN);

#define GPIO_TogglePin(GPIOx, PIN) \
	ToggleBit(GPIOx->ODR, PIN);

#define GPIO_WritePin(GPIOx, PIN, STATUS) \
	WriteBit(GPIOx->ODR, PIN, STATUS);
#define GPIO_Write2Pin(GPIOx, FROM, VALUE) \
	Write2Bit(GPIOx->ODR, FROM, VALUE);
#define GPIO_Write3Pin(GPIOx, FROM, VALUE) \
	Write3Bit(GPIOx->ODR, FROM, VALUE);
#define GPIO_Write4Pin(GPIOx, FROM, VALUE) \
	Write4Bit(GPIOx->ODR, FROM, VALUE);
#define GPIO_WritePort(GPIOx, VALUE) \
	GPIOx->ODR = VALUE;

// Check Again LockBit
#define GPIO_ActiveLockRegister(GPIOx) \
	SetBit(GPIOx->LCKR,16);
#define GPIO_DeActivateLockRegister(GPIOx) \
	ClearBit(GPIOx->LCKR, 16);
#define GPIO_GetFromLCKK(GPIOx) \
	GetBit(GPIOx->LCKR, 16)
	
#define GPIO_LockPin(GPIOx, PIN) \
	SetBit(GPIOx->LCKR, PIN);
#define GPIO_UnLockPin(GPIOx, PIN) \
	ClearBit(GPIOx->LCKR, PIN);
#define GPIO_GetLockStatusFromPin(GPIOx, PIN) \
	GetBit(GPIOx->LCKR, PIN)		//	Use when LCKK bit is 1
#define GPIO_WaitTillLockPin(GPIOx, PIN) \
	while(!GPIO_GetLockStatusFromPin(GPIOx, PIN)){}
#define GPIO_WaitTillUnLockPin(GPIOx, PIN) \
	while(GPIO_GetLockStatusFromPin(GPIOx, PIN)){}
		
#ifdef __cplusplus
}
#endif

#endif	// _STM32F1xx_BM_GPIO_INCLUDED

