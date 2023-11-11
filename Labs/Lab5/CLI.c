// ***************************************** CLI.cpp *************************************
// Project: CLI on the Target
// File: CLI.c
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
#include "stm32f10x.h"
#include "header.h"

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
    // Handle backspace or delete
		if (pData[i] == 0x08 || pData[i] == 0x7F)
		{
			// Only handle backspace if we have received other characters
			if (i > 0)
			{ 
				sendbyte(0x08); // move cursor one position back
				sendbyte(' ');  // overwrite the character with space
				sendbyte(0x08); // move cursor back again
				i -= 2;        // adjust the buffer index to overwrite the last character
			} 
			else
			{
				i--; // Stay at the current position in buffer if no previous character
			}
		} 
		// Handle carriage return
		else if (pData[i] == 0x0D)
		{
			sendbyte(0x0D); // echo carriage return
			sendbyte(0x0A); // move to the next line
		} 
		// Handle line feed
		else if (pData[i] == 0x0A)
		{
			sendbyte(0x0A); // echo line feed
		} 
		// Echo other characters
		else
		{
			sendbyte(pData[i]);
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