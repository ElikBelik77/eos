#include "drivers/screen.h"
void main() {
	ScreenDriver driver;
	init_screen_driver(&driver);
	driver.clear_screen();
	driver.print(&driver, "Hello World!\n");
}
