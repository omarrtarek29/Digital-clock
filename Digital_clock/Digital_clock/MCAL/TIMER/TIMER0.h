/*
 * TIMER0.h
 *
 * Created: 9/12/2022 5:51:15 PM
 *  Author: omart
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_


#include "TIMER_reg_conf.h"
#include "../../std_macros.h"


void TIMER0_normalMode_init(void);
void TIMER0_ctcMode_init(uint8_t oc, void (*fptr)(void));
void TIMER0_write(uint8_t value);
void TIMER0_ctcMode_stop(void);


#endif /* TIMER0_H_ */