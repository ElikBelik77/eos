[bits 16]
[org 0x7c00]
jmp 0:real_mode_start
%include "pm/gdt.asm"
%include "print/print_string.asm"
%include "pm/switch_to_pm.asm"
%include "disk/os_disk_load.asm"
KERNEL_OFFSET equ 0x1000
BOOT_DRIVE db 0

real_mode_start:
mov [BOOT_DRIVE], dl
mov sp, 0x9000
mov bp, sp
call load_kernel
call switch_to_pm

load_kernel:
mov bx, KERNEL_OFFSET
mov dh, 4
mov dl, [BOOT_DRIVE]
call os_disk_load
ret

[bits 32]
%include "print/print_string_pm.asm"

BEGIN_PM:
	mov ax, DATA_SEG
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	call KERNEL_OFFSET

times 510-($-$$) db 0
dw 0xaa55
