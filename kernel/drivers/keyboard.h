#ifndef KEYBOARD_H_
#define KEYBOARD_H_
typedef struct Key {
	unsigned char scan_code;
} Key;
typedef struct KeyboardDriver {
	void (*get_key)(Key* key_buf);
} KeyboardDriver;
void init_keyboard_driver(KeyboardDriver* driver);
#define IO_PORT_KEYBOARD_OUTPUT_BUFFER 0x60
#endif

