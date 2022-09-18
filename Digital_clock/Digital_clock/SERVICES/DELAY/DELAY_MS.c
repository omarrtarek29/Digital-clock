/*
 * DELAY_MS.c
 *
 * Created: 8/31/2022 8:47:33 PM
 *  Author: omart
 */ 


#include "DELAY_MS.h"


volatile uint16_t int_counter = 0;


/*****************************************************************************
* Function Name: delay_ms
* Purpose      : Delay function in milliseconds
* Parameters   : Value in milliseconds (uint16_t)
* Return value : Void
*****************************************************************************/
void delay_ms(uint16_t delayTime){
	TIMER1_ctcMode_init(1000, timer1_ptr_function);
	int_counter = 0;
	// Setting f_cpu to 1Mhz and no prescaler
	// 1 tick == 1 microseconds
	// 1000 ticks == 1 milliseconds
	// Already set timer to generate interrupt when it ticks 1000 times
	// So, we need to interrupt by the value of delay we want
	// Meaning 5000ms == 5000 interrupts
	while (int_counter < delayTime){}
	TIMER1_ctcMode_stop();
}


/*****************************************************************************
* Function Name: timer1_ptr_function
* Purpose      : Function to be passed to timer1 ctc interrupt (increment a variable by 1)
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void timer1_ptr_function(void){
	int_counter++;
}
