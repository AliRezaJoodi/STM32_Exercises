// GitHub Account: GitHub.com/AliRezaJoodi
// Set for 8MHz

#ifndef _DELAY_NOP_INCLUDED
#define _DELAY_NOP_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif 

#include "main.h"

#ifndef DELAY_NOP_LAG
	#define DELAY_NOP_LAG		250000
#endif


void DelayNop_us(unsigned int us);
void DelayNop_ms(unsigned int ms);
char Refresh(void);


#ifdef __cplusplus
}
#endif 

#endif	// _DELAY_NOP_INCLUDED