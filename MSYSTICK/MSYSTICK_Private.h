/*
 * MSYSTICK_private.h
 *
 *  Created on: 2024-04-29
 *      Author: Mahmoud Elrashedy
 */

#ifndef MSYSTICK_PRIVATE_H_
#define MSYSTICK_PRIVATE_H_

#define STK_BASE_ADDRESS	0xE000E010

typedef struct
{
	u32 CTRL ;
	u32 LOAD ;
	u32 VAL ;
}STK_t ;

#define STK ((volatile STK_t*) STK_BASE_ADDRESS )

/******************STK_CTRL Bits********************/
#define STK_ENABLE		0
#define STK_TICKINT		1
#define STK_CLKSOURCE	2
#define STK_COUNTFLAG	16


#define AHB		1
#define AHB_8	2

#define SINGLE  	1
#define PERIODIC 	2
#endif /* MSYSTICK_PRIVATE_H_*/
