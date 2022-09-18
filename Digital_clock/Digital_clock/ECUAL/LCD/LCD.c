/*
 * LCD.c
 *
 * Created: 8/12/2022 3:45:54 PM
 *  Author: omart
 */ 

#include "LCD.h"


/*****************************************************************************
* Function Name: LCD_init
* Purpose      : Initialize LCD in 4-bit mode, clear LCD and turn off cursor
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void LCD_init(void){
	/*
	* Setting D2 to D7 --> D2 ----> RS
	*					   D3 ----> EN
	*					   D4-D7 -> Data
	*/
	DIO_init_pin(PORTD_t, PIN0_t, OUTPUT);
	DIO_init_pin(PORTD_t, PIN1_t, OUTPUT);
	DIO_init_pin(PORTD_t, PIN3_t, OUTPUT);
	DIO_init_pin(PORTD_t, PIN4_t, OUTPUT);
	DIO_init_pin(PORTD_t, PIN5_t, OUTPUT);
	DIO_init_pin(PORTD_t, PIN6_t, OUTPUT);
	
	LCD_write_command(0x3);
	delay_ms(4);
	LCD_write_command(0x3);
	delay_ms(4);
	LCD_write_command(0x3);
	delay_ms(4);
	
	LCD_write_command(0x2);
	LCD_write_command(0x28);
	LCD_write_command(0x08);
	LCD_write_command(0x01);
	LCD_write_command(0x06);
	LCD_write_command(0x0C);
	delay_ms(20);
}


/*****************************************************************************
* Function Name: LCD_write_command
* Purpose      : Write command on data bits
* Parameters   : Command
* Return value : Void
*****************************************************************************/
void LCD_write_command(uint8_t command){
	
	RS(0);
	D7(READBIT(command,7));
	D6(READBIT(command,6));
	D5(READBIT(command,5));
	D4(READBIT(command,4));
	EN(1);
	delay_ms(1);
	EN(0);
	delay_ms(1);
	
	D7(READBIT(command,3));
	D6(READBIT(command,2));
	D5(READBIT(command,1));
	D4(READBIT(command,0));
	EN(1);
	delay_ms(1);
	EN(0);
	delay_ms(1);
}


/*****************************************************************************
* Function Name: LCD_write_data
* Purpose      : Write data on data bits
* Parameters   : Data
* Return value : Void
*****************************************************************************/
void LCD_write_data(uint8_t data){
	
	RS(1);
	D7(READBIT(data,7));
	D6(READBIT(data,6));
	D5(READBIT(data,5));
	D4(READBIT(data,4));
	EN(1);
	delay_ms(1);
	EN(0);
	delay_ms(1);
	
	D7(READBIT(data,3));
	D6(READBIT(data,2));
	D5(READBIT(data,1));
	D4(READBIT(data,0));
	EN(1);
	delay_ms(1);
	EN(0);
	delay_ms(1);
	
}


/*****************************************************************************
* Function Name: LCD_write_string
* Purpose      : Write string on data bits
* Parameters   : Pointer to string
* Return value : Void
*****************************************************************************/
void LCD_write_string(uint8_t *data){
	uint8_t i = 0;
	while(data[i] != '\0')
	{
		LCD_write_data(data[i]);
		i++;
	}
}


void LCD_write_number(sint32_t num){
	uint8_t num_arr[10];
	sint8_t i = 0;
	
	if (num < 0)
	{
		LCD_write_data('-');
		num = num * -1;
	}
	
	if (num == 0)
	{
		LCD_write_data('0');
		return;
	}
	
	// Splitting digits
	for (i = 0; num != 0; i++)
	{
		// Adding 48 to write the ASCII value of the number
		// Because LCD only write ASCII
		num_arr[i] = (num % 10) + 48;
		num /= 10;
	}
	i--;
	
	while(i >= 0)
	{
		LCD_write_data(num_arr[i]);
		i--;
	}
	
}