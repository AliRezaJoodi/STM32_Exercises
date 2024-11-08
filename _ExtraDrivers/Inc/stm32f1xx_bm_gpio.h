// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

/*
It's about:
	AFIO_MAPR:	AF remap and debug I/O configuration register
	GPIOx_CRL: 	Port configuration register low
	GPIOx_CRH:	Port configuration register high
	GPIOx_IDR:	Port input data register
	GPIOx_ODR: 	Port output data register
	GPIOx_BSRR:	Port bit set/reset register
	GPIOx_BRR:	Port bit reset register
	GPIOx_LCKR: Port configuration lock register
*/


#ifndef _STM32F1xx_BM_GPIO_INCLUDED
#define _STM32F1xx_BM_GPIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f1xx.h>	
#include <utility.h>


/*
AFIO_MAPR, Bits 26:24
SWJ_CFG[2:0]: Serial wire JTAG configuration
							These bits are write-only (when read, the value is undefined).
							They are used to configure the SWJ and trace alternate function I/Os.
							The SWJ (Serial Wire JTAG) supports JTAG or SWD access to the Cortex® debug port.
							The default state after reset is SWJ ON without trace.
							This allows JTAG or SW mode to be enabled by sending a specific sequence on the JTMS/JTCK pin.
							000: Full SWJ (JTAG-DP + SW-DP): Reset State
							001: Full SWJ (JTAG-DP + SW-DP) but without NJTRST
							010: JTAG-DP Disabled and SW-DP Enabled
							100: JTAG-DP Disabled and SW-DP Disabled
							
							Note: Other combinations: no effect
*/

#define SWJ_SWD_JTAG_NJTRST		0b000		// Full SWJ (JTAG-DP + SW-DP), Reset State
#define SWJ_SWD_JTAG					0b001		// Full SWJ (JTAG-DP + SW-DP) but without NJTRST
#define SWJ_SWD								0b010		// JTAG-DP Disabled and SW-DP Enabled
#define SWJ_DISABLED					0b100		// JTAG-DP Disabled and SW-DP Disabled

__STATIC_INLINE void GPIO_SWJ_SetDebugInterfaces(uint8_t mode){
	Write3Bit(AFIO->MAPR, AFIO_MAPR_SWJ_CFG_Pos, mode);
}


/*
GPIOx_CRL, Bits 29:28, 25:24, 21:20, 17:16, 13:12, 9:8, 5:4, 1:0
MODEy[1:0]: Port x mode bits (y= 0 .. 7)
						These bits are written by software to configure the corresponding I/O port.

GPIOx_CRH, Bits 29:28, 25:24, 21:20, 17:16, 13:12, 9:8, 5:4, 1:0
MODEy[1:0]: Port x mode bits (y= 8 .. 15)
						These bits are written by software to configure the corresponding I/O port.

						00: Input mode (reset state)
						01: Output mode, max speed 10 MHz.
						10: Output mode, max speed 2 MHz.
						11: Output mode, max speed 50 MHz.
*/

#define IO_INPUT          0b00
#define IO_OUTPUT_10MHz   0b01
#define IO_OUTPUT_2MHz    0b10
#define IO_OUTPUT_50MHz		0b11
#define IO_OUTPUT   			IO_OUTPUT_2MHz
__STATIC_INLINE void GPIO_SetInputOrOutputMode(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode){
	if(pin<=7){Write2Bit(GPIOx->CRL, pin*4, mode);}
		else{Write2Bit(GPIOx->CRH, (pin-8)*4, mode);}	
}


/*
GPIOx_CRL, Bits 31:30, 27:26, 23:22, 19:18, 15:14, 11:10, 7:6, 3:2
CNFy[1:0]: 	Port x configuration bits (y= 0 .. 7)
						These bits are written by software to configure the corresponding I/O port.

GPIOx_CRH, Bits 31:30, 27:26, 23:22, 19:18, 15:14, 11:10, 7:6, 3:2
CNFy[1:0]: 	Port x configuration bits (y= 8 .. 15)
						These bits are written by software to configure the corresponding I/O port.						
						
						In input mode (MODE[1:0]=00):
						00: Analog mode
						01: Floating input (reset state)
						10: Input with pull-up / pull-down
						11: Reserved
						
						In output mode (MODE[1:0] > 00):
						00: General purpose output push-pull
						01: General purpose output Open-drain
						10: Alternate function output Push-pull
						11: Alternate function output Open-drain
*/

