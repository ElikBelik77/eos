#include "string_utils.h"
int is_lowercase(unsigned char ascii) {
	return ascii >= 0x61 && ascii <= 0x7a;
}
int is_uppercase(unsigned char ascii) {
	return ascii >= 0x41 && ascii <= 0x5a;
}

int is_alphabet(unsigned char ascii) {
	return is_uppercase(ascii) || is_lowercase(ascii);
}
int is_printable(unsigned char ascii) {
	return ascii >=0x20 && ascii <=0x7e;
}
