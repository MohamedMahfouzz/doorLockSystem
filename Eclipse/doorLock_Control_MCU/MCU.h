 /******************************************************************************
 *
 * 		Module: Main MCU program
 *
 *	 File Name: MCU.h
 *
 * Description: Header file for the MicroController start point
 *
 * 		Author: Mohamed Mahfouz
 *
 *  Created on: Nov 25, 2020
 *
 *******************************************************************************/

#ifndef MCU_H_
#define MCU_H_

/*******************************************************************************
 *							  INCLUDES	  	   		                           *
 *******************************************************************************/

#include "usart.h"
#include "external_eeprom.h"
#include "external_peripherals.h"
#include "timers.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define PASSWORD_LENGTH 	6			/* Length of password containers		 	*/
#define PASSWORD_ADDRESS	0x00FF		/* Address to save password in memory 		*/
#define ERROR_LIMIT 		3			/* Number of times before activating error	*/

/* Success and Error codes */
#define SUCCESS 1
#define ERROR 	0

/* Action success, fail, and error codes */
#define ACTION_SUCCESS 	'!'
#define ACTION_FAIL		')'
#define ACTION_ERROR	'E'

#endif /* MCU_H_ */
