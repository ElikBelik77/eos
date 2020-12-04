#include "drivers/screen/screen.h"
void main() {
	ScreenDriver driver;
	init_screen_driver(&driver);
	driver.print(&driver, "Hello World!", 0, 0);
}
