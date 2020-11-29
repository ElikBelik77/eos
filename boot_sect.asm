org 0x7C00
bits 16

cli
mov di, boot_msg
call print_info_string
hlt

%include "print/print_string.asm"

boot_msg: db "Booting EOS...",0
times 510-($-$$) db 0
dw 0xAA55
