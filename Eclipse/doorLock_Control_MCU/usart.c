/******************************************************************************
 *
 * 		Module: USART
 *
 *	 File Name: usart.c
 *
 * Description: Source file for USART driver
 *
 * 		Author: Mohamed Mahfouz
 *
 *  Created on: Nov 22, 2020
 *
 *******************************************************************************/

/*******************************************************************************
 *							  INCLUDES	  	   		                           *
 *******************************************************************************/

#include "usart.h"

/*******************************************************************************
 *                      Global Variables                              	   	   *
 *******************************************************************************/

uint8 g_receiveStringFlag = 0;	/* Flag for receiving string using USART */
uint8 g_recievedData;			/* Variable to receive single bytes using USART */

/*******************************************************************************
 *                      Function Definitions                                   *
 *******************************************************************************/

/*******************************************************************************
 * [ISR Name]		: USART_RXC_vect
 * [Description]	: ISR to appropriately handle data received through USART
 * [Args]			: N/A
 * [Returns]		: N/A
 *******************************************************************************/
ISR(USART_RXC_vect){
	g_recievedData = UDR;			/* Store data received in a global variable */
	if (g_recievedData == '~'){		/* Check if data received is a String */
		g_receiveStringFlag = 1;	/* Raise the String flag */
	}
}

/*******************************************************************************
 * [Function Name]	: USART_init
 * [Description]	: Initialize USART peripheral
 * [Args]
 * 		[IN] const Usart_ConfigType * a_s_configuration_Ptr
 * 					: Pointer to structure containing USART configuration
 *
 * [Returns]		: N/A
 *******************************************************************************/
void USART_init(const Usart_ConfigType * a_s_configuration_Ptr){

	//TODO: I need a better way to represent these multi-bit configurations

	/*
	 * RXC: 	USART Receive Complete 					-> (Read Only)
	 * TXC=	0 	USART Transmit Complete					-> Transmit flag is not used
	 * UDRE:  	USART Data Register Empty 				-> (Read Only)
	 * FE:		Frame Error 							-> (Read Only)
	 * DOR: 	Data OverRun 							-> (Read Only)
	 * PE:		Parity Error 							-> (Read Only)
	 * U2X= 1	USART Double Transmission Speed			-> Activate double speed transmission mode
	 * MPCM= 0	Multi-processor Communication Mode		-> Un-need for single processor
	 */
	UCSRA = (HIGH << U2X);

	/*
	 * RXCIE= 1	RX Complete Interrupt Enable				-> Enable receive INT
	 * TXCIE= 0 TX Complete Interrupt Enable				-> Disable transmit INT
	 * UDRIE= 0 USART Data Register Empty Interrupt Enable	-> Disable data register empty INT
	 * RXEN= 1 	Receiver Enable								-> Enable RX pin on MCU
	 * TXEN= 1	Transmitter Enable							-> Enable TX pin on MCU
	 * UCSZ2: 	Character Size								-> Character size control from configuration provided
	 * RXB8: 	Receive Data Bit 8							-> (Read Only)
	 * TXB8: 	Transmit Data Bit 8							-> Bit 8 for 9 bit mode
	 */
	UCSRB = (1<<RXEN) | (HIGH << TXEN) |
			(((a_s_configuration_Ptr->charSize & 4) >> 2) << UCSZ2);

	/*
	 * URSEL= 1	Register Select		-> Set to one to access UCSRC register
	 * UMSEL= 0 USART Mode Select	-> Activate in Async mode
	 * UPM1:0: 	Parity Mode			-> Parity control from configuration provided
	 * USBS: 	Stop Bit Select		-> Stop bit control from configuration provided
	 * UCSZ1:0: Character Size		-> Character size control from configuration provided
	 * UCPOL= 0	Clock Polarity		-> Not needed for Async mode
	 */
	UCSRC = (HIGH << URSEL) |
			((a_s_configuration_Ptr->parity) << UPM0) |
			(a_s_configuration_Ptr->stopBit << USBS)|
			((a_s_configuration_Ptr->charSize & 3) << UCSZ0);	//TODO:Sync or Async, hal3ab feiha?

	/* Calculate UBRR value according to input Baud and MCU frequency */
	uint16 UBRR = UBRR(F_CPU, a_s_configuration_Ptr->baudRate);

	/*
	 * URSEL= 0		Register Select				-> Set to zero to access UBRRH register
	 * BIT14:12:	Reserved bits				-> (Read Only)
	 * UBRR11:0:	USART Baud Rate Register	-> Set Baud Rate according to calculated value
	 */
	UBRRH = (uint8)(UBRR >> 8);
	UBRRL = (uint8)UBRR;
}

/*******************************************************************************
 * [Function Name]	: USART_sendByte
 * [Description]	: Send byte using USART
 * [Args]
 * 		[IN] const unsigned char a_data
 * 					: Byte to send to other device
 *
 * [Returns]		: N/A
 *******************************************************************************/
void USART_sendByte(const uint8 a_data){
	//TODO: Adjust for 9 bits
	/* Wait for UDRE flag to be set before writing data for transmission */
	while(BIT_IS_CLEAR(UCSRA, UDRE));
	/* Write data to UDR to send using USART */
	UDR = a_data;
}

/*******************************************************************************
 * [Function Name]	: USART_receiveByte
 * [Description]	: Receive byte through USART
 * [Args]			: N/A
 * [Returns]		: Byte received from other device
 *******************************************************************************/
uint8 USART_receiveByte(void){

	/* Wait for RXC flag to be set before reading data received */
	while(BIT_IS_CLEAR(UCSRA, RXC));
	/* Read data currently in UDR */
	return UDR;
}

/*******************************************************************************
 * [Function Name]	: USART_sendString
 * [Description]	: Send string using USART
 * [Args]
 * 		[IN] const unsigned char *a_string_Ptr
 * 					: String to send to other device
 *
 * [Returns]		: N/A
 *******************************************************************************/
void USART_sendString(const uint8 *a_string_Ptr){
	/* Send String start symbol */
//	USART_sendByte('~');
	/* Pass by String characters until we reach null terminator */
	while (*a_string_Ptr != '\0'){
		/* Send current character in String */
		USART_sendByte(*a_string_Ptr++);
	}
	/* Send null terminator for String */
	USART_sendByte('\0');
}

/*******************************************************************************
 * [Function Name]	: USART_receiveString
 * [Description]	: Receive string through USART
 * [Args]
 * 		[OUT] unsigned char *a_string_Ptr
 * 					: String to receive from other device
 *
 * [Returns]		: N/A
 *******************************************************************************/
void USART_receiveString(uint8 *a_string_Ptr){
	/* iterator to save string in a_string_Ptr */
	uint8 charNum = 0;
	/* Pass by String characters until we reach null terminator */
	do {
		/* Save character received to the string provided */
		a_string_Ptr[charNum++] = USART_receiveByte();
	/* Keep Passing until string last character is null terminator */
	}while(a_string_Ptr[charNum-1] != '\0');
}
