
#include "drivers/screen.h"
#include "drivers/keyboard.h"
#include "int/idt.h"
#include "int/irq_handler.h"

void keyboard_irq();
void init_interrupt_handler();

KeyboardDriver keyboardDriver;
ScreenDriver screenDriver;
InterruptHandler int_handler;

void main() {
	init_screen_driver(&screenDriver);
	screenDriver.clear_screen();
	screenDriver.print(&screenDriver, "[>] EOS is now running in 32bit protected-mode\n");
	screenDriver.print(&screenDriver, "[!] Loading IDT and interrupts\n");
	inject_interrupt_handler(&int_handler);
	init_interrupt_handler();
	init_idt();
	screenDriver.print(&screenDriver, "[*] IDT and interrupts are loaded\n");
	screenDriver.print(&screenDriver, "[!] Loading keyboard handler\n");
	init_keyboard_driver(&keyboardDriver);
	screenDriver.print(&screenDriver, "[*] Keyboard driver loaded\n");
//	screenDriver.print_byte(&screenDriver, 0xff);
}

void init_interrupt_handler() {
	int_handler.keyboard_irq = keyboard_irq;
}


void keyboard_irq() {
	Key key;
	keyboardDriver.get_key(&keyboardDriver, &key);
	char* echo = (char[]) {key.ascii, '\0'};
//	if (key.is_printable)
//		screenDriver.print(&screenDriver, echo);
	screenDriver.print_byte(&screenDriver, key.scan_code);
}
