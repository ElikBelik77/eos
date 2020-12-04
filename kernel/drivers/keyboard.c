#include "keyboard.h"
KeyboardDriver keyboardDriver;
KeyboardDriver* get_keyboard_driver() {

	keyboardDriver.get_key();
	return &keyboardDriver;
}
