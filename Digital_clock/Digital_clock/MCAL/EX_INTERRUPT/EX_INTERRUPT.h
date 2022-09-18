/*
 * EX_INTERRUPT.h
 *
 * Created: 8/31/2022 9:36:03 PM
 *  Author: omart
 */ 


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_


#include "EX_INTERRUPT_reg_conf.h"
#include "../../std_macros.h"


// Defining an enum for external interrupt numbers to pass them easier to APIs
typedef enum{
	INT0_t,
	INT1_t,
	INT2_t
}EX_INT_num_t;


// Defining an enum for external interrupt edge to pass them easier to APIs
typedef enum{
	LOW_LEVEL,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}EX_INT_edge_t;


void EX_INTERRUPT_init(EX_INT_num_t ex, EX_INT_edge_t edge, void(*fptr)(void));


#endif /* EX_INTERRUPT_H_ */