/*
 * MSYSTICK_Interface.h
 *
 *  Created on: 2024-04-29
 *      Author: Mahmoud Elrashedy
 */

#ifndef MSYSTICK_INTERFACE_H_
#define MSYSTICK_INTERFACE_H_

/**********************Functions Prototypes**************************/
void STK_voidInit (void) ;
void STK_voidSetBusyWait (u32 copy_u32Ticks) ;
void STK_voidDelay_ms_ (u16 copy_u16TimeDelay) ;
void STK_voidSetSingleInterval (u32 copy_u32Ticks , PtrToFunc_void PtrToFunc) ;
void STK_voidSetPeriodicInterval (u32 copy_u32Ticks , PtrToFunc_void PtrToFunc) ;
u32 STK_u32GetElapsedTime (void) ;
u32 STK_u32GetRemainingTIme (void) ;
/********************************************************************/
#endif /* MSYSTICK_INTERFACE_H_*/
