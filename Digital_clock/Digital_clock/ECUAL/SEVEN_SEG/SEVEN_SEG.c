/*
 * SEVEN_SEG.c
 *
 * Created: 8/17/2022 5:52:59 PM
 *  Author: omart
 */ 

#include "SEVEN_SEG.h"


uint8_t seg_decoder[10] = {0b00000001, 0b01001111, 0b00010010, 0b00000110, 0b01001100, 0b00100100, 0b00100000, 0b00001111, 0b00000000, 0b00000100};
/*****************************************************************************
* Function Name: SEVEN_SEG_init
* Purpose      : Initialize seven segment
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void SEVEN_SEG_init(void){
	DIO_init_port(PORTC_t, OUTPUT);
	SEVEN_SEG_init_enables();
}


/*****************************************************************************
* Function Name: SEVEN_SEG_init_enables
* Purpose      : Initialize enable pins as output
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void SEVEN_SEG_init_enables(void){
	DIO_init_pin(PORTA_t, PIN0_t, OUTPUT);
	DIO_init_pin(PORTA_t, PIN1_t, OUTPUT);
	DIO_init_pin(PORTA_t, PIN2_t, OUTPUT);
	DIO_init_pin(PORTA_t, PIN3_t, OUTPUT);
	DIO_init_pin(PORTA_t, PIN4_t, OUTPUT);
	DIO_init_pin(PORTA_t, PIN5_t, OUTPUT);
}


/*****************************************************************************
* Function Name: SEVEN_SEG_write_digit
* Purpose      : Writes a digit on a seven segment
* Parameters   : Seven segment select and digit to be displayed
* Return value : Void
*****************************************************************************/
void SEVEN_SEG_write_digit(SEG_select_t select, uint8_t digit){
	DIO_write_port(PORTA_t, 0);
	DIO_write(PORTA_t, select, HIGH);
	DIO_write_port(PORTC_t, seg_decoder[digit]);
}
