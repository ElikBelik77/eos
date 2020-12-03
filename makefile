all: os-image
run: all
	bochs
os-image: boot_sector.bin kernel.bin
	cat $^ > os-image
kernel.bin: kernel_entry.o kernel.o
	ld -o $@  -melf_i386 -Ttext 0x1000 $^ --oformat binary
kernel.o: kernel/kernel.c
	gcc -m32 -c $< -o $@ -ffreestanding -fno-pie
kernel_entry.o: boot/kernel_entry.asm
	nasm $< -f elf32 -o $@
boot_sector.bin: boot/boot_sector.asm
	nasm $< -f bin -I 'boot/' -o $@
clean:
	rm -fr *.bin *.o *.dis *.map os-image
kernel.dis: kernel/kernel.bin
	ndisasm -b 32 $< > $@

