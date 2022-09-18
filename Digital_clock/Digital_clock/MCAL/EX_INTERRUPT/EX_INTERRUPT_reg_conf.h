/*
 * EX_INTERRUPT_reg_conf.h
 *
 * Created: 8/31/2022 9:36:45 PM
 *  Author: omart
 */ 


#ifndef EX_INTERRUPT_REG_CONF_H_
#define EX_INTERRUPT_REG_CONF_H_


// Defining macros for needed registers and pins
#define SREG		(*(volatile uint8_t *)(0x5F))
#define GINT		7	// Global interrupt pin

#define GICR		(*(volatile uint8_t *)(0x5B))
#define INT2		5
#define INT0		6
#define INT1		7

#define MCUCR		(*(volatile uint8_t *)(0x55))
#define ISC00		0
#define ISC01		1
#define ISC10		2
#define ISC11		3

#define MCUCSR		(*(volatile uint8_t *)(0x54))
#define ISC2		6

#define INT0_vect			__vector_1
#define INT1_vect			__vector_2
#define INT2_vect			__vector_3

#endif /* EX_INTERRUPT_REG_CONF_H_ */