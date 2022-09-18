/*
 * BUTTON.h
 *
 * Created: 8/31/2022 5:54:10 PM
 *  Author: omart
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


#include "../../MCAL/DIO/DIO.h"


void BUTTON_init(REG_name_t reg, PIN_num_t pin);
uint8_t BUTTON_read(REG_name_t reg, PIN_num_t pin);


#endif /* BUTTON_H_ */