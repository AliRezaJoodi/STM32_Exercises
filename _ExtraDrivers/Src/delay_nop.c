
#include <delay_nop.h>

//********************************
void DelayNop_us(unsigned int us){
  unsigned int i;
	
  for(i=0; i<us; ++i){
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
  }
}

//********************************
void DelayNop_ms(unsigned int ms){
  unsigned int i,i2;
	
  for (i=0; i<ms; ++i){
		DelayNop_us(1000);
	}
}

//********************************************
char Refresh(void){
	static unsigned int i=0;
	
	++i;
	if(i>DELAY_NOP_LAG){
		i=0;
		return 1;
	}
	return 0;
}