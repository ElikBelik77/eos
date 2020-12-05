#include "keyboard.h"
#include "../port_io.h"
#include "../utils/string_utils.h"
unsigned char toggle_caps(unsigned char LED_value);

int check_caps(KeyboardDriver* driver, unsigned char scan_code) {
	int rsp = 0;
	if (driver->is_caps && scan_code == SC_CAPS_LOCK_DOWN) {
		rsp = toggle_caps(0x0);
		driver->is_caps = 0;
	}
	else if (!driver->is_caps && scan_code == SC_CAPS_LOCK_DOWN) {
		rsp = toggle_caps(0x4);
		driver->is_caps = 1;
	}
	return rsp;
}
int check_special_keys(KeyboardDriver* driver, unsigned char scan_code) {
	int rsp = 0;
	rsp |= check_caps(driver, scan_code);
	driver->is_shift = (scan_code == SC_SHIFT_UP ? 0 : driver->is_shift);
	driver->is_shift = (scan_code == SC_SHIFT_DOWN ? 1: driver->is_shift);
//	driver->is_caps = scan_code == SC_CAPS_LOCK_UP ? (0: driver->is_caps);
//	driver->is_caps = scan_code == SC_CAPS_LOCK_DOWN ? (1: driver->is_caps);
//	driver->is_c
	return rsp;
}

unsigned char toggle_caps(unsigned char LED_value) {
	unsigned char kbd_rsp;
	while (kbd_rsp != 0xfa) {
		port_byte_out(IO_PORT_KEYBOARD, 0xED);
		kbd_rsp = port_byte_in(IO_PORT_KEYBOARD);
		port_byte_out(IO_PORT_KEYBOARD, LED_value);
	}
	while ((kbd_rsp = port_byte_in(IO_PORT_KEYBOARD)) == 0xfa);
	return kbd_rsp;
}

void get_key(KeyboardDriver* driver, Key* key_buff) {
	unsigned char sc2ascii[] = {SCANCODE2ASCII_TABLE};
	unsigned char scan_code = port_byte_in(IO_PORT_KEYBOARD);
	key_buff->scan_code = scan_code;
	key_buff->ascii = sc2ascii[scan_code];
	int kbd_rsp = 0;
	if (kbd_rsp = check_special_keys(driver, scan_code))
		return;
	if (is_printable(key_buff->ascii)) {
		key_buff->is_printable = 1;
		if (is_lowercase(key_buff->ascii) && (driver->is_shift || driver->is_caps)) {
			key_buff->ascii += 'A'-'a';
		}
	}
	else {
		key_buff->is_printable = 0;
	}
}



void init_keyboard_driver(KeyboardDriver* driver) {
	driver->get_key = get_key;
	driver->is_shift = 0;
	driver->is_caps = 0;
	driver->is_ctrl = 0;
}
