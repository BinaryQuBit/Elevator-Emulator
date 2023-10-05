// ***************************************** main.cpp **************************************
// Project: CLI on the Target
// File: main.cpp
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

// *************************************** Start of Main ***********************************

int main(void)
{
	clockInit();
	portEnable();
	pinConfigure();
	serial_open();
	message("This program lets you control the User led and query the state of the led.\r\n");
	message("To turn on the light, simply type '1'\r\n");
	message("To turn off the light, simply type '0'\r\n");
	message("To get the status, simply type 'S'\r\n");
	message("For help, simply type 'H'\r\n");
	message("To quit, simply type 'Q'\r\n");
	message("> ");
	
// Buffer to hold Received Data
	uint8_t buffer[128];
	
	while (1)
	{
// Received Data anytime
		CLI_Receive(buffer, 128);

// Check if received character is '1' and no other character. Only at buffer 0
		if (buffer[0] == '1' && strlen((char*)buffer) == 1)
		{
			userLedOn();
			message("\r\n\LED is ON\r\n");
			message("> ");
		}

// Check if received character is '0' and no other character. Only at buffer 0
		else if (buffer[0] == '0' && strlen((char*)buffer) == 1)
		{
			userLedOff();
			message("\r\n\LED is OFF\r\n");
			message("> ");
		}

// Check if received character is 's' or 'S' and no other character. Only at buffer 0
		else if (buffer[0] == 'S' || buffer[0] == 's' && strlen((char*)buffer) == 1)
		{
			if(GPIOA->IDR & GPIO_IDR_IDR5)
			{
				message("\r\n\Status: LED is ON\r\n");
				message("> ");
			}
			else
			{
				message("\r\n\Status: LED is OFF\r\n");
				message("> ");
			}
		}
	
// Check if received character is 'h' or 'H' and no other character. Only at buffer 0
	else if ((buffer[0] == 'H' || buffer[0] == 'h') && strlen((char*)buffer) == 1)
	{
		message("\r\n");
		message("Enter 1: To turn on LED\r\n");
		message("Enter 0: To turn off LED\r\n");
		message("Enter S: To check the status of LED\r\n");
		message("Enter H: For Help\r\n");
		message("Enter Q: To Quit\r\n");
		message("> ");
	}
	
// Check if received character is 'q' or 'Q' and no other character. Only at buffer 0
		else if (buffer[0] == 'Q' || buffer[0] == 'q' && strlen((char*)buffer) == 1)
		{
			userLedOff();
			message("\r\n\Thank you for using this program\r\n\Bye Now!!\r\n");
			serial_close();
			break;
		}

// Check for invalid characters
		else
		{
			message("\r\n\Invalid Entry!\r\n");
			message("> ");
		}
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
