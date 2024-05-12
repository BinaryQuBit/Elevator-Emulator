// ***************************************** header.h **************************************
// Project: Elevator Simulation
// File: header.h
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
#include "myFunctions.h"
#include "usart.h"
#include "cli.h"
#include "timer.h"
#include "tasking.h"
#include "FreeRTOS.h"
#include "task.h"
#include "staticStructure.h"
#include "queue.h"

// ***********************************  Global Variables ***********************************
int characterFlag; // Interrupt Flag for input ~ USART
uint8_t characterReceived; // Storing Char recieved
volatile uint32_t timeCounter; // Interupt for Timer
volatile uint32_t floorNumber = 1; // Floor number
char *statusMessage = "Idle                          "; // status message
volatile uint8_t currentRow = 24; // row to be set at this position
volatile uint8_t currentColumn = 0; // column to be set at this position
volatile uint8_t buttonPressed = 0; // button pressed user

// ***************************************** Queues ****************************************
QueueHandle_t xCommandQueue; // Queue for command
QueueHandle_t xDrawQueue; // Queue for updating visiual floors

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