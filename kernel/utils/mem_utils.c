#include "mem_utils.h"
void memcpy(char* source, char* dest, unsigned int no_bytes) {
	int i = 0;
	for(; i < no_bytes; i++) {
		dest[i] = source[i];
	}
}
