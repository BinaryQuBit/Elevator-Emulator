// **************************************** tasking.h **************************************
// Project: Elevator Simulation
// File: tasking.h
// Class: ENEL 452 Lab Works
// Programmer: Amandip Padda
// SID: 200455829
// Description: The project is based on the STM32F103RB that is being used in ENEL 452 Labs.

// =========================================================================================
// **************************************** IMPORTANT **************************************
// Copyright (c) 2023. All rights reserved. 
// See the bottom of this file for the license terms.
// =========================================================================================

// ************************************ Defining Tasking.h *********************************
#ifndef TASKING_H
#define TASKING_H

// *********************************** Defining Header Files *******************************
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "myFunctions.h"
#include "usart.h"
#include "cli.h"
#include "timer.h"
#include "tasking.h"
#include "staticStructure.h"

// ************************************ Defining Variables *********************************
#define CMD_BUFFER_SIZE 128 // Input Size

static int cmdIndex = 0; // Index to track
static char cmdBuffer[CMD_BUFFER_SIZE]; // passing buffer
extern volatile uint32_t floorNumber; // to track floor number
extern char *statusMessage; // to track message

// ************************************* Defining Queues ***********************************
extern QueueHandle_t xCommandQueue; // Queue for command
extern QueueHandle_t xDrawQueue; // Queue to update the visual floors

// ************************************** Defining Tasks ***********************************
void floorStatus(void *pvParameters); // Floor Status
void status(void *pvParameters); // Status Message
void TaskHandleUserInput(void *pvParameters); // Input Handle
void TaskProcessCommand(void *pvParameters); // Process Tasks
void draw(void *pvParameters); // Process to update visiual floors
void timeElapsed(void *pvParameters); // Process to update window timer

// ********************************** Logic to Move Elevator *******************************
void moveElevatorToFloor(unsigned int targetFloor);

// ********************************* Logic to Process Command ******************************
void processCommand(const char* cmd);

#endif // TASKING_H

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