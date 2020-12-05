#ifndef IRQ_HANDLER_H_
#define IRQ_HANDLER_H_
typedef struct InterruptHandler {
	void (*keyboard_irq)();
} InterruptHandler;
void inject_interrupt_handler(InterruptHandler* handler);
#endif
