 /******************************************************************************
 *
 * 		Module: ATMega16 Integrated Timers
 *
 *	 File Name: timers.h
 *
 * Description: Header file for integrated timer modules
 *
 * 		Author: Mohamed Mahfouz
 *
 *  Created on: Nov 24, 2020
 *
 *******************************************************************************/

#ifndef TIMERS_H_
#define TIMERS_H_

/*******************************************************************************
 *							  INCLUDES	  	   		                           *
 *******************************************************************************/

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

/*******************************************************************************
 *                      Global Variables                              	   	   *
 *******************************************************************************/

extern uint8 g_timePassed;		/* Variable to save time passed */

/*******************************************************************************
 *							  ENUMS 	  	   		                           *
 *******************************************************************************/

/*******************************************************************************
 * [Enum Name]		: TIMER_WaveformGenerationMode
 * [Description]	: Enum for timer wave form generation options
 *******************************************************************************/
typedef enum
{
	/* TIMER0 & TIMER2 configuration */
	NORMAL_COUNTING,						/* Normal counter mode */
	PWM_PHASE_CORRECT,						/* PWM phase correct mode */
	CLEAR_TIMER_COMPARE,					/* CTC mode */
	FAST_PWM,								/* Fast PWM mode */

	/* TIMER1 configuration */
	PWM_PHASE_CORRECT_8BIT = 1,				/* PWM phase correct mode with 8 bits TOP mode */
	PWM_PHASE_CORRECT_9BIT,					/* PWM phase correct mode with 9 bits TOP mode */
	PWM_PHASE_CORRECT_10BIT,				/* PWM phase correct mode with 10 bits TOP mode */
	CLEAR_TIMER_COMPARE_OCR1A,				/* CTC mode with OCR1A TOP mode */
	FAST_PWM_8BIT,							/* Fast PWM mode with 8 bits TOP mode */
	FAST_PWM_9BIT,							/* Fast PWM mode with 9 bits TOP mode */
	FAST_PWM_10BIT,							/* Fast PWM mode with 10 bits TOP mode */
	PMW_PHASE_FREQUENCY_CORRECT_ICR1,		/* PWM phase frequency correct mode with ICR1 TOP mode */
	PMW_PHASE_FREQUENCY_CORRECT_OCR1A,		/* PWM phase frequency correct mode with OCR1A TOP mode */
	PMW_PHASE_CORRECT_ICR1,					/* PWM phase correct mode with ICR1 TOP mode */
	PMW_PHASE_CORRECT_OCR1A,				/* PWM phase correct mode with OCR1A TOP mode */
	CLEAR_TIMER_COMPARE_ICR1,				/* CTC mode with ICR1 TOP mode */
	FAST_PWM_ICR1 = 14,						/* Fast PWM mode with ICR1 TOP mode */
	FAST_PWM_OCR1A							/* Fast PWM mode with OCR1A TOP mode */
}TIMER_WaveformGenerationMode;

/*******************************************************************************
 * [Enum Name]		: TIMER_CompareMatchMode
 * [Description]	: Enum for compare match output behavior
 *******************************************************************************/
typedef enum
{
	NORMAL_OPERATION,		/* OC1X is disabled, port works normally */
	TOGGLE_OC1X,			/* OC1X is toggled on compare match */
	CLEAR_OC1X,				/* OC1X is cleared on compare match */
	SET_OC1X				/* OC1X is set on compare match */
}TIMER_CompareMatchMode;

/*******************************************************************************
 * [Enum Name]		: TIMER_ClockPrescalar
 * [Description]	: Enum to control timer prescalar value
 *******************************************************************************/
typedef enum
{
	NO_CLOCK,					/* Disable clock */
	NO_PRESCALING,				/* Activate clock with no prescaling */
	FCPU_8,						/* Activate clock with prescaling F_CPU/8 */
	FCPU_64,					/* Activate clock with prescaling F_CPU/64 */
	FCPU_256,					/* Activate clock with prescaling F_CPU/256 */
	FCPU_1024,					/* Activate clock with prescaling F_CPU/1024 */
	EXTERNAL_FALLING_EDGE,		/* Activate with external clock on falling edge */
	EXTERNAL_RISING_EDGE		/* Activate with external clock on falling edge */
}TIMER_ClockPrescaler;

/*******************************************************************************
 *						Structures & Unions	   		                           *
 *******************************************************************************/

/*******************************************************************************
 * [Structure Name]	: TIMERS_ConfigType
 * [Description]	: Struct responsible for timers configuration
 *******************************************************************************/
typedef struct
{
	uint16 initialValue;							/* Initial value for timer */
	uint16 topValue;								/* Top value for timer */
	TIMER_WaveformGenerationMode waveForm	: 4;	/* Controlling waveform generation mode */
	uint8									: 4;	/* Padding */
	TIMER_ClockPrescaler prescaler			: 3;	/* Prescaler to Interrupt generation control */
	uint8									: 5;	/* Padding */
	TIMER_CompareMatchMode compareMatchA	: 2;	/* Action on compare match A */
	uint8									: 6;	/* Padding */
	TIMER_CompareMatchMode compareMatchB	: 2;	/* Action on compare match B */
	uint8									: 6;	/* Padding */
}TIMERS_ConfigType;

/*******************************************************************************
 *                      Function Declarations                                  *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]	: TIMER1_init
 * [Description]	: Initialize integrated timer 1
 * [Args]
 * 		[IN] const TIMERS_ConfigType * a_s_configuration_Ptr
 * 					: Pointer to structure containing timer configuration
 *
 * [Returns]		: N/A
 *******************************************************************************/
void TIMER1_init(const TIMERS_ConfigType * a_s_configuration_Ptr);

/*******************************************************************************
 * [Function Name]	: TIMER1_start
 * [Description]	: Start timer 1 functionality
 * [Args]			: N/A
 * [Returns]		: N/A
 *******************************************************************************/
void TIMER1_start();

/*******************************************************************************
 * [Function Name]	: TIMER1_stop
 * [Description]	: Stop timer 1 functionality
 * [Args]			: N/A
 * [Returns]		: N/A
 *******************************************************************************/
void TIMER1_stop();

#endif /* TIMERS_H_ */
