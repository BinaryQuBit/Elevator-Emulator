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
	
// Enable RXNE interrupt
	USART2->CR1 |= USART_CR1_RXNEIE;
	
// Enable USART2 interrupt in the NVIC
	NVIC_EnableIRQ(USART2_IRQn);
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
int sendbyte(uint8_t b, uint32_t Timeout) {
    if(!(USART2->CR1 & USART_CR1_UE)) {
        return -1;
    }

    uint32_t start_time = TIM2->CNT;
    while(!(USART2->SR & USART_SR_TXE)) {
        if((TIM2->CNT - start_time) > Timeout) {
            return -2; // Timeout error
        }
    }
    USART2->DR = (uint16_t)b;
    return 0;
}


// *************************************** Getting Byte ************************************
uint8_t getbyte(uint32_t Timeout) {
    uint32_t start_time = TIM2->CNT;
    while (!(USART2->SR & USART_SR_RXNE)) {
        if((TIM2->CNT - start_time) > Timeout) {
            return 0xFF;
        }
    }
    return (uint8_t)USART2->DR;
}


extern "C" void USART2_IRQHandler(void) {
    if(USART2->SR & USART_SR_RXNE) {  // Check if data is available to read
        rx_buffer[rx_index++] = (uint8_t)USART2->DR;  // Read the byte from the data register
        if(rx_index >= 127) {  // Avoid buffer overflow
            rx_index = 0;
        }
        rx_flag = 1;  // Set the flag
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
