#ifndef SCREEN_H_
#define SCREEN_H_
/**
	Struct for the ScreenDriver, allows the user to interact
	with the display.
	function:
		print - prints the string to the screen.
		clear_screen - clears the screen.
**/

struct ScreenDriver {
	int (*print)(struct ScreenDriver*, char*);
	int (*print_byte)(struct ScreenDriver*, unsigned char);
	void (*clear_screen)();
};
typedef struct ScreenDriver ScreenDriver;

//Initiates a new screen driver.
void init_screen_driver(ScreenDriver* driver);
#define VIDEO_MEMORY 0xb8000
#define WHITE_ON_BLACK 0x0f
#define MAX_ROWS 25
#define MAX_COLS 80
#define IO_PORT_SCREEN_REG_CTRL 0x3d4
#define IO_PORT_SCREEN_REG_DATA 0x3d5
#define CURSOR_LOC_HIGH_REG 0xE
#define CURSOR_LOC_LOW_REG 0xF
#endif
