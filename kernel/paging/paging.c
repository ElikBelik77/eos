#include "paging.h"
#include <stdint.h>
uint32_t page_directory[1024] __attribute__((aligned(4096)));
uint32_t null_page_table[1024] __attribute__((aligned(4096)));
/*void map_page(void* physaddr, void* virtualaddr, uint32_t flags) {
	uint32_t pdindex = virtualaddr >> 22;
	uint32_t ptindex = virtualaddr >> 12 & 0x3ff;
}*/
void init_paging() {
	extern void enable_paging();
	extern void load_page_directory(unsigned int*);
	int i = 0;
	for(; i < 1024; i++) {
		page_directory[i] = 0x00000002;
	}
	for (i = 0; i < 1024; i++) {
		null_page_table[i] = (i*0x1000) | 3;
	}
	page_directory[0] = ((uint32_t)null_page_table) | 3;
	load_page_directory(page_directory);
	enable_paging();
}
