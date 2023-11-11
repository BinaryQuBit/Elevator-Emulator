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
#include "string.h"

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

// *********************************** Messages to Serial **********************************
void message(const char* str)
{
	CLI_Transmit((uint8_t *)str, strlen(str));
}

// ********************************* Process the Commands **********************************

void processCommand(const char* cmd)
{
	if (strcmp(cmd, "1") == 0)
	{
		userLedOn(); // Turn on the LED
		message("LED ON");
	}
	else if (strcmp(cmd, "0") == 0)
	{
		userLedOff(); // Turn off the LED
		message("LED OFF");
	}
	else if (strcmp(cmd, "3") == 0)
	{
		speed = 200;
		message("Speed is 200");
	}
	else if (strcmp(cmd, "4") == 0)
	{
		speed = 400;
		message("Speed is 400");
	}
	else if (strcmp(cmd, "5") == 0)
	{
		speed = 800;
		message("Speed is 800");
	}
	else if (strcmp(cmd, "s") == 0 || strcmp(cmd, "S") == 0)
	{
		if (GPIOA->ODR & GPIO_ODR_ODR5)
		{
			message("LED status: ON");
		}
		else
		{
			message("LED status: OFF");
		}
	}
	else if (strcmp(cmd, "h") == 0 || strcmp(cmd, "H") == 0)
	{
		message("Available commands:\r\n"
		"1: Turn ON the LED\r\n"
		"0: Turn OFF the LED\r\n"
		"S: Check LED status\r\n"
		"3: Slow Speed of LED\r\n"
		"4: Faster Speed of LED\r\n"
		"5: Fastest Speed of LED\r\n"
		"H: Display this help\r\n"
		"Q: Quit\r\n"
		"C: Clear Window\r\n"
		"P: Position Cursor\r\n"
		"W: Scroll Window\r\n");
	}
	else if (strcmp(cmd, "q") == 0 || strcmp(cmd, "Q") == 0)
	{
		message("Thank you! Bye Now");
		serial_close();
	}
	else if (strcmp(cmd, "c") == 0 || strcmp(cmd, "C") == 0)
	{
		message("\x1b[2J"); // Clear screen command
	}
	else if (strcmp(cmd, "p") == 0 || strcmp(cmd, "P") == 0)
	{
		message("\x1b[0;0H"); // Reset cursor position command
	}
	else if (strcmp(cmd, "w") == 0 || strcmp(cmd, "W") == 0)
	{
		message("\x1b[10;r"); // Scroll command
	}
	else
	{
		message("Unknown command");
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