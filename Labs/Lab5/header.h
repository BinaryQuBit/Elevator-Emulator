// ***************************************** header.h **************************************
// Project: CLI on the Target
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
#include "stm32f10x.h"
#include "string.h"
extern uint8_t speed;

// ********************************* Configuration of clocks *******************************
void clockInit(void);

// ********************** Enabling certain ports like IO / AFIO / ADC **********************
void portEnable(void);

// ************************* Configuring certain pins on the ports *************************
void pinConfigure(void);

// ********** A delay function used for delaying the processor to a certain speed **********
void delay(int);

// ******************************* Instructions to run USER LED ****************************
void ledTest(void);

// ************************************* Turn User LED ON **********************************
void userLedOn(void);

// ************************************ Turn User LED OFF **********************************
void userLedOff(void);

// ***************************** Serial Connection Open for USART **************************
void serial_open(void);

// **************************** Serial Connection Close for USART **************************
void serial_close(void);

// *************************************** Sending Byte ************************************
int sendbyte(uint8_t b);

// *************************************** Getting Byte ************************************
uint8_t getbyte(void);

// ************************************ Transmitting Data **********************************
void CLI_Transmit(uint8_t *pData, uint16_t Size);

// ************************************* Receiving Data ************************************
void CLI_Receive(uint8_t *pData, uint16_t Size);

// ************************************* Initial Messages **********************************
void message(const char* str);

// ********************************* Process the Commands **********************************
void processCommand(const char* cmd);

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