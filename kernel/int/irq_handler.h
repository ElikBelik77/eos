#ifndef IRQ_HANDLER_H_
#define IRQ_HANDLER_H_
#include <stdint.h>
typedef struct InterruptHandler {
	void (*keyboard_irq)();
	void (*page_fault)(uint32_t address);
} InterruptHandler;
void inject_interrupt_handler(InterruptHandler* handler);
#endif
