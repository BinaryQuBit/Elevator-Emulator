// ******************************************* main.c **************************************
// Project: Elevator Simulation
// File: main.c
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
#include "header.h"

// ************************************* Starting of Main **********************************
int main(void)
{
	// Enabling Clock
	clockInit();
	
	// Opening Serial Com
	serial_open();
	
	// Timer interrupt
	updateTimer();
	
	// Setting up display
	displaySetup();
	
	// External PC13 Interrupt
	interruptPC13setup();
	
	// Creating queue to store Tasks
	xCommandQueue = xQueueCreate(100, sizeof(char*));
	
	// Creating Queue to update the visual floor
	xDrawQueue = xQueueCreate(100, sizeof(uint8_t));
	
	// Thread to handle input
	xTaskCreate(TaskHandleUserInput, "Input", configMINIMAL_STACK_SIZE, NULL, configMAX_PRIORITIES - 1, NULL);
	
	// Thread to handle timer
	xTaskCreate(timeElapsed, "CmdProcessor", configMINIMAL_STACK_SIZE, NULL, configMAX_PRIORITIES - 2, NULL);
	
	// Thread to handle floor
	xTaskCreate(floorStatus, "floor", configMINIMAL_STACK_SIZE, NULL, configMAX_PRIORITIES - 3, NULL);
	
	// Thread to handle status
	xTaskCreate(status, "status", configMINIMAL_STACK_SIZE, (void*)statusMessage, configMAX_PRIORITIES - 4, NULL);
	
	// Thread to handle Tasks that are in input
	xTaskCreate(TaskProcessCommand, "CmdProcessor", configMINIMAL_STACK_SIZE, NULL, configMAX_PRIORITIES - 5, NULL);
	
	// Thread to handle the update of the visual color
	xTaskCreate(draw, "CmdProcessor", configMINIMAL_STACK_SIZE, NULL, configMAX_PRIORITIES, NULL);
	vTaskStartScheduler();
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