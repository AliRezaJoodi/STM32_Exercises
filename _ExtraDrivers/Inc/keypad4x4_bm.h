// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include <utility.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <delay.h>

#ifdef HARDWARE_LOCAL
	#include "_hardware.h"
#endif

#ifndef _KEYPAD4X4_INCLUDED
#define _KEYPAD4X4_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

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

void Keypad4x4_Config(void);
uint8_t _Keypad4x4_GetInitialNumber(void);
uint8_t _Keypad4x4_ConvertNumber(uint8_t key);
uint8_t Keypad4x4_GetNumber(void);

#ifdef __cplusplus
}
#endif

#endif		// _KEYPAD4X4_INCLUDED