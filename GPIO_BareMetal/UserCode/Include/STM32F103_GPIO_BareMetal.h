// GitHub Account: GitHub.com/AliRezaJoodi

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
#define GPIO_ConfigurePinDirection(GPIOx,BIT,MODE) \
	if(BIT<=7){(GPIOx->CRL)= ((GPIOx->CRL) & ~(0b11UL<<(BIT*4))) | ((MODE&0b11UL)<<(BIT*4));}\
		else{(GPIOx->CRH)= ((GPIOx->CRH) & ~(0b11UL<<((BIT-8)*4))) | ((MODE&0b11UL)<<((BIT-8)*4));}

// Input Mode Configuration
#define ANALOG_MODE               	0b00UL
#define FLOATING_INPUT							0b01UL
#define INPUT_WITH_PULLUP_PULLDOWN	0b10UL
#define GPIO_ConfigureInputMode(GPIOx,BIT,MODE) \
		if(BIT<=7){(GPIOx->CRL)= ((GPIOx->CRL) & ~(0b11UL<<((BIT*4)+2))) | ((MODE&0b11UL)<<((BIT*4)+2));}\
			else{(GPIOx->CRH)= ((GPIOx->CRH) & ~(0b11UL<<(((BIT-8)*4)+2))) | ((MODE&0b11UL)<<(((BIT-8)*4)+2));}

//Pull-up or Pull-down Configuration
#define PULLDOWN	0
#define PULLUP		1
#define GPIO_ConfigurePullUpOrPullDown(GPIOx,BIT,MODE) \
	(GPIOx->ODR) |= ((MODE&0b1UL) << BIT);	

// Output Mode Configuration
#define GENERAL_PURPOSE_OUTPUT_PUSHPULL  		0b00UL
#define GENERAL_PURPOSE_OUTPUT_OPENDRAIN 		0b01UL
#define ALTERNATE_FUNCTION_OUTPUT_PUSHPULL	0b10UL
#define ALTERNATE_FUNCTION_OUTPUT_OPENDRAIN	0b11UL
#define GPIO_ConfigureOutputMode(GPIOx,BIT,MODE) \
	(GPIOx->CRL)= ((GPIOx->CRL) & ~(0b11UL<<((BIT*4)+2))) | ((MODE&0b11UL)<<((BIT*4)+2));

// Other Commands																												
#define GPIO_GetInputPin(GPIOx,BIT) 									(((GPIOx->IDR) & (0b1UL<<BIT)) >> BIT)
#define GPIO_GetInputPort(GPIOx)											(GPIOx->IDR)
																												
#define GPIO_SetOutputPinWithBSRR(GPIOx,BIT) 					(GPIOx->BSRR) = (0b1UL<<BIT);	//Fast
#define GPIO_SetOutputPinWithODR(GPIOx,BIT) 					(GPIOx->ODR) |= (0b1UL<<BIT);
#define GPIO_SetOutputPin(GPIOx,BIT) 									GPIO_SetOutputPinWithBSRR(GPIOx,BIT)
#define GPIO_ResetOutputPinWithBRR(GPIOx,BIT) 				(GPIOx->BRR) = (0b1UL<<BIT);	//Fast
#define GPIO_ResetOutputPinWithODR(GPIOx,BIT) 				(GPIOx->ODR) &= ~(0b1U<<BIT);
#define GPIO_ResetOutputPinWithBSRR(GPIOx,BIT) 				(GPIOx->BSRR) = (0b1U<<(BIT+16));
#define GPIO_ResetOutputPin(GPIOx,BIT)								GPIO_ResetOutputPinWithBRR(GPIOx,BIT)
#define GPIO_ToggleOutputPin(GPIOx,BIT)								(GPIOx->ODR) ^= ( 0b1UL<<BIT);
#define GPIO_WriteOutputPin(GPIOx,BIT,STATUS)					(GPIOx->ODR) |= ((STATUS&0b1UL) << BIT);
#define GPIO_WriteOutputPort(GPIOx,VALUE)							(GPIOx->ODR) = VALUE;
#define GPIO_GetOutputPin(GPIOx,BIT) 									(((GPIOx->ODR) & (0b1UL<<BIT)) >> BIT)	


#endif

