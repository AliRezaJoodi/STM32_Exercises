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
#define ConfigurePinForDirection(GPIOx,PIN,MODE) \
	if(PIN<=7){(GPIOx->CRL)= ((GPIOx->CRL) & ~(0b11UL<<(PIN*4))) | ((MODE&0b11UL)<<(PIN*4));}\
		else{(GPIOx->CRH)= ((GPIOx->CRH) & ~(0b11UL<<((PIN-8)*4))) | ((MODE&0b11UL)<<((PIN-8)*4));}

// Input Mode Configuration
#define ANALOG_MODE               	0b00UL
#define FLOATING_INPUT							0b01UL
#define INPUT_WITH_PULLUP_PULLDOWN	0b10UL
#define ConfigurePinForInputMode(GPIOx,PIN,MODE) \
		if(PIN<=7){(GPIOx->CRL)= ((GPIOx->CRL) & ~(0b11UL<<((PIN*4)+2))) | ((MODE&0b11UL)<<((PIN*4)+2));}\
			else{(GPIOx->CRH)= ((GPIOx->CRH) & ~(0b11UL<<(((PIN-8)*4)+2))) | ((MODE&0b11UL)<<(((PIN-8)*4)+2));}

//Pull-up or Pull-down Configuration
#define PULLDOWN	0
#define PULLUP		1
#define ConfigurePinForPullUpOrDown(GPIOx,PIN,MODE) \
	GPIOx->ODR= (GPIOx->ODR & ~(0b1UL << PIN)) | ((MODE&0b1UL) << PIN);

// Output Mode Configuration
#define GENERAL_PURPOSE_OUTPUT_PUSHPULL  		0b00UL
#define GENERAL_PURPOSE_OUTPUT_OPENDRAIN 		0b01UL
#define ALTERNATE_FUNCTION_OUTPUT_PUSHPULL	0b10UL
#define ALTERNATE_FUNCTION_OUTPUT_OPENDRAIN	0b11UL
#define ConfigurePinForOutputMode(GPIOx,PIN,MODE) \
	if(PIN<=7){(GPIOx->CRL)= ((GPIOx->CRL) & ~(0b11UL<<((PIN*4)+2))) | ((MODE&0b11UL)<<((PIN*4)+2));}\
		else{(GPIOx->CRH)= ((GPIOx->CRH) & ~(0b11UL<<(((PIN-8)*4)+2))) | ((MODE&0b11UL)<<(((PIN-8)*4)+2));}
																										
#define GetPinFromInput(GPIOx,PIN) \
	(((GPIOx->IDR) >> PIN) & 0b1UL)
#define Get2PinFromInput(GPIOx,FROM) \
	((GPIOx->IDR >> FROM) & 0b11UL)
#define Get3PinFromInput(GPIOx,FROM) \
	((GPIOx->IDR >> FROM) & 0b111UL)
#define Get4PinFromInput(GPIOx,FROM) \
	((GPIOx->IDR >> FROM) & 0b1111UL)
#define GetPortFromInput(GPIOx) \
	(GPIOx->IDR)
																												
#define SetPinFromOutputWithBSRR(GPIOx,PIN) \
	GPIOx->BSRR = 0b1UL<<PIN;	//Fast
#define SetPinFromOutputWithODR(GPIOx,PIN) \
	(GPIOx->ODR) |= (0b1UL<<PIN);
#define SetPinFromOutput(GPIOx,PIN) \
	SetPinFromOutputWithBSRR(GPIOx,PIN)

#define ResetPinFromOutputWithBRR(GPIOx,PIN) \
	(GPIOx->BRR) = (0b1UL<<PIN);	//Fast
#define ResetPinFromOutputWithODR(GPIOx,PIN) \
	(GPIOx->ODR) &= ~(0b1U<<PIN);
#define ResetPinFromOutputWithBSRR(GPIOx,PIN) \
	(GPIOx->BSRR) = (0b1U<<(PIN+16));
#define ResetPinFromOutput(GPIOx,PIN) \
	ResetPinFromOutputWithBRR(GPIOx,PIN)

#define TogglePinFromOutput(GPIOx,PIN) \
	(GPIOx->ODR) ^= ( 0b1UL<<PIN);

#define WritePinFromOutput(GPIOx,PIN,STATUS) \
	GPIOx->ODR= (GPIOx->ODR & ~(0b1UL << PIN)) | ((STATUS&0b1UL) << PIN);
#define Write2PinFromOutput(GPIOx,FROM,VALUE) \
	GPIOx->ODR= ((GPIOx->ODR) & ~(0b11UL << FROM)) | ((VALUE&0b11UL) << FROM);
#define Write3PinFromOutput(GPIOx,FROM,VALUE) \
	GPIOx->ODR= ((GPIOx->ODR) & ~(0b111UL << FROM)) | ((VALUE&0b111UL) << FROM);
#define Write4PinFromOutput(GPIOx,FROM,VALUE) \
	GPIOx->ODR= ((GPIOx->ODR) & ~(0b1111UL << FROM)) | ((VALUE&0b1111UL) << FROM);
#define WritePortFromOutput(GPIOx,VALUE) \
	(GPIOx->ODR) = VALUE;

#define GetPinFromOutput(GPIOx,PIN) \
	(((GPIOx->ODR) >> PIN) & 0b1UL)

#endif

