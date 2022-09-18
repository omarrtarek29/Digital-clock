/*
 * TIMER2.c
 *
 * Created: 9/14/2022 12:32:38 PM
 *  Author: omart
 */ 


#include "TIMER2.h"


// Pointer to a function to be assigned to ISR
static void (*TIMER2_ctc_Fptr) (void)=NULLPTR;


/*****************************************************************************
* Function Name: TIMER2_normalMode_init
* Purpose      : Initialize Timer2 in normal mode
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void TIMER2_normalMode_init(void){
	// Setting prescaler to 1024
	SETBIT(TCCR2,CS22);		
	SETBIT(TCCR2,CS21);
	SETBIT(TCCR2,CS20);
	
	SETBIT(TCCR2,FOC2);		// Setting FOC2 because it's non-PWM mode
	
	SETBIT(TIMSK,TOIE2);	// Enable interrupt on overflow flag
	SETBIT(SREG,GINT);		// Enable global interrupt
}


/*****************************************************************************
* Function Name: TIMER2_ctcMode_init
* Purpose      : Initialize Timer0 in CTC mode
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void TIMER2_ctcMode_init(uint8_t oc, void (*fptr)(void)){
	// Setting prescaler to 8
	CLRBIT(TCCR2,CS22);
	SETBIT(TCCR2,CS21);
	CLRBIT(TCCR2,CS20);
	
	SETBIT(TCCR2,FOC2);		// Setting FOC2 because it's non-PWM mode
	SETBIT(TCCR2,WGM21);	// Enable CTC mode
	SETBIT(TCCR2,COM20);	// Toggle when output compare interrupt occurs
	
	OCR2 = oc;				// Setting output compare register with the parameter value
	
	SETBIT(TIMSK,OCIE2);	// Enable interrupt on output compare
	SETBIT(SREG,7);			// Enable global interrupt
	
	TIMER2_ctc_Fptr = fptr; // Passing the giving function to ISR
}


/*****************************************************************************
* Function Name: TIMER2_ctcMode_stop
* Purpose      : Stops Timer0
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void TIMER2_ctcMode_stop(void){
	TCCR2 = 0;
	CLRBIT(TIMSK,OCIE2);
}


/*****************************************************************************
* Function Name: TIMER2_write
* Purpose      : Write value on timer2 registers
* Parameters   : Value to be written in registers (uint16_t)
* Return value : Void
*****************************************************************************/
void TIMER2_write(uint8_t value){
	TCNT2 = value;
}


/*****************************************************************************
* Function Name: ISR of Timer2 on CTC mode
* Purpose      : Generate interrupt in compare match
* Parameters   : Timer0 CTC ISR address
* Return value : Void
*****************************************************************************/
ISR(TIMER2_COMP_vect){
	if (TIMER2_ctc_Fptr != NULLPTR)
	{
		TIMER2_ctc_Fptr();
	}
}