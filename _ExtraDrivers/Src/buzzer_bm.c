// GitHub Account: GitHub.com/AliRezaJoodi

#include <buzzer_bm.h>

//********************************************************
void Buzzer_Config(void){
	BUS_GPIOx_EnableOrDisableWithAutoSearch(BUZZER_GPIO);
	GPIO_OutputWithPushPullMode_ConfigPin(BUZZER_GPIO,BUZZER_PIN);
	GPIO_WritePin(BUZZER_GPIO,BUZZER_PIN,!BUZZER_ACTIVE);
}

//*******************************************************
void _MakeBeep_UpOrDownSound(void){
    GPIO_WritePin(BUZZER_GPIO,BUZZER_PIN,BUZZER_ACTIVE);
    SysTick_Delay_1ms(80);
    GPIO_WritePin(BUZZER_GPIO,BUZZER_PIN,!BUZZER_ACTIVE);
}

//*******************************************************
void _MakeBeep_SetSound(void){
    GPIO_WritePin(BUZZER_GPIO,BUZZER_PIN,BUZZER_ACTIVE);
    SysTick_Delay_1ms(220);
    GPIO_WritePin(BUZZER_GPIO,BUZZER_PIN,!BUZZER_ACTIVE);
}

//*******************************************************
void _MakeBeep_ErrorSound(void){
    GPIO_WritePin(BUZZER_GPIO,BUZZER_PIN,BUZZER_ACTIVE);
    SysTick_Delay_1ms(500);
    GPIO_WritePin(BUZZER_GPIO,BUZZER_PIN,!BUZZER_ACTIVE);
}

//*******************************************************
void Buzzer_MakeBeep(char mode){    
    switch(mode){  
        case BEEP_UP:
            _MakeBeep_UpOrDownSound();
            break;
        case BEEP_DOWN:
            _MakeBeep_UpOrDownSound();
            break;
        case BEEP_SET: 
            _MakeBeep_SetSound();
            break;
        case BEEP_ERROR: 
            _MakeBeep_ErrorSound();
            break;
    }
}