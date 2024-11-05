
#ifndef _MAIN_INCLUDED
#define _MAIN_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f1xx.h>

//*****************************************
#ifndef TIMEOUT_VALUE
	#define TIMEOUT_VALUE		1000000
#endif

//*****************************************
#ifndef SYSTICK_HCLK_VALUE
	#define SYSTICK_HCLK_VALUE		8000000
#endif

//*****************************************
#ifndef DELAY_NOP_LAG
	#define DELAY_NOP_LAG		250000
#endif

//*****************************************
#ifndef KEYPAD4X4_HARDWARE
#define KEYPAD4X4_HARDWARE 
	#define R1_GPIO			GPIOA
  #define R1_PIN			0
	#define R2_GPIO			GPIOA
  #define R2_PIN			1
	#define R3_GPIO			GPIOA
  #define R3_PIN			2
	#define R4_GPIO			GPIOA
  #define R4_PIN			3
	#define C1_GPIO			GPIOA
  #define C1_PIN			4
	#define C2_GPIO			GPIOA
  #define C2_PIN			5
	#define C3_GPIO			GPIOA
  #define C3_PIN			6
	#define C4_GPIO			GPIOA
  #define C4_PIN			7
	
	#define N00					215
  #define N01					235
	#define N02					219
  #define N03					187
  #define N04					237
  #define N05					221
  #define N06					189
  #define N07					238
  #define N08					222
  #define N09					190
  #define N10					126
  #define N11					125
  #define N12					123
  #define N13					119
  #define N14					183
  #define N15					231
#endif


#ifdef __cplusplus
}
#endif

#endif		//_MAIN_INCLUDED
