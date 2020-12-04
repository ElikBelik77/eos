#include "drivers/screen.h"
void main() {
	ScreenDriver driver;
	init_screen_driver(&driver);
	driver.clear_screen();
	driver.print(&driver, "EOS is now running in 32bit protected-mode");
}
