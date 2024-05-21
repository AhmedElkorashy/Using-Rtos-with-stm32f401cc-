#include "../include/LIB/STD_TYPES.h"
#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCal/MRCC/MRCC_Interface.h"
#include "../include/MCAL/MNVIC/MNVIC_Interface.h"
#include "../include/MCAL/MEXTI/MEXTI_Interface.h"
#include "../include/MCAL/MSTK/STK_Interface.h"
#include "../include/MRTOS/RTOS_interface.h"
#include "../include/file.h"
u8 flag=0;
/********Task 1*********/
void Task_1 (void)
{
	if(flag==0)
	{
		MGPIO_voidTogglePinValue(GPIO_PORTA , GPIO_PIN0);
		RTOS_voidSuspendTask(2);
		flag=1;
	}
	else
	{
		MGPIO_voidTogglePinValue(GPIO_PORTA , GPIO_PIN0);
		RTOS_voidResumeTask(2);
		flag=0;
	}
}

/*******Task 2********/
void Task_2 (void)
{
	MGPIO_voidTogglePinValue(GPIO_PORTA , GPIO_PIN1);
}

/*******Task 2********/
void Task_3 (void)
{
	MGPIO_voidTogglePinValue(GPIO_PORTA , GPIO_PIN2);
}

void Task_Init(void)
{
	MRCC_voidInit();
	/**********************************************************/
	/*Peripherals Clock Enable*/
	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOA);

	/***************/
	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN0 , GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA , GPIO_PIN0 , GPIO_PUSH_PULL , GPIO_LOW_SPEED);
	for (u8 i = 0 ; i <3 ; i++)
	{
		MGPIO_voidSetPinMode(GPIO_PORTA , i , GPIO_OUTPUT);
		MGPIO_voidSetPinOutputMode(GPIO_PORTA , i , GPIO_PUSH_PULL , GPIO_LOW_SPEED);
	}
	RTOS_voidSuspendTask(0);
}
/************************************************************************/
/*							ENTRY POINT <main>							*/
/************************************************************************/
void main (void)
{
	/************Create RTOS Tasks***************/
	RTOS_u8CreateTask( 0 ,1000,0 ,TASK_RESUMED, &Task_Init) ;
	RTOS_u8CreateTask( 1 ,1000,1000 ,TASK_RESUMED, &Task_1) ;
	RTOS_u8CreateTask( 2 ,2000,2000,TASK_RESUMED ,&Task_2) ;
	RTOS_u8CreateTask( 3 ,1000,4000,TASK_RESUMED ,&Task_3) ;
	RTOS_voidInit() ;
	while (1);
}
