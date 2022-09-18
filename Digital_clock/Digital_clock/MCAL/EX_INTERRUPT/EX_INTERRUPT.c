/*
 * EX_INTERRUPT.c
 *
 * Created: 8/31/2022 9:35:53 PM
 *  Author: omart
 */ 


#include "EX_INTERRUPT.h"


// Pointers to functions to be passed to ISRs
static void (*INT0_Fptr) (void)=NULLPTR;
static void (*INT1_Fptr) (void)=NULLPTR;
static void (*INT2_Fptr) (void)=NULLPTR;


/*****************************************************************************
* Function Name: EX_INTERRUPT_init
* Purpose      : Initialize a specific external interrupt with a specific edge function
* Parameters   : Interrupt number, edge and function to be executed in ISR
* Return value : Void
*****************************************************************************/
void EX_INTERRUPT_init(EX_INT_num_t ex, EX_INT_edge_t edge, void(*fptr)(void)){
	SETBIT(SREG,GINT); // Enable global interrupt
	
	switch (ex)
	{
		case INT0_t:
		SETBIT(GICR,INT0);
		INT0_Fptr = fptr;
		switch (edge)
		{
			case LOW_LEVEL:
			CLRBIT(MCUCR,ISC01);
			CLRBIT(MCUCR,ISC00);
			break;
			
			case ANY_LOGIC_CHANGE:
			CLRBIT(MCUCR,ISC01);
			SETBIT(MCUCR,ISC00);
			break;
			
			case FALLING_EDGE:
			SETBIT(MCUCR,ISC01);
			CLRBIT(MCUCR,ISC00);
			break;
			
			case RISING_EDGE:
			SETBIT(MCUCR,ISC01);
			SETBIT(MCUCR,ISC00);
			break;
		}
		break;
		
		/**********************************************************************/
		
		case INT1_t:
		SETBIT(GICR,INT1);
		INT1_Fptr = fptr;
		switch (edge)
		{
			case LOW_LEVEL:
			CLRBIT(MCUCR,ISC11);
			CLRBIT(MCUCR,ISC10);
			break;
			
			case ANY_LOGIC_CHANGE:
			CLRBIT(MCUCR,ISC11);
			SETBIT(MCUCR,ISC10);
			break;
			
			case FALLING_EDGE:
			SETBIT(MCUCR,ISC11);
			CLRBIT(MCUCR,ISC10);
			break;
			
			case RISING_EDGE:
			SETBIT(MCUCR,ISC11);
			SETBIT(MCUCR,ISC10);
			break;
		}
		
		break;
		
		/**********************************************************************/
		
		case INT2_t:
		SETBIT(GICR,INT2);
		INT2_Fptr = fptr;
		switch (edge)
		{
			case FALLING_EDGE:
			CLRBIT(MCUCSR,ISC2);
			break;
			
			case RISING_EDGE:
			SETBIT(MCUCSR,ISC2);
			break;
			
			default:
			break;
		}
		
		break;
	}
}


/*****************************************************************************
* Function Name: ISR of INT0
* Purpose      : Call the function passed to be executed when INT0 is on
* Parameters   : INT0 isr address
* Return value : Void
*****************************************************************************/
ISR(INT0_vect){
	if (INT0_Fptr != NULLPTR)
	{
		INT0_Fptr();
	}
}


/*****************************************************************************
* Function Name: ISR of INT1
* Purpose      : Call the function passed to be executed when INT1 is on
* Parameters   : INT1 isr address
* Return value : Void
*****************************************************************************/
ISR(INT1_vect){
	if (INT1_Fptr != NULLPTR)
	{
		INT1_Fptr();
	}
}


/*****************************************************************************
* Function Name: ISR of INT2
* Purpose      : Call the function passed to be executed when INT2 is on
* Parameters   : INT2 isr address
* Return value : Void
*****************************************************************************/
ISR(INT2_vect){
	if (INT2_Fptr != NULLPTR)
	{
		INT2_Fptr();
	}
}