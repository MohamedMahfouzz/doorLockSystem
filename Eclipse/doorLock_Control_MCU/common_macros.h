 /******************************************************************************
 *
 * 		Module: Common - Macros
 *
 * 	 File Name: common_macros.h
 *
 * Description: Commonly used Macros
 *
 * 		Author: Mohamed Mahfouz
 *
 * 	Created on: Nov 20, 2020
 *
 *******************************************************************************/

#ifndef COMMON_MACROS
#define COMMON_MACROS

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(HIGH<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(HIGH<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(HIGH<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (HIGH<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (HIGH<<BIT)) )

#endif
