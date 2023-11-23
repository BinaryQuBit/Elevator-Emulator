// ****************************************** usart.c **************************************
// Project: Elevator Simulation
// File: usart.c
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
#include "usart.h"
#include "myFunctions.h"
#include "cli.h"

// **************************************** Serial Open ************************************
void serial_open(void)
{
	RCC_EnableUSARTClock(2);
	RCC_SetGPIOClock('A', true);
	GPIO_ConfigurePin(GPIOA, 2, GPIO_MODE_OUTPUT_10MHZ, GPIO_CNF_AF_PP);
	GPIO_ConfigurePin(GPIOA, 3, GPIO_MODE_INPUT, GPIO_CNF_FLOATING);
	USART2->BRR = 312.5;
	USART2->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE | USART_CR1_RXNEIE;
	NVIC_EnableIRQ(USART2_IRQn);
	usartTimer();
}

// *************************************** Serial Close ************************************
void serial_close(void)
{
	USART2->CR1 = 0;
	USART2->BRR = 0;
	RCC->APB1ENR &= ~RCC_APB1ENR_USART2EN;
}

// *************************************** Sending Byte ************************************
int sendbyte(uint8_t b)
{
	while (!(USART2->SR & USART_SR_TXE));
	USART2->DR = b;
	while (!(USART2->SR & USART_SR_TC));
	return 0;
}

// *************************************** Getting Byte ************************************
uint8_t getbyte(void)
{
	while (!(USART2->SR & USART_SR_RXNE));
	return (uint8_t)USART2->DR;
}

// ************************************* Usart on Timer 2 **********************************
uint32_t usartTimer(void)
{
	RCC_EnableTimerClock(2);
	TIM2->PSC = 35999;
	TIM2->ARR = 1;
	TIM2->DIER |= TIM_DIER_UIE;
	TIM2->CR1 |= TIM_CR1_CEN;
}

// ********************************* Usart Interrupt Handler *******************************
void USART2_IRQHandler(void) {
    if (USART2->SR & USART_SR_RXNE) {
        uint8_t receivedByte = (uint8_t)USART2->DR;
        characterReceived = receivedByte;
        characterFlag = 1;
        sendbyte(receivedByte);
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