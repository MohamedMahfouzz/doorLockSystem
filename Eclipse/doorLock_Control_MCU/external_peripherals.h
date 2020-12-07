 /******************************************************************************
 *
 * 		Module: External Peripherals
 *
 *	 File Name: external_peripherals.h
 *
 * Description: Header file for external peripherals
 *
 * 		Author: Mohamed Mahfouz
 *
 *  Created on: Nov 24, 2020
 *
 *******************************************************************************/

#ifndef EXTERNAL_PERIPHERALS_H_
#define EXTERNAL_PERIPHERALS_H_

/*******************************************************************************
 *							  INCLUDES	  	   		                           *
 *******************************************************************************/

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define MOTOR_STOP 		0		/* Motor stop bit values 			*/
#define MOTOR_START_CW	1		/* Motor CW start bit values 		*/
#define MOTOR_START_CCW	2		/* Motor CCW start bit values 		*/
#define MOTOR_PORT_DIR	DDRC	/* PORTC direction configuration	*/
#define MOTOR_PORT_OUT	PORTC	/* PORTC output pins configuration 	*/

#define BUZZER_ON		1		/* Start Buzzer						*/
#define BUZZER_OFF		0		/* Stop Buzzer 						*/
#define BUZZER_PORT_DIR	DDRC	/* PORTC direction configuration	*/
#define BUZZER_PORT_OUT	PORTC	/* PORTC output pins configuration 	*/

/*******************************************************************************
 *                      Function Declarations                                  *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]	: EXTERNALPERIPHERALS_init
 * [Description]	: Initiate all external peripherals and their registers
 * [Args]			: N/A
 * [Returns]		: N/A
 *******************************************************************************/
void EXTERNALPERIPHERALS_init(void);

/*******************************************************************************
 * [Function Name]	: EXTERNALPERIPHERALS_openDoor
 * [Description]	: Unlocks door
 * [Args]			: N/A
 * [Returns]		: N/A
 *******************************************************************************/
void EXTERNALPERIPHERALS_openDoor(void);

/*******************************************************************************
 * [Function Name]	: EXTERNALPERIPHERALS_holdDoor
 * [Description]	: Holds door unlocked
 * [Args]			: N/A
 * [Returns]		: N/A
 *******************************************************************************/
void EXTERNALPERIPHERALS_holdDoor(void);

/*******************************************************************************
 * [Function Name]	: EXTERNALPERIPHERALS_closeDoor
 * [Description]	: Locks door
 * [Args]			: N/A
 * [Returns]		: N/A
 *******************************************************************************/
void EXTERNALPERIPHERALS_closeDoor(void);

/*******************************************************************************
 * [Function Name]	: EXTERNALPERIPHERALS_startAlarm
 * [Description]	: Starts Alarm from buzzer
 * [Args]			: N/A
 * [Returns]		: N/A
 *******************************************************************************/
void EXTERNALPERIPHERALS_startAlarm(void);

/*******************************************************************************
 * [Function Name]	: EXTERNALPERIPHERALS_stopAlarm
 * [Description]	: Stops Alarm from buzzer
 * [Args]			: N/A
 * [Returns]		: N/A
 *******************************************************************************/
void EXTERNALPERIPHERALS_stopAlarm(void);

#endif /* EXTERNAL_PERIPHERALS_H_ */
