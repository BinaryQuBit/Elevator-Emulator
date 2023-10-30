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
#include "string.h"
int characterFlag = 0;
uint8_t characterReceived = 0;

// **************************************** Serial Open ************************************
void serial_open(void)
{
	// Enable the USART 2 Clock
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	// Set baud rate to 115200 bps
	USART2->BRR = (19 <<4) | (9 & 0xF);

	// Configure data format: 8 bits, no parity, 1 stop bit
	USART2->CR1 &= ~USART_CR1_M; // 8 data bits
	USART2->CR1 &= ~USART_CR1_PCE; // No parity
	USART2->CR2 &= ~USART_CR2_STOP; // 1 stop bit
	
	// Interupt
	NVIC_EnableIRQ(USART2_IRQn);

	// Enable all required 
	USART2->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE | USART_CR1_RXNEIE;

	// Enable TIM2 clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	// Set the prescaler value for 1ms timing assuming a 36MHz clock
	TIM2->PSC = 35999;

	// Set the auto-reload value to achieve a 1s delay
	TIM2->ARR = 1;

	// Enable the update interrupt
	TIM2->DIER |= TIM_DIER_UIE;

	// Enable the timer
	TIM2->CR1 |= TIM_CR1_CEN;
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

// ************************************ Interrupt Handler **********************************
void USART2_IRQHandler(void)
{
	if (USART2->SR & USART_SR_RXNE)
	{
		uint8_t receivedByte = (uint8_t)USART2->DR;
		characterReceived = receivedByte;
		characterFlag = 1;
		sendbyte(receivedByte); // Echo back the received byte
	}
}

// *************************************** Sending Byte ************************************
int sendbyte(uint8_t b)
{
	while (!(USART2->SR & USART_SR_TXE));  // Wait until buffer is empty
	USART2->DR = b;
	while (!(USART2->SR & USART_SR_TC));   // Wait until complete
	return 0;
}

// *************************************** Getting Byte ************************************
uint8_t getbyte(void)
{
	while (!(USART2->SR & USART_SR_RXNE));
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
