/*
 * APP.h
 *
 * Created: 9/16/2022 11:35:58 AM
 *  Author: omart
 */ 


#ifndef APP_H_
#define APP_H_

#include "../MCAL/TIMER/TIMER2.h"
#include "../ECUAL/SEVEN_SEG/SEVEN_SEG.h"
#include "../ECUAL/BUTTON/BUTTON.h"
#include "../ECUAL/KEYPAD/KEYPAD.h"
#include "../ECUAL/LCD/LCD.h"


typedef enum
{
	NORMAL_MODE,
	EDIT_MODE
}MODE_t;


void APP_init(void);
void APP_loop(void);
void increment_seconds(void);
uint8_t get_key_value(void);


#endif /* APP_H_ */