
#include "drivers/screen.h"
#include "drivers/keyboard.h"
#include "int/idt.h"
#include "int/irq_handler.h"

void keyboard_irq();
void init_interrupt_handler();

KeyboardDriver keyboardDriver;
ScreenDriver screenDriver;
InterruptHandler ihandler;

void main() {
	init_screen_driver(&screenDriver);
	screenDriver.clear_screen();
	screenDriver.print(&screenDriver, "[>] EOS is now running in 32bit protected-mode\n");
	screenDriver.print(&screenDriver, "[!] Loading IDT\n");
	init_idt();
	screenDriver.print(&screenDriver, "[*] IDT Loaded\n");
	screenDriver.print(&screenDriver, "[!] Loading interrupts\n");
	//init_interrupt_handler();
	inject_interrupt_handler(&ihandler);
	init_interrupt_handler();
	screenDriver.print(&screenDriver, "[*] Interrupts loaded\n");
	screenDriver.print(&screenDriver, "[!] Loading keyboard handler\n");
	init_keyboard_driver(&keyboardDriver);
	screenDriver.print(&screenDriver, "[*] Keyboard driver loaded\n");
}

void init_interrupt_handler() {
	ihandler.keyboard_irq = keyboard_irq;
}


void keyboard_irq() {
	//Key key;
	screenDriver.print(&screenDriver, "> Keyboard echo IRQ\n");
//	keyboardDriver.get_key(&key);
//	char* echo = (char[]) {key.scan_code, '\0'};
//	screenDriver.print(&screenDriver, echo);
}