#define INPUT_ANALOG		0b00
#define INPUT_FLOATING	0b01
#define INPUT_PULL			0b10
__STATIC_INLINE void GPIO_InInputMode_SetInputType(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode){
	if(pin<=7){Write2Bit(GPIOx->CRL, (pin*4)+2, mode);}
		else{Write2Bit(GPIOx->CRH, ((pin-8)*4)+2, mode);}	
}

#define OUTPUT_GP_PUSHPULL  	0b00		// General purpose output push-pull
#define OUTPUT_GP_OPENDRAIN 	0b01		// General purpose output Open-drain
#define OUTPUT_AF_PUSHPULL		0b10		// Alternate function output Push-pull
#define OUTPUT_AF_OPENDRAIN		0b11		// Alternate function output Open-drain
__STATIC_INLINE void GPIO_InOutputMode_SetOutputType(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode){
	if(pin<=7){
		Write2Bit(GPIOx->CRL, (pin*4)+2, mode);
	}
	else{
		Write2Bit(GPIOx->CRH, ((pin-8)*4)+2, mode);
	}
}

#define OUTPUT_GP		0b0		// General Purpose
#define OUTPUT_AF		0b1		// Alternate Function
__STATIC_INLINE void GPIO_InOutputMode_SetGeneralPurposeOrAlternateFunction(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode){
	if(pin<=7){
		WriteBit(GPIOx->CRL, (pin*4)+3, mode);
	}
	else{
		WriteBit(GPIOx->CRH, ((pin-8)*4)+3, mode);
	}	
}

#define OUTPUT_PUSHPULL		0b0		// Push-Pull
#define OUTPUT_OPENDRAIN	0b1		// Open-Drain
__STATIC_INLINE void GPIO_InOutputMode_SetPushPullOrOpenDrain(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode){
	if(pin<=7){
		WriteBit(GPIOx->CRL, (pin*4)+2, mode);
	}
	else{
		WriteBit(GPIOx->CRH, ((pin-8)*4)+2, mode);
	}
}


/*
GPIOx_ODR, Bits 15:0
ODRy: Port output data (y= 0 .. 15)
			These bits can be read and written by software and can be accessed in Word mode only.
			Note: For atomic bit set/reset, the ODR bits can be individually set and cleared by writing to the GPIOx_BSRR register (x = A .. G).
*/

#define PULL_PULLDOWN		0b0		// Input with pull-down
#define PULL_PULLUP			0b1		// Input with pull-up
__STATIC_INLINE void GPIO_InInputModeWithPull_SetPullUpOrPullDown(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode){
	WriteBit(GPIOx->ODR, pin, mode);
}

#define GetOutputValueFromPin(GPIOx, pin) \
	GetBit(GPIOx->ODR, pin)

__STATIC_INLINE void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint8_t pin){
	ToggleBit(GPIOx->ODR, pin);
}

__STATIC_INLINE void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t status){
		WriteBit(GPIOx->ODR, pin, status);
}

__STATIC_INLINE void GPIO_Write2Pin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t value){
		Write2Bit(GPIOx->ODR, pin, value);
}

__STATIC_INLINE void GPIO_Write3Pin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t value){
		Write3Bit(GPIOx->ODR, pin, value);
}

__STATIC_INLINE void GPIO_Write4Pin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t value){
		Write4Bit(GPIOx->ODR, pin, value);
}

__STATIC_INLINE void GPIO_WritePort(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t value){
		GPIOx->ODR = value;
}


/*
GPIOx_IDR, Bits 15:0
IDRy:	Port input data (y= 0 .. 15)
			These bits are read only and can be accessed in Word mode only.
			They contain the input value of the corresponding I/O port.
*/

__STATIC_INLINE uint8_t GPIO_GetPin(GPIO_TypeDef *GPIOx, uint8_t pin){
	return (GetBit(GPIOx->IDR, pin));
}

