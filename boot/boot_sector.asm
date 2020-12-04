[bits 16]
[org 0x7c00]
jmp 0:real_mode_start
%include "pm/gdt.asm"
%include "print/print_string.asm"
%include "pm/switch_to_pm.asm"
%include "disk/os_disk_load.asm"
KERNEL_OFFSET equ 0x1000
BOOT_DRIVE db 0
REAL_MODE_MESSAGE db "EOS is in 16bit real-mode", 10, 13, 0
LOADING_KERNEL_MESSAGE db "EOS is loading the kernel", 10, 13, 0

real_mode_start:
mov [BOOT_DRIVE], dl
mov sp, 0x9000
mov bp, sp
mov di, info_prefix
mov si, REAL_MODE_MESSAGE
call print_string_with_prefix
call load_kernel
call switch_to_pm

load_kernel:
mov di, info_prefix
mov si, LOADING_KERNEL_MESSAGE
call print_string_with_prefix
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
	mov ebx, PM_MESSAGE
	call print_string_pm
	call KERNEL_OFFSET

PM_MESSAGE db "EOS is in 32bit protected-mode", 0
times 510-($-$$) db 0
dw 0xaa55
