#ifndef IDT_H_
#define IDT_H_
typedef struct IDT_entry{
	unsigned short int offset_lowerbits;
	unsigned short int selector;
	unsigned char zero;
	unsigned char type_attr;
	unsigned short int offset_higherbits;
} IDT_Entry;

void init_idt(void);
#endif 
