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

// ******************************** Setting Cursor Position ********************************
void setCursorPosition(uint8_t row, uint8_t column) {
    char buffer[20];
    sprintf(buffer, "\033[%d;%dH", row, column);
    CLI_Transmit((uint8_t*)buffer, strlen(buffer));
}

// ******************************* Int to String Conversion ********************************
void convertToString(uint8_t number, char buffer[], uint8_t row, uint8_t column)
{
    sprintf(buffer, "%d", number);
    display(buffer, row, column);
}

// ********************** Just to transmit message without position ************************
void message(const char* str)
{
	CLI_Transmit((uint8_t *)str, strlen(str));
}

// ****************************** To save cursors Position *********************************
void saveCursorPosition() {
	message("\033[s");
}

// ******************************* To get cursors Position *********************************
void getCursorPosition() {
	message("\033[u");
}

// ******************************** To send arrow Prompts **********************************
void sendPromptArrows()
{
	uint8_t column = 0;
	display(">> ", currentRow, currentColumn);
	message("\033[s");
}

// *********************************** To clear screen *************************************
void clearScreenFromRow(uint8_t startRow)
{
	char clearLine[SCREEN_WIDTH + 1];
	memset(clearLine, ' ', SCREEN_WIDTH);
	clearLine[SCREEN_WIDTH] = '\0';
	for (uint8_t i = startRow; i <= MAX_ROW; i++)
	{
		display(clearLine, i, 0);
		setCursorPosition(startRow, 0);
		currentRow = startRow;
		currentColumn = 0;
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