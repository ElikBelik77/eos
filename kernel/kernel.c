#include "drivers/screen/screen.h"
void main() {
	char* vidmem = 0xb8000;
	//vidmem[0] = 'X';
	ScreenDriver driver;
	init_screen_driver(&driver);
	//vidmem[0] = 'X';
	//driver.print(&driver, "Hello World!");
	driver.clear_screen();
}
