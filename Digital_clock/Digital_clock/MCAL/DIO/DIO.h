/*
 * DIO.h
 *
 * Created: 8/30/2022 8:47:11 PM
 *  Author: omart
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "DIO_reg_conf.h"
#include "../../std_macros.h"

// Defining an enum for register names to pass them easier to APIs
typedef enum{
	PORTA_t,
	PORTB_t,
	PORTC_t,
	PORTD_t
}REG_name_t;


// Defining an enum for pin number to pass them easier to APIs
typedef enum{
	PIN0_t,
	PIN1_t,
	PIN2_t,
	PIN3_t,
	PIN4_t,
	PIN5_t,
	PIN6_t,
	PIN7_t
}PIN_num_t;


// Defining an enum for pin direction to pass them easier to APIs
typedef enum{
	INPUT,
	OUTPUT
}PIN_direction_t;


// Defining an enum for pin value to pass them easier to APIs
typedef enum{
	LOW,
	HIGH
}PIN_value_t;

void DIO_init_pin(REG_name_t reg, PIN_num_t pin, PIN_direction_t direction);
void DIO_init_port(REG_name_t reg, PIN_direction_t direction);
void DIO_write(REG_name_t reg, PIN_num_t pin, PIN_value_t value);
void DIO_write_port(REG_name_t reg, uint8_t value);
void DIO_toggle(REG_name_t reg, PIN_num_t pin);
PIN_value_t DIO_read(REG_name_t reg, PIN_num_t pin);


#endif /* DIO_H_ */