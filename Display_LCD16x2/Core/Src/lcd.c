
#include "lcd.h"

//********************************
void Cmd4bit(uint8_t cmd){
	/* Set output port */
	if((cmd & 0x08))
	HAL_GPIO_WritePin(DATA_PORT, D7_PIN,GPIO_PIN_SET);
	else
	HAL_GPIO_WritePin(DATA_PORT, D7_PIN,GPIO_PIN_RESET);

	if((cmd & 0x04))
	HAL_GPIO_WritePin(DATA_PORT, D6_PIN,GPIO_PIN_SET);
	else
	HAL_GPIO_WritePin(DATA_PORT, D6_PIN,GPIO_PIN_RESET);
	
	if((cmd & 0x02))
	HAL_GPIO_WritePin(DATA_PORT, D5_PIN,GPIO_PIN_SET);
	else
	HAL_GPIO_WritePin(DATA_PORT, D5_PIN,GPIO_PIN_RESET);
	
	if((cmd & 0x01))
	HAL_GPIO_WritePin(DATA_PORT, D4_PIN,GPIO_PIN_SET);
	else
	HAL_GPIO_WritePin(DATA_PORT, D4_PIN,GPIO_PIN_RESET);
}

//********************************
void send_command(unsigned char data){
  HAL_Delay(2);
  HAL_GPIO_WritePin(CTRL_PORT,(1<<RS_PIN),GPIO_PIN_RESET);
  HAL_GPIO_WritePin(CTRL_PORT,(1<<RW_PIN),GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT, (0x0f<<D0_PIN_Start), GPIO_PIN_RESET);

	/* High nibble */
	
	Cmd4bit(data >> 4);
	HAL_GPIO_WritePin(CTRL_PORT,(1<<EN_PIN),GPIO_PIN_SET);
	HAL_Delay(2);
  HAL_GPIO_WritePin(CTRL_PORT,(1<<EN_PIN),GPIO_PIN_RESET);
	HAL_Delay(2);
	/* Low nibble */
	Cmd4bit(data & 0x0F);	
  HAL_GPIO_WritePin(CTRL_PORT,(1<<EN_PIN),GPIO_PIN_SET);
	HAL_Delay(2);
  HAL_GPIO_WritePin(CTRL_PORT,(1<<EN_PIN),GPIO_PIN_RESET);
	HAL_Delay(2);
}

//********************************
void lcd_putchar(unsigned char data){
  HAL_Delay(1);
  HAL_GPIO_WritePin(CTRL_PORT,(1<<RS_PIN),GPIO_PIN_SET);
  HAL_GPIO_WritePin(CTRL_PORT,(1<<RW_PIN),GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT, (0x0f<<D0_PIN_Start), GPIO_PIN_RESET);
  
  /* High nibble */
	Cmd4bit(data >> 4);
	HAL_GPIO_WritePin(CTRL_PORT,(1<<EN_PIN),GPIO_PIN_SET);
	HAL_Delay(2);
  HAL_GPIO_WritePin(CTRL_PORT,(1<<EN_PIN),GPIO_PIN_RESET);
	HAL_Delay(2);
	/* Low nibble */
	Cmd4bit(data & 0x0F);
	
	HAL_GPIO_WritePin(CTRL_PORT,(1<<EN_PIN),GPIO_PIN_SET);
  HAL_GPIO_WritePin(CTRL_PORT,(1<<EN_PIN),GPIO_PIN_RESET);
}

//********************************
void lcd_init(void){
  HAL_Delay(2);
	
	send_command(0x02);		/* send for 4 bit initialization of LCD  */
	send_command(0x28);   /* 2 line, 5*7 matrix in 4-bit mode */
	send_command(0x0c);   /* Display on cursor off*/
	send_command(0x06);   /* Increment cursor (shift cursor to right)*/
	send_command(0x01);   /* Clear display screen*/
	
}

//********************************
void lcd_puts(char *str){
  HAL_Delay(1);
  while(*str != 0){
    lcd_putchar(*str);
    str++;
  }
}

//********************************
void lcd_gotoxy(unsigned char x, unsigned char y){
  HAL_Delay(1);
 
  switch(y){
    case 0:
      send_command(0x80+x);
    break;
    case 1:
      send_command(0xC0+x);
      break;
    case 2:
      send_command(0x94+x);
      break;
    case 3:
      send_command(0xD4+x);
  }
}

//********************************
void lcd_clear(void){
  HAL_Delay(1);
  send_command(0x01); // clear
  send_command(0x02);	// cursor home
}





