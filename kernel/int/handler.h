typedef struct InterruptHandler {
	void (*keyboard_irq)();
} InterruptHandler;
InterruptHandler* get_interrupt_handler();
