/*
 * TIMER0.c
 *
 * Created: 9/12/2022 5:51:06 PM
 *  Author: omart
 */ 


#include "TIMER0.h"


// Pointer to a function to be assigned to ISR
static void (*TIMER0_ctc_Fptr) (void)=NULLPTR;


/*****************************************************************************
* Function Name: TIMER0_normalMode_init
* Purpose      : Initialize Timer0 in normal mode
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void TIMER0_normalMode_init(void){
	SETBIT(TCCR0,CS02);		// Setting prescaler to 1024
	SETBIT(TCCR0,CS00);		// Setting prescaler to 1024
	
	SETBIT(TCCR0,FOC0);		// Setting FOC0 because it's non-PWM mode
	
	SETBIT(TIMSK,TOIE0);	// Enable interrupt on overflow flag
	SETBIT(SREG,GINT);		// Enable global interrupt
}


/*****************************************************************************
* Function Name: TIMER0_ctcMode_init
* Purpose      : Initialize Timer0 in CTC mode
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void TIMER0_ctcMode_init(uint8_t oc, void (*fptr)(void)){
	SETBIT(TCCR0,CS02);		// Setting prescaler to 1024
	SETBIT(TCCR0,CS00);		// Setting prescaler to 1024
	
	SETBIT(TCCR0,FOC0);		// Setting FOC0 because it's non-PWM mode
	SETBIT(TCCR0,WGM01);	// Enable CTC mode
	SETBIT(TCCR0,COM00);	// Toggle when output compare interrupt occurs
	
	OCR0 = oc;				// Setting output compare register with the parameter value
	
	SETBIT(TIMSK,OCIE0);	// Enable interrupt on output compare
	SETBIT(SREG,7);			// Enable global interrupt
}


/*****************************************************************************
* Function Name: TIMER0_ctcMode_stop
* Purpose      : Stops Timer0
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void TIMER0_ctcMode_stop(void){
	TCCR0 = 0;
	CLRBIT(TIMSK,OCIE0);
}


/*****************************************************************************
* Function Name: TIMER0_write
* Purpose      : Write value on timer0 registers
* Parameters   : Value to be written in registers (uint16_t)
* Return value : Void
*****************************************************************************/
void TIMER0_write(uint8_t value){
	TCNT0 = value;
}


/*****************************************************************************
* Function Name: ISR of Timer0 on ctc mode
* Purpose      : Generate interrupt in compare match
* Parameters   : Timer0 ctc isr address
* Return value : Void
*****************************************************************************/
ISR(TIMER0_COMP_vect){
	if (TIMER0_ctc_Fptr != NULLPTR)
	{
		TIMER0_ctc_Fptr();
	}
}