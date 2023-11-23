// ******************************************* main.c **************************************
// Project: Elevator Simulation
// File: main.c
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
#include "header.h"
#include "myFunctions.h"
#include "usart.h"
#include "cli.h"
#include "timer.h"
#include "tasking.h"
#include "FreeRTOS.h"
#include "task.h"
#include "staticStructure.h"

#define MAX_ROW 49 // Assuming the bottom of your screen is at row 30
#define SCREEN_WIDTH 179
#define CMD_BUFFER_SIZE 128
static char cmdBuffer[CMD_BUFFER_SIZE];
static int cmdIndex = 0;
static QueueHandle_t xCommandQueue;
void clearScreenFromRow(uint8_t startRow);

// Function Prototypes
static void TaskHandleUserInput(void *pvParameters);
static void TaskProcessCommand(void *pvParameters);
static void processCommand(const char* cmd);
void timeElapsed(void *pvParameters);
static void handleCharacterReceived();
void handleUserInput();
void sendPromptArrows();
void floorStatus(void *pvParameters);
void status(void *pvParameters);

uint8_t row = 24;

int main(void)
{
	clockInit();
	serial_open();
	updateTimer();
	displaySetup();
	RCC_SetGPIOClock('C', true);
	xCommandQueue = xQueueCreate(100, sizeof(char*));
	xTaskCreate(TaskHandleUserInput, "Blinky", configMINIMAL_STACK_SIZE, NULL, configMAX_PRIORITIES - 1, NULL);

	xTaskCreate(timeElapsed, "CmdProcessor", configMINIMAL_STACK_SIZE, NULL, configMAX_PRIORITIES - 2, NULL);
	
	xTaskCreate(floorStatus, "floor", configMINIMAL_STACK_SIZE, NULL, configMAX_PRIORITIES - 3, NULL);
	
	xTaskCreate(status, "status", configMINIMAL_STACK_SIZE, (void*)statusMessage, configMAX_PRIORITIES - 4, NULL);

	vTaskStartScheduler();

}

void status(void *pvParameters)
{
    while(1)
    {
        setTextColor(34);
        char buffer[50];
        int len = sprintf(buffer, "\x1b[18;154H%s", statusMessage); // Use %s for string
        CLI_Transmit((uint8_t*)buffer, strlen(buffer));
        message("\033[u");
        vTaskDelay(200);
    }
}

void floorStatus(void *pvParameters)
{
    while(1) {
			setTextColor(34);
            char buffer[20];

            int len = sprintf(buffer, "\x1b[17;153H%u", floorNumber);

            CLI_Transmit((uint8_t*)buffer, strlen(buffer));
			message("\033[u");
        vTaskDelay(200);
			}
}

void timeElapsed(void *pvParameters)
{
	while(1)
	{
		setTextColor(34);
		char buffer[80];
		int len = sprintf(buffer, "\x1b[16;160H%lu seconds", timeCounter);
		CLI_Transmit((uint8_t*)buffer, strlen(buffer));
		message("\033[u");
		vTaskDelay(200);
	}
}

void TaskHandleUserInput(void *pvParameters){
    sendPromptArrows();
	message("\033[s");
    while (1) {
        if (characterFlag == 1) {
					message("\033[s");
            if (characterReceived == '\r') {
							 currentRow++;
							message("\033[s");
                if (currentRow > MAX_ROW) {
                    clearScreenFromRow(24);
									setCursorPosition(24, 4);
									message("\033[s");
                }
                sendPromptArrows();
								cmdBuffer[cmdIndex] = '\0';
								processCommand(cmdBuffer);
                cmdIndex = 0;
            } else {
                if (cmdIndex < CMD_BUFFER_SIZE - 1) {
                    cmdBuffer[cmdIndex++] = characterReceived;
                }
            }
            characterFlag = 0;
        }
				vTaskDelay(1);
    }
}

void processCommand(const char* cmd)
{
	if (strcmp(cmd, "up") == 0 || strcmp(cmd, "open")  == 0 || strcmp(cmd, "1") == 0)
	{
		delay(2000);
		statusMessage = "Door Opened";
	}
	if (strcmp(cmd, "2") == 0)
	{
		delay(2000);
		statusMessage = "Door Closed";
		delay(2000);
		floorNumber = 2;
		statusMessage = "Door Opened";
	}
	else if (strcmp(cmd, "0") == 0)
	{
		display("Hello", 1, 1);
	}
}


void sendPromptArrows() {
    uint8_t column = 0;
    display(">> ", currentRow, currentColumn);
	message("\033[s");
}

void clearScreenFromRow(uint8_t startRow) {
    char clearLine[SCREEN_WIDTH + 1];
    memset(clearLine, ' ', SCREEN_WIDTH); // Fill the line with spaces
    clearLine[SCREEN_WIDTH] = '\0'; // Null-terminate the string

    for (uint8_t i = startRow; i <= MAX_ROW; i++) {
        display(clearLine, i, 0); // Clear each line with spaces
			    setCursorPosition(startRow, 0); // Reset cursor to start of cleared area
    currentRow = startRow; // Update currentRow
    currentColumn = 0; // Reset currentColumn
    }
}