__STATIC_INLINE uint8_t GPIO_Get2Pin(GPIO_TypeDef *GPIOx, uint8_t pin){
	return (Get2Bit(GPIOx->IDR, pin));
}

__STATIC_INLINE uint8_t GPIO_Get3Pin(GPIO_TypeDef *GPIOx, uint8_t pin){
	return (Get3Bit(GPIOx->IDR, pin));
}

__STATIC_INLINE uint8_t GPIO_Get4Pin(GPIO_TypeDef *GPIOx, uint8_t pin){
	return (Get4Bit(GPIOx->IDR, pin));
}

__STATIC_INLINE uint16_t GPIO_GetPort(GPIO_TypeDef *GPIOx){
	return (uint16_t)((GPIOx->IDR) & 0xFFFF);
}


/*
GPIOx_BSRR, Bits 15:0
BSy: 	Port x Set bit y (y= 0 .. 15)
			These bits are write-only and can be accessed in Word mode only.
			0: No action on the corresponding ODRx bit
			1: Set the corresponding ODRx bit
*/

__STATIC_INLINE void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint8_t pin){
	SetBit_NoLastStatus(GPIOx->BSRR, pin);
}


/*
GPIOx_BRR, Bits 15:0
BRy: Port x Reset bit y (y= 0 .. 15)
			These bits are write-only and can be accessed in Word mode only.
			0: No action on the corresponding ODRx bit
			1: Reset the corresponding ODRx bit
*/

__STATIC_INLINE void GPIO_ResetPin(GPIO_TypeDef *GPIOx, uint8_t pin){
	SetBit_NoLastStatus(GPIOx->BRR, pin);
}

/*
GPIOx_LCKR, Bit 16
LCKK[16]: Lock key
					This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
					0: Port configuration lock key not active
					1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
					
					LOCK key writing sequence:
					Write 1
					Write 0
					Write 1
					Read 0
					Read 1 (this read is optional but confirms that the lock is active)
					
					Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
					Any error in the lock sequence will abort the lock.
*/

/*
GPIOx_LCKR, Bits 15:0
LCKy:	Port x Lock bit y (y= 0 .. 15)
			These bits are read write but can only be written when the LCKK bit is 0.
			0: Port configuration not locked.
			1: Port configuration locked.
*/

__STATIC_INLINE void GPIO_ActiveLockRegister(GPIO_TypeDef *GPIOx){
	SetBit(GPIOx->LCKR,16);
}

__STATIC_INLINE void GPIO_DeActivateLockRegister(GPIO_TypeDef *GPIOx){
	ClearBit(GPIOx->LCKR, 16);
}

__STATIC_INLINE uint32_t GPIO_GetFromLCKK(GPIO_TypeDef *GPIOx){
	return (GetBit(GPIOx->LCKR, 16));
}

__STATIC_INLINE void GPIO_LockPin(GPIO_TypeDef *GPIOx, uint8_t pin){
		SetBit(GPIOx->LCKR, pin);
}

__STATIC_INLINE void GPIO_UnLockPin(GPIO_TypeDef *GPIOx, uint8_t pin){
	ClearBit(GPIOx->LCKR, pin);
}

__STATIC_INLINE void GPIO_WaitTillLockPin(GPIO_TypeDef *GPIOx, uint8_t pin){
		while(!GetBit(GPIOx->LCKR, pin)){};
}

__STATIC_INLINE void GPIO_WaitTillUnLockPin(GPIO_TypeDef *GPIOx, uint8_t pin){
		while(GetBit(GPIOx->LCKR, pin)){};
}


void GPIO_ConfigPinForPushPullOutputMode(GPIO_TypeDef *GPIOx, uint8_t pin);
void GPIO_ConfigPinForOpenDrainOutputMode(GPIO_TypeDef *GPIOx, uint8_t pin);
void GPIO_ConfigPinForPullUpInputMode(GPIO_TypeDef *GPIOx, uint8_t pin);
void GPIO_ConfigPinForPullDownInputMode(GPIO_TypeDef *GPIOx, uint8_t pin);
void GPIO_ConfigPinForFloatingInputMode(GPIO_TypeDef *GPIOx, uint8_t pin);
		
#ifdef __cplusplus
}
#endif

#endif	// _STM32F1xx_BM_GPIO_INCLUDED

