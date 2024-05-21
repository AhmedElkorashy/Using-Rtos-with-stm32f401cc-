/*
 * MGPIO.c
 *
 *  Created on: Apr 22, 2024
 *      Author: sheri
 */

/************************************************************************/
/*							FILES INCLUSIONS							*/
/************************************************************************/
/*******************************LIB**************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"


/*******************************MCAL*************************************/
#include "../include/MCAL/MGPIO/MGPIO_Config.h"
#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MGPIO/MGPIO_Private.h"



void MGPIO_voidSetPinMode(u8 copyu8Port, u8 copyu8Pin, u8 copyu8Mode)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13)|| (copyu8Pin == GPIO_PIN14) || (copyu8Pin == GPIO_PIN15)))
	{
		/*DO NOTHING*/
	}
	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3)|| (copyu8Pin == GPIO_PIN4) ))
	{
		/*DO NOTHING*/
	}
	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			GPIOA->MODER &= ~(TWO_BIT_MASK<<(2*copyu8Pin));
			GPIOA->MODER |= (copyu8Mode<<(2*copyu8Pin));
			break;
		case GPIO_PORTB:
			GPIOB->MODER &= ~(TWO_BIT_MASK<<(2*copyu8Pin));
			GPIOB->MODER |= (copyu8Mode<<(2*copyu8Pin));
			break;
		case GPIO_PORTC:
			GPIOC->MODER &= ~(TWO_BIT_MASK<<(2*copyu8Pin));
			GPIOC->MODER |= (copyu8Mode<<(2*copyu8Pin));
			break;
		default:
			break;
		}

	}
}

void MGPIO_voidSetPinOutputMode(u8 copyu8Port, u8 copyu8Pin, u8 copyu8OutputMode, u8 copyu8Speed)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13)|| (copyu8Pin == GPIO_PIN14) || (copyu8Pin == GPIO_PIN15)))
	{
		/*DO NOTHING*/
	}
	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3)|| (copyu8Pin == GPIO_PIN4) ))
	{
		/*DO NOTHING*/
	}
	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			GPIOA->OSPEEDR &= ~(TWO_BIT_MASK<<(2*copyu8Pin));
			GPIOA->OSPEEDR |= (copyu8Speed<<(2*copyu8Pin));

			GPIOA->OTYPER &= ~(ONE_BIT_MASK<<(copyu8Pin));
			GPIOA->OTYPER |= (copyu8OutputMode<<(copyu8Pin));
			break;
		case GPIO_PORTB:
			GPIOB->OSPEEDR &= ~(TWO_BIT_MASK<<(2*copyu8Pin));
			GPIOB->OSPEEDR |= (copyu8Speed<<(2*copyu8Pin));

			GPIOB->OTYPER &= ~(ONE_BIT_MASK<<(copyu8Pin));
			GPIOB->OTYPER |= (copyu8OutputMode<<(copyu8Pin));
			break;
		case GPIO_PORTC:
			GPIOC->OSPEEDR &= ~(TWO_BIT_MASK<<(2*copyu8Pin));
			GPIOC->OSPEEDR |= (copyu8Speed<<(2*copyu8Pin));

			GPIOC->OTYPER &= ~(ONE_BIT_MASK<<(copyu8Pin));
			GPIOC->OTYPER |= (copyu8OutputMode<<(copyu8Pin));
			break;
		default:
			break;
		}
	}
}
void MGPIO_voidSetPinInputMode(u8 copyu8Port, u8 copyu8Pin, u8 copyu8InputMode)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Do Nothing*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Do Nothing*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			GPIOA->PUPDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOA->PUPDR |= (copyu8InputMode<<(copyu8Pin *2));
			break;

		case GPIO_PORTB:
			GPIOB->PUPDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOB->PUPDR |= (copyu8InputMode<<(copyu8Pin *2));
			break;

		case GPIO_PORTC:
			GPIOC->PUPDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOC->PUPDR |= (copyu8InputMode<<(copyu8Pin *2));
			break;

		default:
			break;
		}
	}
}

void MGPIO_voidSetPinValue(u8 copyu8Port, u8 copyu8Pin, u8 copyu8Output)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Do Nothing*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Do Nothing*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			switch(copyu8Output)
			{
			case GPIO_PIN_HIGH:
				SET_BIT(GPIOA->ODR , copyu8Pin);
				break;

			case GPIO_PIN_LOW:
				CLR_BIT(GPIOA->ODR , copyu8Pin);
				break;

			default:
				break;
			}
			break;

			case GPIO_PORTB:
				switch(copyu8Output)
				{
				case GPIO_PIN_HIGH:
					SET_BIT(GPIOB->ODR , copyu8Pin);
					break;

				case GPIO_PIN_LOW:
					CLR_BIT(GPIOB->ODR , copyu8Pin);
					break;

				default:
					break;
				}
				break;

				case GPIO_PORTC:
					switch(copyu8Output)
					{
					case GPIO_PIN_HIGH:
						SET_BIT(GPIOC->ODR , copyu8Pin);
						break;

					case GPIO_PIN_LOW:
						CLR_BIT(GPIOC->ODR , copyu8Pin);
						break;

					default:
						break;
					}
					break;

					default:
						break;
		}
	}
}

