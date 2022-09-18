/*
 * std_macros.h
 *
 * Created: 8/11/2022 10:03:00 PM
 *  Author: omart
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

//#include <avr/interrupt.h>


typedef unsigned char		uint8_t;
typedef signed char			sint8_t;

typedef unsigned short		uint16_t;
typedef signed short		sint16_t;

typedef unsigned long		uint32_t;
typedef signed long			sint32_t;

#define NULLPTR   ((void*)0)

#define F_CPU 1000000UL


#define SETBIT(REG,BIT) (REG |= 1<<BIT)
#define CLRBIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^= 1<<BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)

#define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

#endif /* STD_MACROS_H_ */