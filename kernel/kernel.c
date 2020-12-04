#include "drivers/screen.h"
#include "idt/idt.h"
void main() {
	ScreenDriver driver;
	init_screen_driver(&driver);
	driver.clear_screen();
	driver.print(&driver, "[>] EOS is now running in 32bit protected-mode\n");
	driver.print(&driver, "[!] Attempting to load the IDT\n");
	init_idt();
	driver.print(&driver, "[*] IDT Loaded\n");
}
