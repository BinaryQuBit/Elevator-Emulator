// *************************************** myFunctions.c ***********************************
// Project: Elevator Simulation
// File: myFunctions.c
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
#include "myFunctions.h"

// *************************************** Clock Enable ************************************
void clockInit(void)
{
// ************************* Enable HSI and wait for it to be ready ************************
	RCC->CR |= RCC_CR_HSION;
	while (((RCC->CR) & (RCC_CR_HSION | RCC_CR_HSIRDY)) == 0);
	
// ******************* Enable HSE with Bypass and wait for it to be ready ******************
	RCC->CR |= RCC_CR_HSEON | RCC_CR_HSEBYP;
	while (((RCC->CR) & (RCC_CR_HSEON | RCC_CR_HSEBYP | RCC_CR_HSERDY)) == 0);
	
// ******************* SET HSI as SYSCLK and wait for it to be recognized ******************
// RCC->CFGR = RCC_CFGR_SW_HSI;
// while (((RCC->CFGR) & (RCC_CFGR_SW_HSI | RCC_CFGR_SWS_HSI))!=0);

// ******************* SET HSE as SYSCLK and wait for it to be recognized ******************
	RCC->CFGR = RCC_CFGR_SW_HSE;
	while (((RCC->CFGR) & (RCC_CFGR_SW_HSE | RCC_CFGR_SWS_HSE)) == 0);
	
// *********************************** To Use PLL as SYSCLK ********************************
	RCC->CR &= ~RCC_CR_PLLON;
	
// *********************** Change PLL source and set the PLL multiplier ********************
// These are the SYSCLK values when using the PLL with HSI/2 as the input. The max value is 64 MHz
// RCC->CFGR = 0x00000000;// 8 MHz
// RCC->CFGR = 0x00040000;// 12 MHz
// RCC->CFGR = 0x00080000;// 16 MHz
// RCC->CFGR = 0x000c0000;// 20 MHz
// RCC->CFGR = 0x00100000;// 24 MHz
// RCC->CFGR = 0x00140000;// 28 MHz
// RCC->CFGR = 0x00180000;// 32 MHz
 RCC->CFGR = 0x001C0000;// 36 MHz
// RCC->CFGR = 0x00200000;// 40 MHz
// RCC->CFGR = 0x00280000;// 48 MHz
// RCC->CFGR = 0x002C0000;// 52 MHz
// RCC->CFGR = 0x003C0000;// 64 MHz

// These are the SYSCLK values when using the PLL with HSE/Bypass as the input. The max value is 72 Mhz
// RCC->CFGR = 0x00010000;// 16 MHz
// RCC->CFGR = 0x00050000;// 24 MHz
// RCC->CFGR = 0x00090000;// 32 MHz
// RCC->CFGR = 0x000d0000;// 40 MHz
// RCC->CFGR = 0x00110000;// 48 MHz
// RCC->CFGR = 0x00150000;// 56 MHz
// RCC->CFGR = 0x00190000;// 64 MHz
// RCC->CFGR = 0x001d0000;// 72 MHz

// ****************************** ENABLE PLL and wait for it to be ready *******************
RCC->CR |= RCC_CR_PLLON;
while(((RCC->CR) & (RCC_CR_PLLON | RCC_CR_PLLRDY)) == 0);
 
// ************************* Set PLL as SYSCLK and wait for it to be ready *****************
RCC->CFGR &= ~(RCC_CFGR_SW);
RCC->CFGR |= RCC_CFGR_SW_PLL; // 0x00000002;
while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL) {}
	
// Enable clock visibity on PA8 and select desired source (By default, the output will be the PLL frequency divided by 2)
// RCC->CFGR |= RCC_CFGR_MCO_HSI;
// RCC->CFGR |= RCC_CFGR_MCO_HSE;
// RCC->CFGR |= RCC_CFGR_MCO_SYSCLK;
	RCC->CFGR |= RCC_CFGR_MCO_PLL;
	RCC->CFGR &= ~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
	RCC->CFGR |= (RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL9);
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY)) {}
}
// **************************************** Port Enable ************************************
void RCC_SetGPIOClock(uint8_t GPIOx, bool enable)
{
	uint32_t gpioClockBit = 0;
	switch (GPIOx)
	{
		case 'A':
			gpioClockBit = RCC_APB2ENR_IOPAEN;
			break;
		case 'B':
			gpioClockBit = RCC_APB2ENR_IOPBEN;
			break;
		case 'C':
			gpioClockBit = RCC_APB2ENR_IOPCEN;
			break;
		case 'D':
			gpioClockBit = RCC_APB2ENR_IOPDEN;
			break;
		default:
			return;
	}
	if (enable)
	{
		RCC->APB2ENR |= gpioClockBit;
	}
	else
	{
		RCC->APB2ENR &= ~gpioClockBit;
	}
}

// **************************************** AFIO Enable ************************************
void RCC_EnableAFIOClock(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
}

// ***************************************** ADC Enable ************************************
void RCC_EnableADCClock(uint8_t ADCx)
{
	if (ADCx == 1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
		ADC1->CR2 = 0x00000001;
	} 
	else if (ADCx == 2)
	{
		RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
		ADC2->CR2 = 0x00000001;
	}
}

// ************************************* USART Clock Enable ********************************
void RCC_EnableUSARTClock(uint8_t usart)
{
	switch (usart)
	{
		case 1:
			RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
			break;
		case 2:
			RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
			break;
		case 3:
			RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
			break;
		default:
			break;
	}
}

// ************************************ Timer Clock Enable *********************************
void RCC_EnableTimerClock(uint8_t timer)
{
	switch (timer)
	{
		case 1:
			RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
			break;
		case 2:
			RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
			break;
		case 3:
			RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
      break;
		case 4:
			RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
			break;
		default:
			break;
	}
}

// ************************************ Pin Configuration **********************************
void GPIO_ConfigurePin(GPIO_TypeDef* GPIOx, uint8_t Pin, uint8_t Mode, uint8_t CNF)
{
	uint32_t cnf_mode_mask = 0x0F;
	uint32_t cnf_mode_bits = ((uint32_t)CNF << 2) | (uint32_t)Mode;
	uint32_t *config_register;
	if (Pin < 8)
	{
		config_register = &GPIOx->CRL;
	}
	else
	{
		config_register = &GPIOx->CRH;
		Pin -= 8;
	}
	cnf_mode_mask <<= (Pin * 4);
	cnf_mode_bits <<= (Pin * 4);
	*config_register &= ~cnf_mode_mask;
	*config_register |= cnf_mode_bits;
}

// ************************************** Delay Function ***********************************
void delay(int a)
{
	unsigned volatile int c, d; 
	for (c = 1; c <= a; c++)
	{
		for (d = 1; d <= a; d++)
		{}
	}
}

// *************************** Function defination to User LED Flash ***********************
void ledFlash(void)
{
	RCC_SetGPIOClock('A', true);
	GPIO_ConfigurePin(GPIOA, 5, GPIO_MODE_OUTPUT_50MHZ, GPIO_CNF_OUTPUT_PP);
	GPIOA->ODR |= GPIO_ODR_ODR5;
	delay(1000);
	GPIOA->ODR &= ~GPIO_ODR_ODR5;
	delay(1000);
}

// ************************************* Turn User LED ON **********************************
void userLedOn(void)
{
	GPIOA->ODR |= GPIO_ODR_ODR5;
}

// ************************************ Turn User LED OFF **********************************
void userLedOff(void)
{
	GPIOA->ODR &= ~GPIO_ODR_ODR5;
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