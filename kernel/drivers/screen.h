#ifndef SCREEN_H_
#include <stdint.h>
#define SCREEN_H_
/**
	Struct for the ScreenDriver, allows the user to interact
	with the display.
	function:
		print - prints the string to the screen.
		clear_screen - clears the screen.
**/

// This function prints a string to the cursor location.
int print(char*);
// This function print a byte in hex to the cursor location.
void print_byte(uint8_t);
void print_word(uint16_t);
void print_dword(uint32_t);
// This function clears the screen.
void clear_screen();

#define VIDEO_MEMORY 0xb8000
#define WHITE_ON_BLACK 0x0f
#define MAX_ROWS 25
#define MAX_COLS 80
#define IO_PORT_SCREEN_REG_CTRL 0x3d4
#define IO_PORT_SCREEN_REG_DATA 0x3d5
#define CURSOR_LOC_HIGH_REG 0xE
#define CURSOR_LOC_LOW_REG 0xF
#endif
