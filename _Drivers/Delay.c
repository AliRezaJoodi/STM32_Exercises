// GitHub Account: GitHub.com/AliRezaJoodi

#include "Delay.h"

//********************************
void delay_us(unsigned int us){
  volatile unsigned int i;
  volatile unsigned int t;

  for(i=0; i<us; i++){
    t=_LAG; while(t!=0){t--;}
  }
}

//********************************
void delay_ms(unsigned int ms){
  volatile unsigned int i;
	
  for (i=0; i<ms; i++){
    delay_us(1000);
  }
}