// **************************************** tasking.c **************************************
// Project: Elevator Simulation
// File: tasking.c
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
#include "tasking.h"

// ****************************** Task to update status message ****************************
void status(void *pvParameters)
{
	while(1)
	{
		setTextColor(34);
		char buffer[50];
		int len = sprintf(buffer, "\x1b[18;152H%s", statusMessage);
		CLI_Transmit((uint8_t*)buffer, strlen(buffer));
		message("\033[u");
		vTaskDelay(200);
	}
}

// ********************************** Task to update Floors ********************************
void floorStatus(void *pvParameters)
{
	while(1)
	{
		setTextColor(34);
		char buffer[20];
		int len = sprintf(buffer, "\x1b[17;151H%u", floorNumber);
		CLI_Transmit((uint8_t*)buffer, strlen(buffer));
		message("\033[u");
		vTaskDelay(200);
	}
}

// *********************************** Task to update Time ********************************
void timeElapsed(void *pvParameters)
{
	while(1)
	{
		setTextColor(34);
		char buffer[80];
		int len = sprintf(buffer, "\x1b[16;158H%lu seconds", timeCounter);
		CLI_Transmit((uint8_t*)buffer, strlen(buffer));
		message("\033[u");
		vTaskDelay(200);
	}
}

// ******************************* Task to handle user input ******************************
void TaskHandleUserInput(void *pvParameters)
{
	sendPromptArrows();
	message("\033[s");
	while (1)
	{
		if (characterFlag == 1)
		{
			message("\033[s");
			if (characterReceived == '\r')
			{
				currentRow++;
				message("\033[s");
				if (currentRow > MAX_ROW)
				{
					clearScreenFromRow(24);
					setCursorPosition(24, 4);
					message("\033[s");
				}
				sendPromptArrows();
				cmdBuffer[cmdIndex] = '\0';
				char *cmdCopy = newMemory(cmdBuffer);
				if (cmdCopy)
				{
					xQueueSend(xCommandQueue, &cmdCopy, portMAX_DELAY);
				}
				cmdIndex = 0;
			}
			else
			{
				if (cmdIndex < CMD_BUFFER_SIZE - 1)
				{
					cmdBuffer[cmdIndex++] = characterReceived;
				}
			}
			characterFlag = 0;
		}
		vTaskDelay(1);
	}
}

// ****************************** Task to update visual floors ****************************
void draw(void *pvParameters)
{
	unsigned int activeColor = 34;
	unsigned int inactiveColor = 33;
	uint8_t cmd;
	while(1)
	{
		if (xQueueReceive(xDrawQueue, &cmd, portMAX_DELAY) == pdPASS)
		{
			drawFirst(1, cmd == 1 ? activeColor : inactiveColor);
			drawSecond(2, cmd == 2 ? activeColor : inactiveColor);
			drawThird(3, cmd == 3 ? activeColor : inactiveColor);
			drawForth(4, cmd == 4 ? activeColor : inactiveColor);
			drawFifth(5, cmd == 5 ? activeColor : inactiveColor);
		}
		vTaskDelay(1);
	}
}

// ******************************* Task Process the commands ******************************
void TaskProcessCommand(void *pvParameters)
{
	char *cmd;
	while(1)
	{
		if (xQueueReceive(xCommandQueue, &cmd, portMAX_DELAY) == pdPASS)
		{
			processCommand(cmd);
			vPortFree(cmd);
		}
		vTaskDelay(1);
	}
}

// ********************************* Moving Elevator Logic ********************************
void moveElevatorToFloor(unsigned int targetFloor)
{
	if (floorNumber == targetFloor)
	{
		statusMessage = "Already on the requested floor";
		return;
	}
	statusMessage = "Moving...                     ";
	while (floorNumber != targetFloor)
	{
		delay(2000);
		if (floorNumber < targetFloor)
		{
			floorNumber++;
		}
		else if (floorNumber > targetFloor)
		{
			floorNumber--;
		}
		uint8_t floorNumberToSend = (uint8_t)floorNumber;
		xQueueSend(xDrawQueue, &floorNumberToSend, portMAX_DELAY);
		char floorStatusMsg[300];
		sprintf(floorStatusMsg, "Passing Floor %u               ", floorNumber);
		statusMessage = floorStatusMsg;
	}
	statusMessage = "Door opening...               ";
	delay(2000);
	char mng[300];
	sprintf(mng, "You have arrived at Floor %u   ", floorNumber);
	statusMessage = mng;
	delay(2000);
	statusMessage = "Door closing...               ";
	delay(2000);
	statusMessage = "Idle                          ";
}

// ******************************** Processing Command Logic ******************************
void processCommand(const char* cmd)
{
	if (strcmp(cmd, "up") == 0 || strcmp(cmd, "open") == 0 || strcmp(cmd, "down") == 0)
	{
		delay(2000);
		statusMessage = "Door Opened                   ";
	} 
	else if (strcmp(cmd, "close") == 0)
	{
		delay(2000);
		statusMessage = "Door Closed                   ";
	}
	else if (strcmp(cmd, "M") == 0)
	{
		delay(2000);
		statusMessage = "In Maintenance Mode           ";
		while(1){};
	}
	else
	{
		unsigned int targetFloor = (unsigned int)characterToInt(cmd);
		if (targetFloor >= 1 && targetFloor <= 5)
		{
			moveElevatorToFloor(targetFloor);
		}
		else
		{
			statusMessage = "Invalid Floor                 ";
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