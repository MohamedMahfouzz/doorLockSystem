/******************************************************************************
 *
 * 		Module: USART
 *
 *	 File Name: usart.h
 *
 * Description: Header file for USART driver
 *
 * 		Author: Mohamed Mahfouz
 *
 *  Created on: Nov 22, 2020
 *
 *******************************************************************************/

#ifndef USART_H_
#define USART_H_

/*******************************************************************************
 *							  INCLUDES	  	   		                           *
 *******************************************************************************/

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

/*******************************************************************************
 *                      Global Variables                              	   	   *
 *******************************************************************************/

extern uint8 g_receiveStringFlag;	/* Flag for receiving string using USART */
extern uint8 g_recievedData;		/* Variable to receive single bytes using USART */

/*******************************************************************************
 *							  ENUMS 	  	   		                           *
 *******************************************************************************/

/*******************************************************************************
 * [Enum Name]		: Usart_CharacterSize
 * [Description]	: Enum for USART character size configuration
 *******************************************************************************/
typedef enum
{
	FIVE_BITS,		/* Character size of 5 bits */
	SIX_BITS,		/* Character size of 6 bits */
	SEVEN_BITS,		/* Character size of 7 bits */
	EIGHT_BITS,		/* Character size of 8 bits */
	NINE_BITS=7		/* Character size of 9 bits */
}Usart_CharacterSize;

/*******************************************************************************
 * [Enum Name]		: Usart_BaudRate
 * [Description]	: Enum for USART baud rate configuration
 *******************************************************************************/
typedef enum
{
	BAUD_RATE_2400 = 2400,		/* Baud rate of 2400 */
	BAUD_RATE_4800 = 4800,		/* Baud rate of 4800 */
	BAUD_RATE_9600 = 9600,		/* Baud rate of 9600 */
	BAUD_RATE_14400 = 14400,	/* Baud rate of 14400 */
	BAUD_RATE_19200 = 19200,	/* Baud rate of 19200 */
	BAUD_RATE_28800 = 28800,	/* Baud rate of 28800 */
	BAUD_RATE_38400 = 38400, 	/* Baud rate of 38400 */
	BAUD_RATE_57600 = 57600,	/* Baud rate of 57600 */
	BAUD_RATE_76800 = 76800,	/* Baud rate of 76800 */
	BAUD_RATE_115200 = 115200	/* Baud rate of 115200 */
}Usart_BaudRate;

/*******************************************************************************
 * [Enum Name]		: Usart_Parity
 * [Description]	: Enum for USART parity configuration
 *******************************************************************************/
typedef enum
{
	DISABLED,			/* Disable UART parity check bit */
	EVEN_PARITY = 2,	/* Enable UART even parity check bit */
	ODD_PARITY			/* Enable UART odd parity check bit */
}Usart_Parity;

/*******************************************************************************
 * [Enum Name]		: Usart_StopBit
 * [Description]	: Enum for USART stop bit configuration
 *******************************************************************************/
typedef enum
{
	ONE_BIT,	/* Send 1 stop bit to finish sending */
	TWO_BITS	/* Send 2 stop bit to finish sending */
}Usart_StopBit;

/*******************************************************************************
 *						Structures & Unions	   		                           *
 *******************************************************************************/

/*******************************************************************************
 * [Structure Name]	: Usart_ConfigType
 * [Description]	: Struct responsible for USART configuration
 *******************************************************************************/
typedef struct
{
	Usart_BaudRate baudRate			: 17;	/* Baud Rate for USART */
	uint32 							: 2;	/* Padding */
	Usart_CharacterSize charSize 	: 3;	/* Character Size for sending */
	uint32 							: 2;	/* Padding */
	Usart_Parity parity				: 2;	/* Parity control */
	uint32 							: 2;	/* Padding */
	Usart_StopBit stopBit			: 1;	/* Stop bit control */
	uint32		 					: 3;	/* Padding */
}Usart_ConfigType;

/*******************************************************************************
 *                      Function-like Macros                                   *
 *******************************************************************************/

/*******************************************************************************
 * [Macro Name]		: UBRR
 * [Description]	: Returns correct UBRR value for USART configuration using
 * 					  the MCU frequency and chosen baud rate
 * [Args]
 * 		[IN] F_CPU
 * 					: MCU specified working frequency
 * 		[IN] enum BAUD
 * 					: Baud rate specified in configuration
 *
 * [Returns]		: UBRR value for double speed AVR USART peripheral
 *******************************************************************************/
#define UBRR(F_CPU, BAUD) (((F_CPU)/((8UL)*(BAUD)))-1)

/*******************************************************************************
 *                      Function Declarations                                  *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]	: USART_init
 * [Description]	: Initialize USART peripheral
 * [Args]
 * 		[IN] const Usart_ConfigType * a_s_configuration_Ptr
 * 					: Pointer to structure containing USART configuration
 *
 * [Returns]		: N/A
 *******************************************************************************/
void USART_init(const Usart_ConfigType * a_s_configuration_Ptr);

/*******************************************************************************
 * [Function Name]	: USART_sendByte
 * [Description]	: Send byte using USART
 * [Args]
 * 		[IN] const unsigned char a_data
 * 					: Byte to send to other device
 *
 * [Returns]		: N/A
 *******************************************************************************/
void USART_sendByte(const uint8 a_data);

/*******************************************************************************
 * [Function Name]	: USART_receiveByte
 * [Description]	: Receive byte through USART
 * [Args]			: N/A
 * [Returns]		: Byte received from other device
 *******************************************************************************/
uint8 USART_receiveByte(void);

/*******************************************************************************
 * [Function Name]	: USART_sendString
 * [Description]	: Send string using USART
 * [Args]
 * 		[IN] const unsigned char *a_string_Ptr
 * 					: String to send to other device
 *
 * [Returns]		: N/A
 *******************************************************************************/
void USART_sendString(const uint8 *a_string_Ptr);

/*******************************************************************************
 * [Function Name]	: USART_receiveString
 * [Description]	: Receive string through USART
 * [Args]
 * 		[OUT] unsigned char *a_string_Ptr
 * 					: String to receive from other device
 *
 * [Returns]		: N/A
 *******************************************************************************/
void USART_receiveString(uint8 *a_string_Ptr);

#endif /* USART_H_ */
