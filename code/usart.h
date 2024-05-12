// ****************************************** usart.h **************************************
// Project: Elevator Simulation
// File: usart.h
// Class: ENEL 452 Lab Works
// Programmer: Amandip Padda
// SID: 200455829
// Description: The project is based on the STM32F103RB that is being used in ENEL 452 Labs.

// =========================================================================================
// **************************************** IMPORTANT **************************************
// Copyright (c) 2023. All rights reserved. 
// See the bottom of this file for the license terms.
// =========================================================================================

// *************************************** Library Call ************************************
#include <stdint.h>


// ************************************  Global Variables **********************************
extern int characterFlag;
extern uint8_t characterReceived;
extern volatile int cursorRow;
extern volatile int cursorColumn;

// ***************************** Serial Connection Open for USART **************************
void serial_open(void);

// **************************** Serial Connection Close for USART **************************
void serial_close(void);

// *************************************** Sending Byte ************************************
int sendbyte(uint8_t b);

// *************************************** Getting Byte ************************************
uint8_t getbyte(void);

// ************************************* Usart on Timer 2 **********************************
uint32_t usartTimer(void);

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
