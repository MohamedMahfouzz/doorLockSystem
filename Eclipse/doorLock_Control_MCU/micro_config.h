 /******************************************************************************
 *
 * 		Module: Microcontroller - Configuration
 *
 * 	 File Name: micro_config.h
 *
 * Description: File to include all Microcontroller libraries
 *
 * 		Author: Mohamed Mahfouz
 *
 * 	Created on: Nov 20, 2020
 *
 *******************************************************************************/

#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_

/*******************************************************************************
 *							  INCLUDES	  	   		                           *
 *******************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#ifndef F_CPU
#define F_CPU 8000000UL /* 8MHz Clock frequency */
#endif  

#endif /* MICRO_CONFIG_H_ */
