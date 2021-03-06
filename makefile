C_SOURCES = $(wildcard kernel/*.c kernel/*/*.c)
HEADERS = $(wildcard kernel/*.h kernel/*/*.h) 
OBJ = ${C_SOURCES:.c=.o}
all: clean os-image
run: all
	bochs

os-image: boot/boot_sector.bin kernel.bin
	cat $^ > os-image

kernel.bin: boot/kernel_entry.o kernel/paging/paging_init.o kernel/int/irq.o ${OBJ}
	ld -o $@ -m elf_i386 -Ttext 0x1000 $^ --oformat binary
boot/kernel_entry.o: boot/kernel_entry.asm
	nasm $< -f elf -o $@
kernel/int/irq.o: kernel/int/irq.asm
	nasm $< -f elf -o $@
kernel/paging/paging_init.o: kernel/paging/paging_init.asm
	nasm $< -f elf -o $@
%.o: %.c ${HEADERS}
	gcc -m32 -ffreestanding -fno-pie -c $< -o $@
%.bin: %.asm
	nasm $< -f bin -I 'boot/' -o $@
clean:
	rm -fr *.bin *.o *.dis *.map *.c~ os-image
	rm -fr kernel/*.o boot/*.bin kernel/drivers/*.o
	rm -fr kernel/*/*.o  kernel/*/*.save
	rm -fr kernel/int/*.o
kernel.dis: kernel.bin
	ndisasm -b 32 $< > $@

