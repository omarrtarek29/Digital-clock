/*
 * TIMER1_reg_conf.h
 *
 * Created: 8/30/2022 10:51:00 PM
 *  Author: omart
 */ 


#ifndef TIMER_REG_CONF_H_
#define TIMER_REG_CONF_H_


/************************************************ COMMON TIMER REGISTERS ************************************************/
#define SREG		(*(volatile uint8_t *)(0x5F))
#define GINT		7	// Global interrupt pin		

#define TIMSK		(*(volatile uint8_t *)(0x59))
#define TOIE0		0
#define OCIE0		1
#define TOIE1		2
#define OCIE1B		3
#define OCIE1A		4
#define TICIE1		5
#define TOIE2		6
#define OCIE2		7

#define TIFR		(*(volatile uint8_t *)(0x58))
#define TOV0		0
#define OCF0		1
#define TOV1		2
#define OCF1B		3
#define OCF1A		4
#define ICF1		5
#define TOV2		6
#define OCF2		7


/*************************************************** TIMER0 REGISTERS ***************************************************/
#define TCCR0		(*(volatile uint8_t *)(0x53))
#define CS00		0
#define CS01		1
#define CS02		2
#define WGM01		3
#define COM00		4
#define COM01		5
#define WGM00		6
#define FOC0		7

#define OCR0		(*(volatile uint8_t *)(0x5C))
#define TCNT0		(*(volatile uint8_t *)(0x52))

/*************************************************** TIMER1 REGISTERS ***************************************************/
#define TCCR1A		(*(volatile uint8_t *)(0x4F))
#define WGM10		0
#define WGM11		1
#define FOC1B		2
#define FOC1A		3
#define COM1B0		4
#define COM1B1		5
#define COM1A0		6
#define COM1A1		7

#define TCCR1B		(*(volatile uint8_t *)(0x4E))
#define CS10		0
#define CS11		1
#define CS12		2
#define WGM12		3
#define WGM13		4


#define TCNT1H		(*(volatile uint8_t *)(0x4D))
#define TCNT1L		(*(volatile uint8_t *)(0x4C))

#define OCR1AH		(*(volatile uint8_t *)(0x4B))
#define OCR1AL		(*(volatile uint8_t *)(0x4A))

#define OCR1BH		(*(volatile uint8_t *)(0x49))
#define OCR1BL		(*(volatile uint8_t *)(0x48))


/*************************************************** TIMER2 REGISTERS ***************************************************/
#define TCCR2		(*(volatile uint8_t *)(0x45))
#define CS20		0
#define CS21		1
#define CS22		2
#define WGM21		3
#define COM20		4
#define COM21		5
#define WGM20		6
#define FOC2		7


#define TCNT2		(*(volatile uint8_t *)(0x44))
#define OCR2		(*(volatile uint8_t *)(0x43))


/*************************************************** TIMER ISR ADDRESS ***************************************************/
#define TIMER2_COMP_vect		__vector_4
#define TIMER2_OVF_vect			__vector_5
#define TIMER1_CAPT_vect		__vector_6
#define TIMER1_COMPA_vect		__vector_7
#define TIMER1_COMPB_vect		__vector_8
#define TIMER1_OVF_vect			__vector_9
#define TIMER0_COMP_vect		__vector_10
#define TIMER0_OVF_vect			__vector_11


#endif /* TIMER_REG_CONF_H_ */