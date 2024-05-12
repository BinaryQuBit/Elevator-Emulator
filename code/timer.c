// ****************************************** timer.c **************************************
// Project: Elevator Simulation
// File: timer.c
// Class: ENEL 452 Lab Works
// Programmer: Amandip Padda
// SID: 200455829
// Description: The project is based on the STM32F103RB that is being used in ENEL 452 Labs.

// =========================================================================================
// **************************************** IMPORTANT **************************************
// Copyright (c) 2023. All rights reserved. 
// See the bottom of this file for the license terms.
// =========================================================================================

// *************************************** Header Files ************************************
#include "timer.h"

// ********************************** Time Elapsed on window *******************************
void updateTimer(void)
{
	initTimerForTIM3();
	NVIC_EnableIRQ(TIM3_IRQn);
}

// ********************************** Timer setup for window *******************************
void initTimerForTIM3(void)
{
	RCC_EnableTimerClock(3);
	TIM3->PSC = 35999;
	TIM3->ARR = 999;
	TIM3->DIER |= TIM_DIER_UIE;
	TIM3->CR1 |= TIM_CR1_CEN;
}

// **************************** Interrupt Handler for Window Timer *************************
void TIM3_IRQHandler(void)
{
	if (TIM3->SR & TIM_SR_UIF)
	{
		TIM3->SR &= ~TIM_SR_UIF;
		timeCounter++;
	}
}

// ******************************** Setting up EXTI Interrupt ******************************
void interruptPC13setup()
{
	RCC_SetGPIOClock('C', true);
	RCC_EnableAFIOClock();
	AFIO->EXTICR[3] |= AFIO_EXTICR4_EXTI13_PC;
	EXTI->IMR |= (1 << 13);
	EXTI->RTSR |= (1 << 13);
	EXTI->FTSR &= ~(1 << 13);
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	NVIC_SetPriority(EXTI15_10_IRQn, 1);
}

// **************************** Interrupt Handler for User Button **************************
void EXTI15_10_IRQHandler(void)
{
	if (EXTI->PR & (1 << 13))
	{
		if (buttonPressed == 0)
		{
			display("Emergency Stop                ", 18, 152);
			display("If Life Threatening, Call 911", 19, 144);
			serial_close();
			buttonPressed = 1;
		}
		else
		{
			serial_open();
			display("Emergency Stop                ", 18, 152);
			display("                              ", 19, 144);
			buttonPressed = 0;
		}
		EXTI->PR = (1 << 13);
	}
}

// =========================================================================================
// *****************************************IMPORTANT***************************************
// Copyright (c) 2016. All rights reserved.
// This library is free software; you can redistribute it and/or modify it under the terms 
// of the GNU Lesser General Public License as published by the Free Software Foundation; 
// either version 2.1 of the License, or (at your option) any later version. This library
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
// the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a copy of the GNU
// Lesser General Public License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
// ==========================================================================================