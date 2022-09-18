/*
 * TIMER1.c
 *
 * Created: 8/30/2022 11:18:45 PM
 *  Author: omart
 */ 

#include "TIMER1.h"


// Pointer to a function to be assigned to ISR
static void (*TIMER1_ctc_Fptr) (void)=NULLPTR;

/*****************************************************************************
* Function Name: TIMER1_normalMode_init
* Purpose      : Initialize Timer1 in normal mode
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void TIMER1_normalMode_init(void){
	SETBIT(TCCR1B,CS12);		// Setting prescaler to 256
	
	SETBIT(TCCR1A,FOC1B);		// Setting FOC1B because it's non-PWM mode
	SETBIT(TCCR1A,FOC1A);		// Setting FOC1A because it's non-PWM mode
	
	SETBIT(TIMSK,TOIE1);		// Enable overflow flag
	SETBIT(SREG,GINT);			// Enable global interrupt
}


/*****************************************************************************
* Function Name: TIMER1_ctcMode_init
* Purpose      : Initialize Timer1 in CTC mode
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void TIMER1_ctcMode_init(uint16_t oc, void (*fptr)(void)){
	SETBIT(TCCR1B,CS10);		// No prescaler
	SETBIT(TCCR1B,WGM12);		// Enable CTC mode
	
	SETBIT(TCCR1A,FOC1A);		// Setting FOC1A because it's non-PWM mode
	SETBIT(TCCR1A,COM1A0);		// Toggle when compare match occurs
	
	// oc 16 bits ... we need to put least 8 bits in OCR1AL and most 8 bits in OCR1AH
	OCR1AH = (oc >> 8);
	OCR1AL = oc;
	
	SETBIT(TIMSK,OCIE1A);		// Enable overflow flag when compare match
	SETBIT(SREG,GINT);			// Enable global interrupt
	
	// Clear timer1 register
	TCNT1H = 0;
	TCNT1L = 0;
	
	TIMER1_ctc_Fptr = fptr;
}


/*****************************************************************************
* Function Name: TIMER1_ctcMode_stop
* Purpose      : Stops Timer1
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void TIMER1_ctcMode_stop(void){
	TCCR1A = 0;
	TCCR1B = 0;
	TIMSK &= 0b11000011;
}


/*****************************************************************************
* Function Name: TIMER1_write
* Purpose      : Write value on timer1 registers
* Parameters   : Value to be written in registers (uint16_t)
* Return value : Void
*****************************************************************************/
void TIMER1_write(uint16_t value){
	TCNT1L = value;			// This will store the least 8 bits in TCNT1L
	TCNT1H = (value >> 8);	// This will store the most 8 bits in TCNT1H
}


/*****************************************************************************
* Function Name: ISR of Timer1 on ctc mode
* Purpose      : Generate interrupt in compare match
* Parameters   : Timer1 ctc isr address
* Return value : Void
*****************************************************************************/
ISR(TIMER1_COMPA_vect){
	if (TIMER1_ctc_Fptr != NULLPTR)
	{
		TIMER1_ctc_Fptr();
	}
}