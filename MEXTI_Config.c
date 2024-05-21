/*
 * MEXTI_Config.c
 *
 *  Created on: Apr 24, 2024
 *      Author: Ibrahim
 */



/*****************LIB*************************/
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"


/****************MCAL************************/
#include "../include/MCAL/MEXTI/MEXTI_Config.h"
#include "../include/MCAL/MEXTI/MEXTI_Interface.h"
#include "../include/MCAL/MEXTI/MEXTI_Private.h"


MEXTI_Configurations  MEXTI_Config[MEXTI_NUMBER] =
{
		{
				MEXTI_LINE0	,
				MEXTI_PORTB ,
				MEXTI_FALLING_EDGE ,
				MEXTI_ENABLED
		}

//		,
//		{
//				MEXTI_LINE1	,
//				MEXTI_PORTB ,
//				MEXTI_FALLING_EDGE ,
//				MEXTI_DISABLED
//		}
//		,
//		{
//				MEXTI_LINE2	,
//				MEXTI_PORTB ,
//				MEXTI_FALLING_EDGE ,
//				MEXTI_DISABLED
//		}

};



