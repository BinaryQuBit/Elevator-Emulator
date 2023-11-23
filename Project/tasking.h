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

// *************************************** Header Files ************************************
#ifndef TASKING_H
#define TASKING_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "FreeRTOS.h"
#include "task.h"
#include <queue.h>

extern volatile uint32_t timeCounter;
extern volatile uint32_t floorNumber;
extern int blockSize;
extern char block[8][20];
extern int counter;
extern int moveCount;
extern int volatile cursorRow;
extern int volatile cursorColumn;	

void createQueue();
void displayStructure();
void elevatorUp(void *pvParameters);
void elevatorDown(void *pvParameters);
void timeElapsed(void *pvParameters);
void displayFloor(void *pvParameters);
// void displayStatus(void *pvParameters);
void ElevatorDoorTask(void *pvParameters);
void openDoor(void *pvParameters);

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