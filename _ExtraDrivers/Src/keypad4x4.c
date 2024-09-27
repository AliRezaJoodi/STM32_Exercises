// GitHub Account: GitHub.com/AliRezaJoodi

#include <keypad4x4.h>

const uint8_t keypad_data[16]={N00,N01,N02,N03,N04,N05,N06,N07,N08,N09,N10,N11,N12,N13,N14,N15};

//********************************************************
uint8_t _Keypad4x4_GetInitialNumber(void){
	uint8_t numer;
	
	GPIO_ConfigPinForPullUpInputMode(R1_GPIO,R1_PIN);
	GPIO_ConfigPinForPullUpInputMode(R2_GPIO,R2_PIN);
	GPIO_ConfigPinForPullUpInputMode(R3_GPIO,R3_PIN);
	GPIO_ConfigPinForPullUpInputMode(R4_GPIO,R4_PIN);
	GPIO_ConfigPinForPushPullOutputMode(C1_GPIO, C1_PIN); GPIO_ResetPin(C1_GPIO,C1_PIN);
	GPIO_ConfigPinForPushPullOutputMode(C2_GPIO, C2_PIN);	GPIO_ResetPin(C2_GPIO,C2_PIN);
	GPIO_ConfigPinForPushPullOutputMode(C3_GPIO, C3_PIN);	GPIO_ResetPin(C3_GPIO,C3_PIN);
	GPIO_ConfigPinForPushPullOutputMode(C4_GPIO, C4_PIN);	GPIO_ResetPin(C4_GPIO,C4_PIN);
	Delay_ms(1);
	WriteBit(numer, 0, GPIO_GetPin(R1_GPIO,R1_PIN));
	WriteBit(numer, 1, GPIO_GetPin(R2_GPIO,R2_PIN));
	WriteBit(numer, 2, GPIO_GetPin(R3_GPIO,R3_PIN));
	WriteBit(numer, 3, GPIO_GetPin(R4_GPIO,R4_PIN));	
	
	GPIO_ConfigPinForPushPullOutputMode(R1_GPIO, R1_PIN); GPIO_ResetPin(R1_GPIO,R1_PIN);
	GPIO_ConfigPinForPushPullOutputMode(R2_GPIO, R2_PIN); GPIO_ResetPin(R2_GPIO,R2_PIN);
	GPIO_ConfigPinForPushPullOutputMode(R3_GPIO, R3_PIN); GPIO_ResetPin(R3_GPIO,R3_PIN);
	GPIO_ConfigPinForPushPullOutputMode(R4_GPIO, R4_PIN); GPIO_ResetPin(R4_GPIO,R4_PIN);
	GPIO_ConfigPinForPullUpInputMode(C1_GPIO,C1_PIN);
	GPIO_ConfigPinForPullUpInputMode(C2_GPIO,C2_PIN);
	GPIO_ConfigPinForPullUpInputMode(C3_GPIO,C3_PIN);
	GPIO_ConfigPinForPullUpInputMode(C4_GPIO,C4_PIN);
	Delay_ms(1);
	WriteBit(numer, 4, GPIO_GetPin(C1_GPIO,C1_PIN));
	WriteBit(numer, 5, GPIO_GetPin(C2_GPIO,C2_PIN));
	WriteBit(numer, 6, GPIO_GetPin(C3_GPIO,C3_PIN));
	WriteBit(numer, 7, GPIO_GetPin(C4_GPIO,C4_PIN));
	
	return numer;
}

//********************************************************
uint8_t _Keypad4x4_ConvertNumber(uint8_t numer){ 
    unsigned char i=0;
     
    if(numer!=0xff){ 
        for(i=0; i<16; ++i){    
  	        if(numer==keypad_data[i]){return i;}   
  	    }
    }  
    
    return 16; 
}

//********************************************************
uint8_t Keypad4x4_GetNumber(void){
    unsigned char numer_initial=0;
    unsigned char key=0;
    
    numer_initial=_Keypad4x4_GetInitialNumber(); 
    key=_Keypad4x4_ConvertNumber(numer_initial);
    
    return key;
}
