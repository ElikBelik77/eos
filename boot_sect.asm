
org 0x7C00                      ; BIOS loads our programm at this address
bits 16                         ; We're working at 16-bit mode here

start:
	cli
	mov si, msg
	mov ah, 0x0E
.loop	lodsb
	or al, al
	jz halt
	int 0x10
	jmp .loop
halt:	hlt
msg:	db "Hello, World!", 0
times 510-($-$$) db 0
dw 0xAA55
