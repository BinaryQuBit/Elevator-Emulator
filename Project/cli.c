// ****************************************** cli.c ****************************************
// Project: Elevator Simulation
// File: cli.c
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
#include "cli.h"
#include "usart.h"
#include <stdio.h>
#include "myFunctions.h"

// ************************************ Transmitting Data **********************************
void CLI_Transmit(uint8_t *pData, uint16_t Size)
{
	for (uint16_t i = 0; i < Size; i++)
	{
		sendbyte(pData[i]);
	}
}

// ************************************* Receiving Data ************************************
void CLI_Receive(uint8_t *pData, uint16_t Size)
{
	for (uint16_t i = 0; i < Size; i++)
	{
		pData[i] = getbyte();
		if (pData[i] == 0x08 || pData[i] == 0x7F)
		{
			if (i > 0)
			{ 
				sendbyte(0x08);
				sendbyte(' ');
				sendbyte(0x08);
				i -= 2;
			} 
			else
			{
				i--;
			}
		} 
		else if (pData[i] == 0x0D)
		{
			sendbyte(0x0D);
			sendbyte(0x0A);
		} 
		else if (pData[i] == 0x0A)
		{
			sendbyte(0x0A);
		} 
		else
		{
			sendbyte(pData[i]);
		}
	}
}

// ******************************** For Easier Transmitting ********************************
void display(char messages[], uint8_t row, uint8_t column)
{
	setCursorPosition(row, column);
	CLI_Transmit((uint8_t*)messages, strlen(messages));
}

void setCursorPosition(uint8_t row, uint8_t column) {
    char buffer[20];
    sprintf(buffer, "\033[%d;%dH", row, column);
    CLI_Transmit((uint8_t*)buffer, strlen(buffer));
}

void convertToString(uint8_t number, char buffer[], uint8_t row, uint8_t column)
{
    sprintf(buffer, "%d", number);
    display(buffer, row, column);
}

void message(const char* str)
{
	CLI_Transmit((uint8_t *)str, strlen(str));
}

void saveCursorPosition() {
	message("\033[s");
}

void getCursorPosition() {
	message("\033[u");
}

//void sendPromptArrows(){
//	uint8_t row = 24;
//	uint8_t column = 0;
//	display(">> ", row, column);
//	row++;
//}

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