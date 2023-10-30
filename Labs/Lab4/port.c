// ****************************************** port.cpp *************************************
// Project: CLI on the Target
// File: port.cpp
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

// *************************************** Enable Ports ************************************
void portEnable(void)
{
// ***************************************** IO Ports **************************************
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
// RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN;
// RCC -> APB2ENR |= RCC_APB2ENR_IOPCEN;
// RCC -> APB2ENR |= RCC_APB2ENR_IOPDEN;

// **************************************** AFIO Ports *************************************
// RCC -> APB2ENR |= RCC_APB2ENR_AFIOEN;
	
// ***************************************** ADC Ports *************************************
// RCC -> APB2ENR |= RCC_APB2ENR_ADC1EN;
// ADC1 -> CR2 = 0x00000001;
// RCC -> APB2ENR |= RCC_APB2ENR_ADC2EN;
// ADC2 -> CR2 = 0x00000001;
	
// ******************************************* Timer ***************************************
// RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
// RCC -> APB1ENR |= RCC_APB1ENR_TIM3EN;
	
// ***************************************** Interrupt *************************************
// AFIO -> EXTICR[1] |= AFIO_EXTICR2_EXTI5_PB; // Sets to trigger Line 5 External Interrupt
// EXTI -> IMR |= (1 << 5); // Enable Interrupt on Line 5
// EXTI -> RTSR |= (1 << 5); // Rising Edge Trigger on Line 5
// EXTI -> FTSR &= ~(1 << 5); // Falling Edge Trigger on Line 5
// AFIO -> EXTICR[1] |= AFIO_EXTICR2_EXTI6_PB; // Sets to trigger Line 6 External Interrupt
// EXTI -> IMR |= (1 << 6); // Enable Interrupt on Line 6
// EXTI -> RTSR |= (1 << 6); // Rising Edge Trigger on Line 5
// EXTI -> FTSR &= ~(1 << 6); // Falling Edge Trigger on Line 5
// NVIC_SetPriority(EXTI9_5_IRQn, 0x00); // Priority High
// NVIC_EnableIRQ(EXTI9_5_IRQn); // Enable 
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
