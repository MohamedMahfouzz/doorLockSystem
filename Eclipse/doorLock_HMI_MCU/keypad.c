/******************************************************************************
 *
 * 		Module: Keypad
 *
 * 	 File Name: keypad.c
 *
 * Description: Source file for keypad driver
 *
 * 		Author: Mohamed Mahfouz
 *
 * 	Created on: Nov 20, 2020
 *
 *******************************************************************************/

/*******************************************************************************
 *                      	   INCLUDES	  	   		                           *
 *******************************************************************************/

#include "keypad.h"

/*******************************************************************************
 *                    Private Function Prototypes                              *
 *******************************************************************************/

#if (N_COL == 3)
/*
 * Button mapping function for 3x4 keypads
 */
static uint8 KEYPAD_4x3_adjustSwitchNumber(uint8 a_keyNumber);
#elif (N_COL == 4)
/*
 * Button mapping function for 4x4 keypads
 */
static uint8 KEYPAD_4x4_adjustSwitchNumber(uint8 a_keyNumber);
#endif

/*******************************************************************************
 *                       Function Definitions                                  *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]	: Keypad_getPressed
 * [Description]	: Function responsible for getting the key pressed on the keypad
 * [Args]			: N/A
 * [Returns]		: [unsigned character] key pressed on keypad
 *******************************************************************************/
uint8 KEYPAD_getPressed(void){
	while(1){
		for (uint8 col = 0; col < N_COL; col++){		/* Loop to pass through all columns */
			KEYPAD_PORT_DIR = 0x10<<col;				/* Setting 1 column as output at a time */
			KEYPAD_PORT_OUT = ~(0x10<<col);				/* Setting current column output as 0 and activating pull-up resistor for all rows */
			for (uint8 row = 0; row < N_ROW; row++){	/* Loop to pass through all rows for currently active column */
				if (BIT_IS_CLEAR(KEYPAD_PORT_IN, row)){	/* Check if key pressed in any row */
#if N_COL == 3
					return KEYPAD_4x3_adjustSwitchNumber((row*N_COL)+col+1);	/* return value of key pressed */
#elif N_COL == 4
					return KEYPAD_4x4_adjustSwitchNumber((row*N_COL)+col+1);	/* return value of key pressed */
#endif
				}
			}
		}
	}
}

#if N_COL == 3
/*******************************************************************************
 * [Function Name]	: Keypad_4x3_adjustSwitchNumber
 * [Description]	: Function responsible for mapping the key pressed on keypad
 * 					  to a correct output
 * [Args]
 * 		[IN] unsigned char a_keyNumber
 * 					: index of key pressed on keypad
 *
 * [Returns]		: [unsigned character] key pressed on keypad
 *******************************************************************************/
static uint8 KEYPAD_4x3_adjustSwitchNumber(uint8 a_keyNumber)
{
	switch(a_keyNumber)
	{
	case 10: return '*'; /* ASCII Code of * */

	case 11: return 0;

	case 12: return '#'; /* ASCII Code of # */

	default: return a_keyNumber;
	}
}

#elif N_COL == 4
/*******************************************************************************
 * [Function Name]	: Keypad_4x4_adjustSwitchNumber
 * [Description]	: Function responsible for mapping the key pressed on keypad
 * 					  to a correct output
 * [Args]
 * 		[IN] unsigned char a_keyNumber
 * 					: index of key pressed on keypad
 *
 * [Returns]		: [unsigned character] key pressed on keypad
 *******************************************************************************/
static uint8 KEYPAD_4x4_adjustSwitchNumber(uint8 a_keyNumber){

	switch(a_keyNumber)
	{
	case 1: return 7;

	case 2: return 8;

	case 3: return 9;

	case 4: return '/'; 	/* ASCII Code of / */

	case 5: return 4;

	case 6: return 5;

	case 7: return 6;

	case 8: return '*';		/* ASCII Code of '*' */

	case 9: return 1;

	case 10: return 2;

	case 11: return 3;

	case 12: return '-';	/* ASCII Code of '-' */

	case 13: return 13;  	/* ASCII Code of Enter */

	case 14: return 0;

	case 15: return '='; 	/* ASCII Code of '=' */

	case 16: return '+'; 	/* ASCII Code of '+' */

	default: return a_keyNumber;
	}
}
#endif
