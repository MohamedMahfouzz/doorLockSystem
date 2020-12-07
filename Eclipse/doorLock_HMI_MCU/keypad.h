 /******************************************************************************
 *
 * 		Module: Keypad
 *
 * 	 File Name: keypad.h
 *
 * Description: Header file for keypad driver
 *
 * 		Author: Mohamed Mahfouz
 *
 * 	Created on: Nov 20, 2020
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

/*******************************************************************************
 *                      	   Includes	  	   		                           *
 *******************************************************************************/

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define N_COL 4		/* Number of columns in keypad	*/
#define N_ROW 4 	/* Number of rows in keypad		*/

/* Keypad Port Configurations */
#define KEYPAD_PORT_DIR DDRA	/* PORTA direction configuration	*/
#define KEYPAD_PORT_IN  PINA 	/* PORTA input pins configuration 	*/
#define KEYPAD_PORT_OUT PORTA 	/* PORTA output pins configuration 	*/

/*******************************************************************************
 *                      Function Declarations                                  *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]	: Keypad_getPressed
 * [Description]	: Function responsible for getting the key pressed on the keypad
 * [Args]			: N/A
 * [Returns]		: [unsigned character] key pressed on keypad
 *******************************************************************************/
uint8 KEYPAD_getPressed(void);

#endif /* KEYPAD_H_ */
