#include "paging/paging.h"
#include "drivers/screen.h"
#include "drivers/keyboard.h"
#include "int/idt.h"
#include "int/irq_handler.h"
#include <stdint.h>
void keyboard_irq();
void init_interrupt_handler();

KeyboardDriver keyboardDriver;
InterruptHandler int_handler;

void main() {
	clear_screen();
	print_dword((uint32_t)&main);
	print("[>] EOS is now running in 32bit protected-mode\n");
	print("[!] Loading IDT and interrupts\n");
	inject_interrupt_handler(&int_handler);
	init_interrupt_handler();
	init_idt();
	print("[*] IDT and interrupts are loaded\n");
	print("[!] Loading keyboard handler\n");
	init_keyboard_driver(&keyboardDriver);
	print("[*] Keyboard driver loaded\n");
	print_dword(&int_handler);
	init_paging();
	print_dword(&int_handler);
}

void page_fault(uint32_t fault) {
	print("fault");
}
void init_interrupt_handler() {
	int_handler.keyboard_irq = keyboard_irq;
	int_handler.page_fault = page_fault;
}


void keyboard_irq() {
	Key key;
	keyboardDriver.get_key(&keyboardDriver, &key);
	char* echo = (char[]) {key.ascii, '\0'};
//	if (key.is_printable)
//		print(&screenDriver, echo);
	print_byte(key.scan_code);
}
