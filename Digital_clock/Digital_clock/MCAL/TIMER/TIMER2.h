/*
 * TIMER2.h
 *
 * Created: 9/14/2022 12:32:48 PM
 *  Author: omart
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_


#include "TIMER_reg_conf.h"
#include "../../std_macros.h"


void TIMER2_normalMode_init(void);
void TIMER2_ctcMode_init(uint8_t oc, void (*fptr)(void));
void TIMER2_write(uint8_t value);
void TIMER2_ctcMode_stop(void);


#endif /* TIMER2_H_ */