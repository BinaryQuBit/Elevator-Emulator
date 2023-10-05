// ***************************************** CLI.cpp *************************************
// Project: CLI on the Target
// File: CLI.cpp
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
void CLI_Receive(uint8_t *pData, uint16_t Size) {
	uint16_t i = 0;
	
// Leave space for null terminator -1 space
	while (i < Size - 1)
	{
		
// This will block until a byte is received
		uint8_t byte = getbyte();
		
// Anytime a byte new line and carriage break it off
		if (byte == '\n' || byte == '\r')
		{
			break;
		}
		
// Handle backspace and delete character
		if (byte == '\b' || byte == 0x7F)
		{

// Has to be greater than 0 due to it not going backward
			if (i > 0)
			{

// Move cursor one step back
				sendbyte('\b');
				
// Overwrite with space
				sendbyte(' ');
				
// Move cursor back again
				sendbyte('\b');
				
// Decrement buffer index
				i--;
			}
				continue;
		}
		
// Check all the characters on the keyboard
		if (byte >= ' ' && byte <= '~')
		{
			
// Store byte in buffer and increment index
			pData[i++] = byte;
			
// Echo the received byte back
			sendbyte(byte);
		}
	}
	
// Null-terminate the received string
	pData[i] = '\0';
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