/*
 * APP.c
 *
 * Created: 9/16/2022 11:36:11 AM
 *  Author: omart
 */ 


#include "APP.h"


static uint8_t seconds = 26;
static uint8_t minutes = 24;
static uint8_t hours = 11;
static uint8_t key = 0;
static uint8_t edit_click = 0;
static volatile uint8_t flag = 0;

MODE_t mode = NORMAL_MODE;


/*****************************************************************************
* Function Name: APP_init
* Purpose      : Initialize app
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void APP_init(void){
	LCD_init();
	TIMER2_ctcMode_init(125, increment_seconds);
	
	SEVEN_SEG_init();
	BUTTON_init(PORTD_t, PIN2_t);
	
	KEYPAD_init();
}


/*****************************************************************************
* Function Name: APP_loop
* Purpose      : Keep app running continuously
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void APP_loop(void){
	while (1)
	{
		/***********************************************************************************************************************************/
		/********************************************************* NORMAL MODE *************************************************************/
		/***********************************************************************************************************************************/
		switch (mode)
		{
			case NORMAL_MODE:
			// Checks if user needed edit mode
			key = KEYPAD_read();
			if (key == 'C')
			{
				mode = EDIT_MODE;
				flag = 1;
				continue;			// Skip iteration to go to edit mode
			}
			
			if (seconds == 60)
			{
				minutes++;
				seconds = 0;
			}
			
			if (minutes == 60)
			{
				hours++;
				minutes = 0;
			}
			
			if (hours == 24)
			{
				seconds = 0;
				minutes = 0;
				hours = 0;
			}

			LCD_write_command(0x80);
			LCD_write_number(hours / 10);
			LCD_write_number(hours % 10);
			LCD_write_data(':');
			LCD_write_number(minutes / 10);
			LCD_write_number(minutes % 10);
			LCD_write_data(':');
			LCD_write_number(seconds / 10);
			LCD_write_number(seconds % 10);
			break;
			
			/***********************************************************************************************************************************/
			/********************************************************** EDIT MODE **************************************************************/
			/***********************************************************************************************************************************/
			
			case EDIT_MODE:
			
			key = get_key_value();
			
			switch (key)
			{
				case 'C':
				edit_click++;
				if (edit_click == 3)
				{
					flag = 0;
					edit_click = 0;
					mode = NORMAL_MODE;
					continue;
				}
				break;
				
				case '+':
				if (edit_click == 1)
				{
					if (minutes == 59)
					{
						minutes = 0;
					}
					else
					{
						minutes++;
					}
				}
				else if (edit_click == 2)
				{
					if (hours == 23)
					{
						hours = 0;
					}
					else
					{
						hours++;
					}
				}
				break;
				
				case '-':
				if (edit_click == 1)
				{
					if (minutes == 0)
					{
						minutes = 59;
					}
					else
					{
						minutes--;
					}
				}
				else if (edit_click == 2)
				{
					if (hours == 0)
					{
						hours = 23;
					}
					else
					{
						hours--;
					}
				}
				break;
			}
			break;
		}
	}
}


/*****************************************************************************
* Function Name: increment_seconds
* Purpose      : function to timer2 isr
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void increment_seconds(void){
	static uint16_t ovf_counter = 0;
	static uint8_t seg_counter = 0;
	
	
	// Prescaler 8 and Freq 1 Mhz --> each tick = 8 us
	// 125 ticks == 1000 us == 1 ms
	// 1000ms == 1000 interrupts needed

	if (flag == 0)
	{
		ovf_counter++;
	}
	
	if (ovf_counter == 1000)
	{
		seconds++;
		ovf_counter = 0;
	}
	
	switch (seg_counter)
	{
		case 0:
		SEVEN_SEG_write_digit(SEG0, (seconds % 10));
		seg_counter++;
		break;
		
		case 1:
		SEVEN_SEG_write_digit(SEG1, (seconds / 10));
		seg_counter++;
		break;
		
		case 2:
		SEVEN_SEG_write_digit(SEG2, (minutes % 10));
		seg_counter++;
		break;
		
		case 3:
		SEVEN_SEG_write_digit(SEG3, (minutes / 10));
		seg_counter++;
		break;
		
		case 4:
		SEVEN_SEG_write_digit(SEG4, (hours % 10));
		seg_counter++;
		break;
		
		case 5:
		SEVEN_SEG_write_digit(SEG5, (hours / 10));
		seg_counter = 0;
		break;
	}
	
}


/*****************************************************************************
* Function Name: get_key_value
* Purpose      : Reads a pressed keypad key
* Parameters   : Void
* Return value : Pressed key (uint8_t)
*****************************************************************************/
uint8_t get_key_value(void){
	uint8_t key;
	key = KEYPAD_read();
	
	// Stuck in the loop until user press a key
	// key == 0 means it's still null, meaning user still didn't press any key
	while (key == 0)
	{
		key = KEYPAD_read();
	}
	
	//LCD_write_data(key);
	// Stuck if user kept pressing the key until he release
	while (KEYPAD_read() == key);
	
	return key;
}

