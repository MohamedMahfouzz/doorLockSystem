 /******************************************************************************
 *
 * 		Module: External EEPROM
 *
 *	 File Name: external_eeprom.h
 *
 * Description: Header file for External EEPROM memory
 *
 * 		Author: Mohamed Mahfouz
 *
 *  Created on: Nov 24, 2020
 *
 *******************************************************************************/

#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

/*******************************************************************************
 *							  INCLUDES	  	   		                           *
 *******************************************************************************/

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Success and Error codes */
#define SUCCESS 1
#define ERROR 	0

/*******************************************************************************
 *                      Function Declarations                                  *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]	: EEPROM_init
 * [Description]	: Initialize the external EEPROM memory
 * [Args]			: N/A
 * [Returns]		: N/A
 *******************************************************************************/
void EEPROM_init(void);

/*******************************************************************************
 * [Function Name]	: EEPROM_writeByte
 * [Description]	: Write a byte to memory at specified address
 * [Args]
 * 		[IN] unsigned short a_address
 * 					: Memory address to access
 * 		[IN] unsigned char a_data
 * 					: Data to right in memory
 *
 * [Returns]		: Operation success/failure
 *******************************************************************************/
uint8 EEPROM_writeByte(uint16 a_address, uint8 a_data);

/*******************************************************************************
 * [Function Name]	: EEPROM_readByte
 * [Description]	: Read a byte from memory at specified address
 * [Args]
 * 		[IN] unsigned short a_address
 * 					: Memory address to access
 * 		[IN] unsigned char * a_data_Ptr
 * 					: Variable to read data into
 *
 * [Returns]		: Operation success/failure
 *******************************************************************************/
uint8 EEPROM_readByte(uint16 a_address, uint8 *a_data_Ptr);

/*******************************************************************************
 * [Function Name]	: EEPROM_writeString
 * [Description]	: Write a string to memory starting at the specified address
 * [Args]
 * 		[IN] unsigned short a_address
 * 					: Memory address to access
 * 		[IN] const unsigned char * a_string_Ptr
 * 					: String to write in memory
 *
 * [Returns]		: Operation success/failure
 *******************************************************************************/
uint8 EEPROM_writeString(uint16 a_address, const uint8 *a_string_Ptr);

#endif /* EXTERNAL_EEPROM_H_ */