void MGPIO_voidSetPortValue(u8 copyu8Port, u8 copyu16Output)
{

	switch(copyu8Port)
	{
	case GPIO_PORTA:
		GPIOA->ODR &= (~(0xFF));
		GPIOA->ODR |= (copyu16Output );
		break;

	case GPIO_PORTB:
		GPIOB->ODR &= (~(0xFF));
		GPIOB->ODR |= (copyu16Output );
		break;

	case GPIO_PORTC:
		GPIOC->ODR &= (~(0xFF));
		GPIOC->ODR |= (copyu16Output );
		break;

	default:
		break;
	}
}
void MGPIO_voidGetPinValue(u8 copyu8Port, u8 copyu8Pin, u8* pu8Return)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Do Nothing*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Do Nothing*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			*pu8Return = GET_BIT(GPIOA->IDR ,copyu8Pin);
			break;

		case GPIO_PORTB:
			*pu8Return = GET_BIT(GPIOB->IDR ,copyu8Pin);
			break;

		case GPIO_PORTC:
			*pu8Return = GET_BIT(GPIOC->IDR ,copyu8Pin);
			break;

		default:
			break;
		}
	}
}


void MPGIO_voidSetRestPin(u8 copyu8Port, u8 copyu8Pin, u8 copyu8SetResetValue)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Do Nothing*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Do Nothing*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			switch(copyu8SetResetValue)
			{
			case GPIO_SET:
				GPIOA->BSRR = (1 <<copyu8Pin);
				break;

			case GPIO_RESET:
				GPIOA->BSRR = (1 <<(copyu8Pin +16));
				break;

			default:
				break;
			}
			break;

			case GPIO_PORTB:
				switch(copyu8SetResetValue)
				{
				case GPIO_SET:
					GPIOB->BSRR = (1 <<copyu8Pin);
					break;

				case GPIO_RESET:
					GPIOB->BSRR = (1 <<(copyu8Pin +16));
					break;

				default:
					break;
				}
				break;

				case GPIO_PORTC:
					switch(copyu8SetResetValue)
					{
					case GPIO_SET:
						GPIOC->BSRR = (1 <<copyu8Pin);
						break;

					case GPIO_RESET:
						GPIOC->BSRR = (1 <<(copyu8Pin +16));
						break;

					default:
						break;
					}
					break;

					default:
						break;
		}
	}
}
void MGPIO_voidSerPortMode(u8 copyu8Port, u32 copyu8mode)
{
	switch (copyu8Port)
	{
	case GPIO_PORTA:
		GPIOA->MODER = (copyu8mode);
		break;
	case GPIO_PORTB:
		GPIOB->MODER = (copyu8mode);
		break;
	case GPIO_PORTC:
		GPIOC->MODER = (copyu8mode);
		break;
	default :
		break;

	}
}
void MPGIO_voidTogglePin(u8 copyu8Port, u8 copyu8Pin)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
			{
				/*Do Nothing*/
			}

			else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
			{
				/*Do Nothing*/
			}

		else
		{
			switch(copyu8Port)
			{
			case GPIO_PORTA:
				TOG_BIT(GPIOA->ODR,copyu8Pin);
				break;

			case GPIO_PORTB:
				TOG_BIT(GPIOB->ODR,copyu8Pin);
				break;

			case GPIO_PORTC:
				TOG_BIT(GPIOC->ODR,copyu8Pin);
				break;

			default:
				break;
			}
		}
}

void MGPIO_voidSetAF(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8AlternateFunctionNo)
{
	switch (copy_u8PORT)
	{
	case GPIO_PORTA:
		if (copy_u8PIN<8)
		{
			GPIOA->AFRL |= (copy_u8AlternateFunctionNo<<(copy_u8PIN*4));
		}
		else
		{
			GPIOA->AFRH |= (copy_u8AlternateFunctionNo<<((copy_u8PIN-8)*4));
		}
		break;
	case GPIO_PORTB:
		if (copy_u8PIN<8)
		{
			GPIOB->AFRL |= (copy_u8AlternateFunctionNo<<(copy_u8PIN*4));
		}
		else
		{
			GPIOB->AFRH |= (copy_u8AlternateFunctionNo<<((copy_u8PIN-8)*4));
		}
		break;
	case GPIO_PORTC:
		if (copy_u8PIN<8)
		{
			GPIOC->AFRL |= (copy_u8AlternateFunctionNo<<(copy_u8PIN*4));
		}
		else
		{
			GPIOC->AFRH |= (copy_u8AlternateFunctionNo<<((copy_u8PIN-8)*4));
		}
		break;
	}
}
