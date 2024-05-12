// *********************************** staticStructure.h ***********************************
// Project: Elevator Simulation
// File: staticStructure.h
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
#include <stdio.h>
#include "cli.h"
void setTextColor(uint8_t colorCode);
void displayBox(uint8_t width, uint8_t height, uint8_t centerRow, uint8_t centerColumn, uint8_t colorCode);
void drawHorizontal(uint8_t width, uint8_t centerRow, uint8_t centerColumn, uint8_t colorCode);
void drawVertical(uint8_t height, uint8_t centerRow, uint8_t centerColumn, uint8_t colorCode);
void drawFifth(uint8_t floorNumber, uint8_t colorCode);
void drawForth(uint8_t floorNumber, uint8_t colorCode);
void drawThird(uint8_t floorNumber, uint8_t colorCode);
void drawSecond(uint8_t floorNumber, uint8_t colorCode);
void drawFirst(uint8_t floorNumber, uint8_t colorCode);
void instructions(uint8_t colorCode);
void statusDisplay(uint8_t colorCode);
void displayBreaker(uint8_t row, uint8_t colorCode);
void displaySetup();

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