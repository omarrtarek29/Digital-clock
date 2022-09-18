/*
 * KEYPAD.h
 *
 * Created: 8/16/2022 3:27:11 PM
 *  Author: omart
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../std_macros.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../SERVICES/DELAY/DELAY_MS.h"


#define K0		DIO_read(PORTB_t, PIN0_t)
#define K1		DIO_read(PORTB_t, PIN1_t)
#define K2		DIO_read(PORTB_t, PIN2_t)
#define K3		DIO_read(PORTB_t, PIN3_t)
#define K4(x)	if (x == 1)		DIO_write(PORTB_t, PIN4_t, HIGH); else DIO_write(PORTB_t, PIN4_t, LOW)
#define K5(x)	if (x == 1)		DIO_write(PORTB_t, PIN5_t, HIGH); else DIO_write(PORTB_t, PIN5_t, LOW)
#define K6(x)	if (x == 1)		DIO_write(PORTB_t, PIN6_t, HIGH); else DIO_write(PORTB_t, PIN6_t, LOW)
#define K7(x)	if (x == 1)		DIO_write(PORTB_t, PIN7_t, HIGH); else DIO_write(PORTB_t, PIN7_t, LOW)


void KEYPAD_init(void);
uint8_t KEYPAD_read(void);


#endif /* KEYPAD_H_ */