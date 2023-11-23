// ****************************************** cli.h ****************************************
// Project: Elevator Simulation
// File: cli.h
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
#include <stdint.h>
#include <string.h>

extern int volatile cursorColumn;
extern uint8_t volatile currentRow;
extern uint8_t volatile currentColumn;

// ************************************ Transmitting Data **********************************
void CLI_Transmit(uint8_t *pData, uint16_t Size);

// ************************************* Receiving Data ************************************
void CLI_Receive(uint8_t *pData, uint16_t Size);

// ******************************** For Easier Transmitting ********************************
void display(char messages[], uint8_t row, uint8_t column);

void setCursorPosition(uint8_t row, uint8_t column);
void testCursor();
void convertToString(uint8_t number, char buffer[], uint8_t row, uint8_t column);
void saveCursorPosition();
void getCursorPosition();

void message(const char* str);


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