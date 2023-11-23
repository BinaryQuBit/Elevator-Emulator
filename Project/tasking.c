//// **************************************** tasking.c **************************************
//// Project: Elevator Simulation
//// File: tasking.c
//// Class: ENEL 452 Lab Works
//// Programmer: Amandip Padda
//// SID: 200455829
//// Description: The project is based on the STM32F103RB that is being used in ENEL 452 Labs.

//// =========================================================================================
//// **************************************** IMPORTANT **************************************
//// Copyright (c) 2023. All rights reserved. 
//// See the bottom of this file for the license terms.
//// =========================================================================================

//// *************************************** Header Files ************************************
//#include "tasking.h"
//#include "cli.h"
//#include "FreeRTOS.h"
//#include "task.h"
//#include "queue.h"
//#include "myFunctions.h"
//QueueHandle_t floorQueue;
//QueueHandle_t floorStatus;

//void displayStructure()
//{
//	message("\x1b[2J");
//	message("\x1b[4;1HTime Elapsed: 0");
//	message("\x1b[5;1HFloor: 1");
//	message("\x1b[6;1HStatus: Idle");
//	message("\x1b[0;78HWelcome to Elevator Simulation Control");
//	strcpy(block[0], " ----------- \r\n");
//	sprintf(block[1], "|     %d     |\r\n", counter);
//	strcpy(block[2], "|-----------|\r\n");
//	strcpy(block[3], "|     |     |\r\n");
//	strcpy(block[4], "|     |     |\r\n");
//	strcpy(block[5], "|     |     |\r\n");
//	strcpy(block[6], "|     |     |\r\n");
//	strcpy(block[7], " ----------- \r\n");
//	message("\x1b[10;0H-----------------------------------------------------------------------");
//	message("\x1b[10;72H-----------------------------------------------------------------------");
//	message("\x1b[10;143H-----------------------------------------------");
//	message("\x1b[11;78HTo Run Elevator, Follow these commands");
//	message("\x1b[12;0HTo go to the top floors ~ TYPE: 'up'");
//	message("\x1b[13;0HTo go to the bottom floors ~ TYPE: 'down'");
//	message("\x1b[14;0HTo select 1st floor ~TYPE: '1'");
//	message("\x1b[15;0HTo select 2nd floor ~TYPE: '2'");
//	message("\x1b[16;0HTo select 3rd floor ~TYPE: '3'");
//	message("\x1b[17;0HTo select 4th floor ~TYPE: '4'");
//	message("\x1b[18;0HTo select 5th floor ~TYPE: '5'");
//	message("\x1b[19;0HTo open door ~TYPE: 'open'");
//	message("\x1b[20;0HTo close door ~TYPE: 'close'");
//	message("\x1b[21;0HFor emergency stop ~TYPE: 'stop'");
//	message("\x1b[22;0HFor maintenance ~TYPE: 'M'");
//	message("\x1b[23;0H-----------------------------------------------------------------------");
//	message("\x1b[23;72H-----------------------------------------------------------------------");
//	message("\x1b[23;143H-----------------------------------------------");
//	message("\x1b[24;0H>> Press up or down! \r\n>> ");
//}



//void createQueue() {
//  floorQueue = xQueueCreate(10, sizeof(int));
//	floorStatus = xQueueCreate(1, 12);
//}

//void openDoor(void *pvParameters)
//{
//	while(1)
//	{
//		char statusToShow[] = "Opening Door";
//		char statusToShowNow[12] = "Door Opened!";
//		xQueueSend(floorStatus, &statusToShow, portMAX_DELAY);
//		delay(2000);
//		xQueueSend(floorStatus, &statusToShowNow, portMAX_DELAY);
//		vTaskSuspend(NULL);
//	}
//}

