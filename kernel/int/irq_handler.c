
#include "../port_io.h"
#include "irq_handler.h"
InterruptHandler* handler;

void inject_interrupt_handler(InterruptHandler* h) {
	handler = h;
}

void irq0_handler(void) {
	port_byte_out(0x20, 0x20);
}

void irq1_handler(void) {
	handler->keyboard_irq();
	port_byte_out(0x20, 0x20);
}

void irq2_handler(void) {
	port_byte_out(0x20, 0x20);
}

void irq3_handler(void) {
	port_byte_out(0x20, 0x20);
}

void irq4_handler(void) {
	port_byte_out(0x20, 0x20);
}

void irq5_handler(void) {
	port_byte_out(0x20, 0x20);
}

void irq6_handler(void) {
	port_byte_out(0x20, 0x20);
}

void irq7_handler(void) {
	port_byte_out(0x20, 0x20);
}

void irq8_handler(void) {
	port_byte_out(0xA0, 0x20);
	port_byte_out(0x20, 0x20);
}

void irq9_handler(void) {
	port_byte_out(0xA0, 0x20);
	port_byte_out(0x20, 0x20);
}

void irq10_handler(void) {
	port_byte_out(0xA0, 0x20);
	port_byte_out(0x20, 0x20);
}

void irq11_handler(void) {
	port_byte_out(0xA0, 0x20);
	port_byte_out(0x20, 0x20);
}

void irq12_handler(void) {
	port_byte_out(0xA0, 0x20);
	port_byte_out(0x20, 0x20);
}

void irq13_handler(void) {
	port_byte_out(0xA0, 0x20);
	port_byte_out(0x20, 0x20);
}

void irq14_handler(void) {
	port_byte_out(0xA0, 0x20);
	port_byte_out(0x20, 0x20);
}

void irq15_handler(void) {
	port_byte_out(0xA0, 0x20);
	port_byte_out(0x20, 0x20);
}
