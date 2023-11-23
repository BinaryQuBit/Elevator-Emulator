#include <stdint.h>
void setTextColor(uint8_t colorCode);
void displayBox(uint8_t width, uint8_t height, uint8_t centerRow, uint8_t centerColumn, uint8_t colorCode);
void drawHorizontal(uint8_t width, uint8_t centerRow, uint8_t centerColumn, uint8_t colorCode);
void drawVertical(uint8_t height, uint8_t centerRow, uint8_t centerColumn, uint8_t colorCode);
void drawFifth(uint8_t floorNumber, uint8_t colorCode);
void drawForth(uint8_t floorNumber, uint8_t colorCode);
void drawThird(uint8_t floorNumber, uint8_t colorCode);
void drawSecond(uint8_t floorNumber, uint8_t colorCode);
void drawFirst(uint8_t floorNumber, uint8_t colorCode);
void instructions(uint8_t colorCode);
void statusDisplay(uint8_t colorCode);
void displayBreaker(uint8_t row, uint8_t colorCode);
void displaySetup();