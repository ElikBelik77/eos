
#include "../port_io.h"
#include "irq_handler.h"
#include <stdint.h>
InterruptHandler* handler;

void inject_interrupt_handler(InterruptHandler* h) {
	handler = h;
}

void page_fault_handler(void) {
	uint32_t address;
	asm("movl %%cr2,%0":"=r" (address));
}
void irq0_handler(void) {
	outb(0x20, 0x20);
}

void irq1_handler(void) {
	handler->keyboard_irq();
	outb(0x20, 0x20);
}

void irq2_handler(void) {
	outb(0x20, 0x20);
}

void irq3_handler(void) {
	outb(0x20, 0x20);
}

void irq4_handler(void) {
	outb(0x20, 0x20);
}

void irq5_handler(void) {
	outb(0x20, 0x20);
}

void irq6_handler(void) {
	outb(0x20, 0x20);
}

void irq7_handler(void) {
	outb(0x20, 0x20);
}

void irq8_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20);
}

void irq9_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20);
}

void irq10_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20);
}

void irq11_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20);
}

void irq12_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20);
}

void irq13_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20);
}

void irq14_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20);
}

void irq15_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20);
}
