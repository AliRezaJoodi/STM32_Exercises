// GitHub Account: GitHub.com/AliRezaJoodi
// Set for 8MHz

#include <stm32f1xx.h>

#ifndef _DELAY_INCLUDED
#define _DELAY_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif 


///#define _DELAY_LAG		5
#define _REFRESH_LAG	250000

void Delay_us(unsigned int us);
void Delay_ms(unsigned int ms);
char Refresh(void);


#ifdef __cplusplus
}
#endif 

#endif	// _DELAY_INCLUDED