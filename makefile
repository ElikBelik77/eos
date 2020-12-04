C_SOURCES = $(wildcard kernel/*.c kernel/idt/*.c kernel/drivers/*.c)
HEADERS = $(wildcard kernel/*.h kernel/drivers/*.h kernel/idt/*.h)
OBJ = ${C_SOURCES:.c=.o}
all: os-image
run: all
	bochs

os-image: boot/boot_sector.bin kernel.bin
	cat $^ > os-image

kernel.bin: kernel/kernel_entry.o kernel/idt/irq.o ${OBJ}
	ld -o $@ -m elf_i386 -Ttext 0x1000 $^ --oformat binary
kernel/kernel_entry.o: boot/kernel_entry.asm
	nasm $< -f elf -o $@
kernel/idt/irq.o: kernel/idt/irq.asm
	nasm $< -f elf -o $@
%.o: %.c ${HEADERS}
	gcc -m32 -ffreestanding -fno-pie -c $< -o $@
%.bin: %.asm
	nasm $< -f bin -I 'boot/' -o $@

clean:
	rm -fr *.bin *.o *.dis *.map os-image
	rm -fr kernel/*.o boot/*.bin kernel/drivers/*.o
kernel.dis: kernel/kernel.bin
	ndisasm -b 32 $< > $@

