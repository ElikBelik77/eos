[bits 16]
[org 0x7c00]
jmp 0:real_mode_start
%include "pm/gdt.asm"
%include "print/print_string.asm"
%include "pm/switch_to_pm.asm"
BOOT_DRIVE db 0
REAL_MODE_MESSAGE db "EOS is in 16bit real-mode",0
PM_MESSAGE db "EOS is in 32bit protected-mode",0

real_mode_start:
mov [BOOT_DRIVE], dl
mov sp, 0xFFFC
mov di, info_prefix
mov si, REAL_MODE_MESSAGE
call print_string_with_prefix

call switch_to_pm

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
	jmp $

times 510-($-$$) db 0
dw 0xaa55
