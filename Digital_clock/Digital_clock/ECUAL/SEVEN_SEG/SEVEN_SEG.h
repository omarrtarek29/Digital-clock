/*
 * SEVEN_SEG.h
 *
 * Created: 8/17/2022 5:53:05 PM
 *  Author: omart
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_


#include "../../MCAL/DIO/DIO.h"
#include "../../SERVICES/DELAY/DELAY_MS.h"


// Defining an enum for pin number to pass them easier to APIs
typedef enum{
	SEG0 = PIN0_t,
	SEG1 = PIN1_t,
	SEG2 = PIN2_t,
	SEG3 = PIN3_t,
	SEG4 = PIN4_t,
	SEG5 = PIN5_t,
	SEG6 = PIN6_t
}SEG_select_t;


void SEVEN_SEG_init(void);
void SEVEN_SEG_init_enables(void);
void SEVEN_SEG_write_digit(SEG_select_t select, uint8_t digit);


#endif /* SEVEN_SEG_H_ */