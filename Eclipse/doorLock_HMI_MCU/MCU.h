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

#include "lcd.h"
#include "keypad.h"
#include "usart.h"
#include "timers.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define PASSWORD_LENGTH 6		/* Length of password containers */


/* Action success, fail, and error codes */
#define ACTION_SUCCESS 	'!'
#define ACTION_FAIL		')'
#define ACTION_ERROR	'E'

#endif /* MCU_H_ */
