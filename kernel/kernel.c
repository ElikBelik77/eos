#include "drivers/screen.h"
#include "int/idt.h"
#include "int/handler.h"
void keyboard_irq();

ScreenDriver* screenDriver;
InterruptHandler* ihandler;
KeyboardDriver* keyboardDriver;
void main() {
	screenDriver = get_screen_driver();
	screenDriver->clear_screen();
	screenDriver->print(screenDriver, "[>] EOS is now running in 32bit protected-mode\n");
	screenDriver->print(screenDriver, "[!] Loading IDT\n");
	init_idt();
	screenDriver->print(screenDriver, "[*] IDT Loaded\n");
	screenDriver->print(screenDriver, "[!] Loading interrupts\n");
	ihandler = get_interrupt_handler();
	ihandler->keyboard_irq = keyboard_irq;
	screenDriver->print(screenDriver, "[*] Interrupts loaded\n");
}



void keyboard_irq() {
	screenDriver->print(screenDriver, "Keyboard IRQ\n");
}
