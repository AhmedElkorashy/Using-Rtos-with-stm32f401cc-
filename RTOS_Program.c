/*
 * RTOS_Program.c
 *
 *  Created on: 2024-04-30
 *      Author: Mahmoud Elrashedy
 */

// Source content for module RTOS




/************************************************************************/
/*							FILES INCLUSIONS							*/
/************************************************************************/
/*******************************LIB**************************************/
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"


/*******************************MCAL*************************************/
#include "../include/MCAL/MSYSTICK/MSYSTICK_Interface.h"

#include "../include/SERVICE/RTOS/RTOS_Config.h"
#include "../include/SERVICE/RTOS/RTOS_Interface.h"
#include "../include/SERVICE/RTOS/RTOS_Private.h"



/**************************Functions Definitions***********************/


TCB_t TasksArray[MAX_TASK_NUM] = {NULL} ;

void RTOS_voidInit (void)
{
	STK_voidInit() ;
	STK_voidSetPeriodicInterval(RTOS_TICK , &RTOS_voidScheduler) ;
}

void RTOS_voidCreateTask( u8 copy_u8Priority , u16 copy_u16Periodicity , u32 copy_u32FirstDelay ,void (*copy_pvTaskFunc)(void))
{
	TasksArray[copy_u8Priority].T_FD = copy_u32FirstDelay ;
	TasksArray[copy_u8Priority].T_priodicity = copy_u16Periodicity ;
	TasksArray[copy_u8Priority].T_ptr = copy_pvTaskFunc ;
	TasksArray[copy_u8Priority].T_state = TASK_RESUMED ;

}


void RTOS_voidDeleteTask (u8 copy_u8Priority)
{
	TasksArray[copy_u8Priority].T_ptr = NULL ;
	TasksArray[copy_u8Priority].T_state = TASK_DELETED ;
}


void RTOS_voidResumeTask (u8 copy_u8Priority)
{
	TasksArray[copy_u8Priority].T_state = TASK_RESUMED ;
}
void RTOS_voidSuspendTask (u8 copy_u8Priority)
{
	TasksArray[copy_u8Priority].T_state = TASK_SUSPENDED ;
}

static void RTOS_voidScheduler (void)
{
	static u32 Local_u32Counter = 0 ;
	Local_u32Counter++ ;
	for (u8 i = 0 ; i < MAX_TASK_NUM ; i++)
	{
		if (TasksArray[i].T_state == TASK_RESUMED)
		{
			if ( TasksArray[i].T_FD == 0 )
			{
				TasksArray[i].T_ptr() ;
				TasksArray[i].T_FD = TasksArray[i].T_priodicity -1 ;
			}
			else
			{
				TasksArray[i].T_FD -- ;
			}
		}
	}
}




























