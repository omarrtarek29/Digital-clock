/*
 * KEYPAD.c
 *
 * Created: 8/16/2022 3:27:03 PM
 *  Author: omart
 */ 

#include "KEYPAD.h"


const uint8_t keypad_matrix[] = {'7', '8', '9', '/',
								 '4', '5', '6', '*',
								 '1', '2', '3', '-',
								 'C', '0', '=', '+'};
								 
								 

/*****************************************************************************
* Function Name: KEYPAD_init
* Purpose      : Initialize keypad
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void KEYPAD_init(void){
	// Set pins 4-7 as output & 0-3 as input pull-up
	DIO_init_pin(PORTB_t, PIN0_t, INPUT);
	DIO_init_pin(PORTB_t, PIN1_t, INPUT);
	DIO_init_pin(PORTB_t, PIN2_t, INPUT);
	DIO_init_pin(PORTB_t, PIN3_t, INPUT);
	DIO_write(PORTB_t, PIN0_t, HIGH);
	DIO_write(PORTB_t, PIN1_t, HIGH);
	DIO_write(PORTB_t, PIN2_t, HIGH);
	DIO_write(PORTB_t, PIN3_t, HIGH);
	
	DIO_init_pin(PORTB_t, PIN4_t, OUTPUT);
	DIO_init_pin(PORTB_t, PIN5_t, OUTPUT);
	DIO_init_pin(PORTB_t, PIN6_t, OUTPUT);
	DIO_init_pin(PORTB_t, PIN7_t, OUTPUT);
}


/*****************************************************************************
* Function Name: KEYPAD_read
* Purpose      : Reads a keypad key
* Parameters   : Void
* Return value : Pressed key (uint8_t)
*****************************************************************************/
uint8_t KEYPAD_read(void){
	K4(0); K5(1); K6(1); K7(1);	
	
	if(K0 == 0) return keypad_matrix[0];
	if(K1 == 0) return keypad_matrix[4];
	if(K2 == 0) return keypad_matrix[8];
	if(K3 == 0) return keypad_matrix[12];
	delay_ms(1);
	
	K4(1); K5(0); K6(1); K7(1);
	if(K0 == 0) return keypad_matrix[1];
	if(K1 == 0) return keypad_matrix[5];
	if(K2 == 0) return keypad_matrix[9];
	if(K3 == 0) return keypad_matrix[13];
	delay_ms(1);
	
	K4(1); K5(1); K6(0); K7(1);
	if(K0 == 0) return keypad_matrix[2];
	if(K1 == 0) return keypad_matrix[6];
	if(K2 == 0) return keypad_matrix[10];
	if(K3 == 0) return keypad_matrix[14];
	delay_ms(1);
	
	K4(1); K5(1); K6(1); K7(0);
	if(K0 == 0) return keypad_matrix[3];
	if(K1 == 0) return keypad_matrix[7];
	if(K2 == 0) return keypad_matrix[11];
	if(K3 == 0) return keypad_matrix[15];
	delay_ms(1);
	
	return 0;
}