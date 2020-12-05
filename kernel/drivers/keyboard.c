#include "keyboard.h"
#include "../port_io.h"
void get_key(Key* key_buff) {
	unsigned char scan_code = port_byte_in(IO_PORT_KEYBOARD_OUTPUT_BUFFER);
	key_buff->scan_code = scan_code;
}



void init_keyboard_driver(KeyboardDriver* driver) {
	driver->get_key = get_key;
}
