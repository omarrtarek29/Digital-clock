/*
 * DIO_reg_conf.h
 *
 * Created: 8/30/2022 8:47:36 PM
 *  Author: omart
 */ 


#ifndef DIO_REG_CONF_H_
#define DIO_REG_CONF_H_


// Defining macros for PORTA registers
#define PORTA		(*(volatile uint8_t *)(0x3B))
#define DDRA		(*(volatile uint8_t *)(0x3A))
#define PINA		(*(volatile uint8_t *)(0x39))


// Defining macros for PORTB registers
#define PORTB		(*(volatile uint8_t *)(0x38))
#define DDRB		(*(volatile uint8_t *)(0x37))
#define PINB		(*(volatile uint8_t *)(0x36))


// Defining macros for PORTC registers
#define PORTC		(*(volatile uint8_t *)(0x35))
#define DDRC		(*(volatile uint8_t *)(0x34))
#define PINC		(*(volatile uint8_t *)(0x33))


// Defining macros for PORTD registers
#define PORTD		(*(volatile uint8_t *)(0x32))
#define DDRD		(*(volatile uint8_t *)(0x31))
#define PIND		(*(volatile uint8_t *)(0x30))


#endif /* DIO_REG_CONF_H_ */