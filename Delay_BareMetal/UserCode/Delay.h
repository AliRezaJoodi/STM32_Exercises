// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _DELAY_INCLUDED
    #define _DELAY_INCLUDED

#ifdef __cplusplus
	extern "C" {
#endif 


#define _DELAY_LAG		8
#define _REFRESH_LAG	40000

void Delay_us(unsigned int us);
void Delay_ms(unsigned int ms);
char Refresh(void);


#ifdef __cplusplus
	}
#endif 

#endif