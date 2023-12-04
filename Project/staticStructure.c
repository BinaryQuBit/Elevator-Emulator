// *********************************** staticStructure.c ***********************************
// Project: Elevator Simulation
// File: staticStructure.c
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
#include "staticStructure.h"

// *********************************** To change Text color ********************************
void setTextColor(uint8_t colorCode)
{
	char colorBuffer[20];
	sprintf(colorBuffer, "\033[38;5;%dm", colorCode);
	CLI_Transmit((uint8_t*)colorBuffer, strlen(colorBuffer));
}

// ******************************* To make boundary of elevator ****************************
void displayBox(uint8_t width, uint8_t height, uint8_t centerRow, uint8_t centerColumn, uint8_t colorCode)
{
	uint8_t halfWidth = width / 2;
	uint8_t halfHeight = height / 2;
	setTextColor(colorCode);
	for (uint8_t col = centerColumn - halfWidth; col <= centerColumn + halfWidth; col++)
	{
		setCursorPosition(centerRow - halfHeight, col);
		CLI_Transmit((uint8_t*)"-", 1);
		setCursorPosition(centerRow + halfHeight - 1, col);
		CLI_Transmit((uint8_t*)"-", 1);
	}
	for (uint8_t row = centerRow - halfHeight; row < centerRow + halfHeight; row++)
	{
		setCursorPosition(row, centerColumn - halfWidth);
		CLI_Transmit((uint8_t*)"|", 1);
		setCursorPosition(row, centerColumn + halfWidth);
		CLI_Transmit((uint8_t*)"|", 1);
	}
	setCursorPosition(centerRow - halfHeight, centerColumn - halfWidth);
	CLI_Transmit((uint8_t*)"+", 1);
	setCursorPosition(centerRow - halfHeight, centerColumn + halfWidth);
	CLI_Transmit((uint8_t*)"+", 1);
	setCursorPosition(centerRow + halfHeight - 1, centerColumn - halfWidth);
	CLI_Transmit((uint8_t*)"+", 1);
	setCursorPosition(centerRow + halfHeight - 1, centerColumn + halfWidth);
	CLI_Transmit((uint8_t*)"+", 1);
}

// ********************************* To draw horizontal line *******************************
void drawHorizontal(uint8_t width, uint8_t centerRow, uint8_t centerColumn, uint8_t colorCode)
{
	uint8_t halfWidth = width / 2;
	setTextColor(colorCode);
	for (uint8_t col = centerColumn - halfWidth; col <= centerColumn + halfWidth; col++)
	{
		setCursorPosition(centerRow, col);
		CLI_Transmit((uint8_t*)"-", 1);
	}
}

void drawVertical(uint8_t height, uint8_t centerRow, uint8_t centerColumn, uint8_t colorCode) {
    uint8_t halfHeight = height / 2;
    setTextColor(colorCode);
    for (uint8_t row = centerRow - halfHeight; row <= centerRow + halfHeight; row++) {
        setCursorPosition(row, centerColumn);
        CLI_Transmit((uint8_t*)"|", 1);
    }
}

void drawFifth(uint8_t floorNumber, uint8_t colorCode)
{
	char buffer[1];
	displayBox(20, 9, 6, 155, colorCode);
	drawVertical(4, 6, 155, colorCode);
	drawVertical(4, 6, 156, colorCode);
	drawHorizontal(18, 4, 155, colorCode);
  convertToString(floorNumber, buffer, 3, 155);
}

void drawForth(uint8_t floorNumber, uint8_t colorCode)
{
	char buffer[1];
	displayBox(20, 9, 6, 125, colorCode);
	drawVertical(4, 6, 125, colorCode);
	drawVertical(4, 6, 126, colorCode);
	drawHorizontal(18, 4, 125, colorCode);
  convertToString(floorNumber, buffer, 3, 125);
}

void drawThird(uint8_t floorNumber, uint8_t colorCode)
{
	char buffer[1];
	displayBox(20, 9, 6, 95, colorCode);
	drawVertical(4, 6, 95, colorCode);
	drawVertical(4, 6, 96, colorCode);
	drawHorizontal(18, 4, 95, colorCode);
  convertToString(floorNumber, buffer, 3, 95);
}

void drawSecond(uint8_t floorNumber, uint8_t colorCode)
{
	char buffer[1];
	displayBox(20, 9, 6, 65, colorCode);
	drawVertical(4, 6, 65, colorCode);
	drawVertical(4, 6, 66, colorCode);
	drawHorizontal(18, 4, 65, colorCode);
  convertToString(floorNumber, buffer, 3, 65);
}

void drawFirst(uint8_t floorNumber, uint8_t colorCode)
{
	char buffer[1];
	displayBox(20, 9, 6, 35, colorCode);
	drawVertical(4, 6, 35, colorCode);
	drawVertical(4, 6, 36, colorCode);
	drawHorizontal(18, 4, 35, colorCode);
  convertToString(floorNumber, buffer, 3, 35);
}

void instructions(uint8_t colorCode)
{
	setTextColor(colorCode);
	display("To Run Elevator, Follow these commands", 11, 76);
	display("To go to the top floors ~ TYPE: 'up'", 12, 1);
	display("To go to the bottom floors ~ TYPE: 'down'", 13, 1);
	display("To select 1st floor ~TYPE: '1'", 14, 1);
	display("To select 2nd floor ~TYPE: '2'", 15, 1);
	display("To select 3rd floor ~TYPE: '3'", 16, 1);
	display("To select 4th floor ~TYPE: '4'", 17, 1);
	display("To select 5th floor ~TYPE: '5'", 18, 1);
	display("To open door ~TYPE: 'open'", 19, 1);
	display("To close door ~TYPE: 'close'", 20, 1);
	display("For emergency stop ~Press: 'User Button'. To continue press again!", 21, 1);
	display("For maintenance ~TYPE: 'M'. To continue press reset button!", 22, 1);
}

void statusDisplay(uint8_t colorCode)
{
	setTextColor(colorCode);
	displayBox(44, 9, 17, 160, colorCode);
	display("View Point", 14, 155);
	display("Time Elapsed: ", 16, 144);
	display("Floor: ", 17, 144);
	display("Status: ", 18, 144);
}

void displayBreaker(uint8_t row, uint8_t colorCode)
{
	setTextColor(colorCode);
	display("-----------------------------------------------------------------------", row, 0);
	display("-----------------------------------------------------------------------", row, 72);
	display("-----------------------------------------------", row, 143);
}

void displaySetup()
{
	display("\033[2J", 1, 1);
	drawFirst(1, 34);
	drawSecond(2, 33);
	drawThird(3, 33);
	drawForth(4, 33);
	drawFifth(5, 33);
	displayBreaker(10, 31);
	instructions(34);
	statusDisplay(33);
	displayBreaker(23, 31);
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