print_hex_word:
	mov bx, hex_table
	mov cx, 4
	xor ax, ax
	mov dx, di
print_hex_word_loop:
	push dx
	and dh, 0xF0
	mov al, dh
	shr al, 4
	xlat
	mov ah, 0x0e
	int 0x10
	pop dx
	shl dx, 4
	loop print_hex_word_loop
	ret
hex_table:
	db "0123456789ABCDEF",0
