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
extern int characterFlag;
extern uint8_t characterReceived;
#define CMD_BUFFER_SIZE 32
char cmdBuffer[CMD_BUFFER_SIZE];
int cmdIndex = 0;

// *************************************** Start of Main ***********************************

int main(void)
{
	clockInit();
	portEnable();
	pinConfigure();
	serial_open();
	message("This program lets you control the User led and query the state of the led.\r\n");
	message("To turn on the light, simply type 'ON'\r\n");
	message("To turn off the light, simply type 'OFF'\r\n");
	message("To get the status, simply type 'S'\r\n");
	message("For help, simply type 'H'\r\n");
	message("To quit, simply type 'Q'\r\n");
	message("To clear window, type 'C'\r\n");
	message("To scroll window, type 'W'\r\n");
	message("To Postion Cursor, type 'P'\r\n");
	message("> ");
	
	while (1)
	{
		if (characterFlag == 1) 
		{
			if (characterReceived == '\r')
			{
				message("\r\n");
				cmdBuffer[cmdIndex] = '\0';  // Null-terminate the command string
				processCommand(cmdBuffer);   // Process the buffered command
				cmdIndex = 0;                // Reset the buffer index for the next command
				message("\r\n> ");           // Print a new prompt line
			} 
			else 
			{
			// Buffer the received character
				if (cmdIndex < CMD_BUFFER_SIZE - 1) 
				{
				// Ensure we don't overrun the buffer
					cmdBuffer[cmdIndex++] = characterReceived;
				}
			}
			characterFlag = 0;
		}
	}
	return 0;
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