//// ********************************* Task to Display Elevator ******************************
//void elevatorUp(void *pvParameters)
//{
//while (1)
//    {
//        for (int i = 0; i < blockSize; i++)
//        {
//            char buffer[50];
//            sprintf(buffer, "\x1b[%d;90H%s", i + 2, block[i]);
//            message(buffer);
//        }
//        char temp[50];
//        strcpy(temp, block[0]);
//        for (int i = 0; i < blockSize - 1; i++)
//        {
//            strcpy(block[i], block[i + 1]);
//						setCursorPosition();
//        }
//        strcpy(block[blockSize - 1], temp);
//				setCursorPosition();
//        moveCount++;
//        if (moveCount % blockSize == 0)
//        {
//            counter = (counter % 5) + 1;
//            sprintf(block[1], "|     %d     |", counter);
//        }
//				 xQueueSend(floorQueue, &counter, portMAX_DELAY);
//        vTaskDelay(pdMS_TO_TICKS(399));
//    }
//}	


//void elevatorDown(void *pvParameters)
//{
//    while (1)
//    {
//        // Display the elevator block
//        for (int i = 0; i < blockSize; i++)
//        {
//            char buffer[50];
//            sprintf(buffer, "\x1b[%d;90H%s", i + 2, block[i]);
//            message(buffer);
//					setCursorPosition();
//        }

//        // Rotate the block display in reverse
//        char temp[50];
//        strcpy(temp, block[blockSize - 1]);
//        for (int i = blockSize - 1; i > 0; i--)
//        {
//            strcpy(block[i], block[i - 1]);
//					setCursorPosition();
//        }
//        strcpy(block[0], temp);
//				setCursorPosition();

//        // Update floor counter and display every blockSize moves
//        moveCount++;
//        if (moveCount % blockSize == 0)
//        {
//            counter = (counter == 1) ? 5 : counter - 1; // Loop back to 5 when it reaches 1
//            sprintf(block[1], "|     %d     |\r\n", counter);
//					setCursorPosition();
//        }
//				xQueueSend(floorQueue, &counter, portMAX_DELAY);
//        // Delay for animation effect
//        vTaskDelay(pdMS_TO_TICKS(400));
//				setCursorPosition();
//    }
//}



//// ******************************* Task to Display Time Elapsed ****************************
//void timeElapsed(void *pvParameters) {
//    while(1) {
//        char buffer[80]; // Increase the buffer size to accommodate both strings

//        // Print the time counter at the original position
//        int len = sprintf(buffer, "\x1b[4;15H%lu seconds", timeCounter);

//        // Move the cursor to the new position
//        sprintf(buffer + len, "\033[%d;%dH", cursorRow, cursorColumn);

//        CLI_Transmit((uint8_t*)buffer, strlen(buffer));
//        vTaskDelay(pdMS_TO_TICKS(400));
//    }
//}


//// ******************************* Task to Display Floor ****************************
//void displayFloor(void *pvParameters) {
//    int floorToShow;
//    while(1) {
//        if (xQueueReceive(floorQueue, &floorToShow, portMAX_DELAY) == pdPASS) {
//            char buffer[80]; // Increase buffer size to accommodate both strings

//            // Print the floor number at the original position
//            int len = sprintf(buffer, "\x1b[5;8H%d", floorToShow);

//            // Move the cursor to the new position
//            sprintf(buffer + len, "\033[%d;%dH", cursorRow, cursorColumn);

//            CLI_Transmit((uint8_t*)buffer, strlen(buffer));
//        }
//        vTaskDelay(pdMS_TO_TICKS(400));
//    }
//}


//// ******************************* Task to Display Status ****************************
//	void displayStatus(void *pvParameters)
//	{
//			char* statusToShow[0];
//			while(1)
//			{
//				if (xQueueReceive(floorStatus, &statusToShow, portMAX_DELAY) == pdPASS)
//				{
//					char buffer[80]; // Buffer size may need to be adjusted based on the length of statusToShow

//					// Print the status at the original position
//					int len = sprintf(buffer, "\x1b[6;9H%s", statusToShow);

//					// Move the cursor to the new position
//					sprintf(buffer + len, "\033[%d;%dH", cursorRow, cursorColumn);

//					CLI_Transmit((uint8_t*)buffer, strlen(buffer));
//									}
//					vTaskDelay(pdMS_TO_TICKS(400));
//			}
//	}



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