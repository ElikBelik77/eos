
print_hex:
	ret
print_info_string:
	mov bx, di
	mov di, info_prefix
	call print_string
	mov di, bx
	call print_string
	ret
print_string:
	mov si, di
        mov ah, 0x0E
.loop   lodsb
        or al, al
        jz fin
        int 0x10
        jmp .loop
fin:   	ret

info_prefix: db "[Info]: ",0
error_prefix: db "[Error]: ",0
