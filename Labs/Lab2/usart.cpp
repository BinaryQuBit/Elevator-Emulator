// ***************************************** usart.cpp *************************************
// Project: CLI on the Target
// File: usart.cpp
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

// **************************************** Serial Open ************************************
void serial_open(void) {
// USART Clock Enabled
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

// Baud Rate Set ~ 72000000/115200 = 625 = 0x271 - 72Mhz is the SYSCLK
	USART2->BRR = 0x271;
	
// Enabling Transmitter, Reciever and USART2
	USART2->CR1 |= (USART_CR1_TE | USART_CR1_RE | USART_CR1_UE);
}

// *************************************** Serial Close ************************************
void serial_close(void)
{
// Clock Register = 0
	USART2->CR1 = 0;
	
// Baud Rate = 0 
	USART2->BRR = 0;

// USART Clock Enabled
	RCC->APB1ENR &= ~RCC_APB1ENR_USART2EN;
}

// *************************************** Sending Byte ************************************
int sendbyte(uint8_t b)
{
// Checking if USART Enable Bit is not set in Control Register 1
	if(!(USART2->CR1 & USART_CR1_UE))
	{
		return -1;
	}

// Waiting for the Transmission Data Register if its empty or not in Status Register
	while(!(USART2->SR & USART_SR_TXE))
	{};

// Sending the Byte
	USART2->DR = (uint16_t)b;
	return 0;
}

// *************************************** Getting Byte ************************************
uint8_t getbyte(void)
{
// Waiting for the Receiver Data Register if its empty or not in Status Register
	while (!(USART2->SR & USART_SR_RXNE))
	{};

// Read and Return the Byte
	return (uint8_t)USART2->DR;
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
