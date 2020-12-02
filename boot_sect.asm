[org 0x7c00]
mov bp, 0x9000
mov sp, bp
mov di, info_prefix
mov si, real_mode_message
call print_string_with_prefix

call switch_to_pm



;mov dh, 2
;mov dl, [BOOT_DRIVE]
;mov bx, 0x9000
;call os_disk_load

%include "print/print_string.asm"
%include "print/print_string_pm.asm"
%include "gdt.asm"
%include "switch_to_pm.asm"
[bits 32]
BEGIN_PM:
	mov ebx, protected_mode_message
	call print_string_pm
	jmp $

BOOT_DRIVE: db 0
real_mode_message: db "EOS is in 16bit real-mode", 10, 13, 0
protected_mode_message: db "EOS is in 32bit protected-mode", 0

times 510-($-$$) db 0
dw 0xaa55
