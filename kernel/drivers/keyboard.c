#include "keyboard.h"
#include "../port_io.h"
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
	unsigned char scan_code = port_byte_in(IO_PORT_KEYBOARD);
	unsigned char sc2ascii[] = {SCANCODE2ASCII_TABLE};
	unsigned char scshifted2ascii[] = {SCANCODE2ASCII_TABLE_SHIFT};
	unsigned char scctrl2ascii[] = {SCANCODE2ASCII_TABLE_CTRL};
	int kbd_rsp = 0;
	if (kbd_rsp = check_special_keys(driver, scan_code))
		return;
	key_buff->scan_code = scan_code;
	
	if (driver->is_shift) {
		key_buff->ascii = scshifted2ascii[scan_code];
		return;
	}
	if (driver->is_ctrl) {
		key_buff->ascii = scctrl2ascii[scan_code];
		return;
	}
	if (driver->is_caps && sc2ascii[scan_code] <= 0x7a && sc2ascii[scan_code] >= 0x61) {
		key_buff->ascii = sc2ascii[scan_code]+'A'-'a';
		return;
	}
	key_buff->ascii = sc2ascii[scan_code];
}



void init_keyboard_driver(KeyboardDriver* driver) {
	driver->get_key = get_key;
	driver->is_shift = 0;
	driver->is_caps = 0;
	driver->is_ctrl = 0;
}
