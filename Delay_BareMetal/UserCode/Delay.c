
#include "Delay.h"

//********************************
void Delay_us(unsigned int us){
  volatile unsigned int i;
  volatile unsigned int t;

  for(i=0; i<us; ++i){
    t=_DELAY_LAG; 
		while(t!=0){--t;}
  }
}

//********************************
void Delay_ms(unsigned int ms){
  volatile unsigned int i;
	
  for (i=0; i<ms; i++){
    Delay_us(1000);
  }
}