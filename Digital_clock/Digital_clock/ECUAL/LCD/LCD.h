/*
 * LCD.h
 *
 * Created: 8/12/2022 3:46:15 PM
 *  Author: omart
 */ 


#ifndef LCD_H_
#define LCD_H_


#include "../../MCAL/DIO/DIO.h"
#include "../../SERVICES/DELAY/DELAY_MS.h"


#define EN(x)			if(x == 1) DIO_write(PORTD_t, PIN0_t, HIGH); else DIO_write(PORTD_t, PIN0_t, LOW)
#define RS(x)			if(x == 1) DIO_write(PORTD_t, PIN1_t, HIGH); else DIO_write(PORTD_t, PIN1_t, LOW)
#define D4(x)			if(x == 1) DIO_write(PORTD_t, PIN3_t, HIGH); else DIO_write(PORTD_t, PIN3_t, LOW)
#define D5(x)			if(x == 1) DIO_write(PORTD_t, PIN4_t, HIGH); else DIO_write(PORTD_t, PIN4_t, LOW)
#define D6(x)			if(x == 1) DIO_write(PORTD_t, PIN5_t, HIGH); else DIO_write(PORTD_t, PIN5_t, LOW)
#define D7(x)			if(x == 1) DIO_write(PORTD_t, PIN6_t, HIGH); else DIO_write(PORTD_t, PIN6_t, LOW)


void LCD_init(void);
void LCD_write_command(uint8_t command);
void LCD_write_data(uint8_t data);
void LCD_write_string(uint8_t *data);
void LCD_write_number(sint32_t num);


#endif /* LCD_H_ */