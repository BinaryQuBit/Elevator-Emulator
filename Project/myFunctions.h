// *************************************** myFunctions.h ***********************************
// Project: Elevator Simulation
// File: myFunctions.h
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
#include <stdint.h>
#include <stdbool.h>

// ***********************************  Defining Variables *********************************
#define GPIO_MODE_INPUT           0x00
#define GPIO_MODE_OUTPUT_10MHZ    0x01
#define GPIO_MODE_OUTPUT_2MHZ     0x02
#define GPIO_MODE_OUTPUT_50MHZ    0x03
#define GPIO_CNF_ANALOG           0x00
#define GPIO_CNF_FLOATING         0x01
#define GPIO_CNF_INPUT_PUPD       0x02
#define GPIO_CNF_OUTPUT_PP        0x00
#define GPIO_CNF_OUTPUT_OD        0x01
#define GPIO_CNF_AF_PP            0x02
#define GPIO_CNF_AF_OD            0x03

// *************************************** Clock Enable ************************************
void clockInit(void);

// **************************************** Port Enable ************************************
void RCC_SetGPIOClock(uint8_t GPIOx, bool enable);

// **************************************** AFIO Enable ************************************
void RCC_EnableAFIOClock(void);

// ***************************************** ADC Enable ************************************
void RCC_EnableADCClock(uint8_t ADCx);

// ************************************* USART Clock Enable ********************************
void RCC_EnableUSARTClock(uint8_t usart);

// ************************************ Timer Clock Enable *********************************
void RCC_EnableTimerClock(uint8_t timer);

// ************************************ Pin Configuration **********************************
void GPIO_ConfigurePin(GPIO_TypeDef* GPIOx, uint8_t Pin, uint8_t Mode, uint8_t CNF);

// ************************************** Delay Function ***********************************
void delay(int a);

// *************************** Function defination to User LED Flash ***********************
void ledFlash(void);

// ************************************* Turn User LED ON **********************************
void userLedOn(void);

// ************************************ Turn User LED OFF **********************************
void userLedOff(void);

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