 /******************************************************************************
 *
 * 		Module: I2C
 *
 *	 File Name: i2c.h
 *
 * Description: Header file for I2C driver
 *
 * 		Author: Mohamed Mahfouz
 *
 *  Created on: Nov 23, 2020
 *
 *******************************************************************************/

#ifndef I2C_H_
#define I2C_H_

/*******************************************************************************
 *							  INCLUDES	  	   		                           *
 *******************************************************************************/

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Master transmit/receive status codes */
#define TWI_START 				0x08	/* Start status code */
#define TWI_REP_START 			0x10	/* Repeated start status code */
#define TWI_MT_SLA_W_ACK 		0X18	/* Master transmit SLA write with Acknowledge status code */
#define TWI_MT_SLA_W_NACK 		0X20	/* Master transmit SLA write with Not Acknowledge status code */
#define TWI_MT_DATA_ACK 		0x28	/* Master transmit data with Acknowledge status code */
#define TWI_MT_DATA_NACK 		0x30	/* Master transmit data with Not Acknowledge status code */
#define TWI_ARTBITRATION_LOST	0x38	/* Arbitration lost, master did not get bus */
#define TWI_MT_SLA_R_ACK		0x40	/* Master transmit SLA read with Acknowledge status code */
#define TWI_MT_SLA_R_NACK		0x48	/* Master transmit SLA read with Not Acknowledge status code */
#define TWI_MR_DATA_ACK			0x50	/* Master receive data with Acknowledge status code */
#define TWI_MR_DATA_NACK		0x58	/* Master receive data with Not Acknowledge status code */

/*******************************************************************************
 *							  ENUMS 	  	   		                           *
 *******************************************************************************/

/*******************************************************************************
 * [Enum Name]		: TWI_Prescaler
 * [Description]	: Enum for TWI prescaler values
 *******************************************************************************/
typedef enum
{
	ONE,			/* Prescaler of 1 */
	FOUR,			/* Prescaler of 4 */
	SIXTEEN,		/* Prescaler of 16 */
	SIXTY_FOUR		/* Prescaler of 64 */
}TWI_Prescaler;

/*******************************************************************************
 *						Structures & Unions	   		                           *
 *******************************************************************************/

/*******************************************************************************
 * [Structure Name]	: TWI_ConfigType
 * [Description]	: Struct responsible for TWI configuration
 *******************************************************************************/
typedef struct
{
	uint8 divisionFactor;		/* Division factor to control SCL frequency */
	uint8 slaveAddress;			/* Device address for contacting as a slave */
	TWI_Prescaler prescalar;	/* Pre-scalar to control bit rate affecting SCL frequency */
}TWI_ConfigType;

/*******************************************************************************
 *                      Function Declarations                                  *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]	: TWI_init
 * [Description]	: Initialize TWI peripheral
 * [Args]
 * 		[IN] const TWI_ConfigType * a_s_configuration_Ptr
 * 					: Pointer to structure containing TWI configuration
 *
 * [Returns]		: N/A
 *******************************************************************************/
void TWI_init(const TWI_ConfigType * a_s_configuration_Ptr);

/*******************************************************************************
 * [Function Name]	: TWI_start
 * [Description]	: Start new communication with another device
 * [Args]			: N/A
 * [Returns]		: N/A
 *******************************************************************************/
void TWI_start(void);

/*******************************************************************************
 * [Function Name]	: TWI_stop
 * [Description]	: Stop communication with another device
 * [Args]			: N/A
 * [Returns]		: N/A
 *******************************************************************************/
void TWI_stop(void);

/*******************************************************************************
 * [Function Name]	: TWI_write
 * [Description]	: Write data to TWDR to communicate to other device
 * [Args]
 * 		[IN] unsigned char a_data
 * 					: Data to send to other device
 *
 * [Returns]		: N/A
 *******************************************************************************/
void TWI_write(uint8 a_data);

/*******************************************************************************
 * [Function Name]	: TWI_readWithACK
 * [Description]	: Read data from TWDR received from other device and send ACK
 * [Args]			: N/A
 * [Returns]		: Data from TWDR
 *******************************************************************************/
uint8 TWI_readWithACK(void);

/*******************************************************************************
 * [Function Name]	: TWI_readWithNACK
 * [Description]	: Read data from TWDR received from other device and send NACK
 * [Args]			: N/A
 * [Returns]		: Data from TWDR
 *******************************************************************************/
uint8 TWI_readWithNACK(void);

/*******************************************************************************
 * [Function Name]	: TWI_getStatus
 * [Description]	: Get current device status
 * [Args]			: N/A
 * [Returns]		: Current bus status
 *******************************************************************************/
uint8 TWI_getStatus(void);

#endif /* I2C_H_ */
