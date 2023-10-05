// ************************************** functions.cpp ************************************
// Project: CLI on the Target
// File: functions.cpp
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
#include "stm32f10x.h"
#include "header.h"
#include <cstring> // for strlen

// **************************** Function defination to User LED Test ***********************
void ledTest(void)
{
	GPIOA->ODR |= GPIO_ODR_ODR5;
	delay(1000);
	GPIOA->ODR &= ~GPIO_ODR_ODR5;
	delay(1000);
}

// ************************************** Delay Function ***********************************
void delay(int a)
{
	unsigned volatile int c, d; 
	for (c = 1; c <= a; c++)
	{
		for (d = 1; d <= a; d++)
		{}
	}
}

// ************************************* Turn User LED ON **********************************
void userLedOn(void)
{
	GPIOA->ODR |= GPIO_ODR_ODR5;
}

// ************************************ Turn User LED OFF **********************************
void userLedOff(void)
{
	GPIOA->ODR &= ~GPIO_ODR_ODR5;
}

// ************************************* Initial Messages **********************************
void message(char messages[])
{
	CLI_Transmit((uint8_t*)messages, strlen(messages));
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
