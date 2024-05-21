/*
 * SDELAY_Config.h
 *
 *  Created on: Apr 30, 2024
 *      Author: sakr3
 */

#ifndef SDELAY_CONFIG_H_
#define SDELAY_CONFIG_H_




/* CLK src (AHB Or AHB/8) */
/* Options
 * 1- SYSTICK_AHB_PRESCALER_BY_1
 * 2- SYSTICK_AHB_PRESCALER_BY_8
 * */

#define CLK_SRC				SYSTICK_AHB_PRESCALER_BY_8


/* Calculate clock which used in the systick */
#if CLK_SRC == SYSTICK_AHB_PRESCALER_BY_1
#define SYSTEM_CLOCK		16000000UL
#elif CLK_SRC == SYSTICK_AHB_PRESCALER_BY_8
#define SYSTEM_CLOCK		2000000UL
#endif

#endif /* SDELAY_CONFIG_H_ */
