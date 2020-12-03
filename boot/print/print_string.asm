print_string_with_prefix:
	mov bx, si
	call print_string
	mov di, bx
	call print_string
	ret
print_string:
	mov si, di
        mov ah, 0x0E
.print_string_loop   lodsb
        or al, al
        jz .print_string_fin
        int 0x10
        jmp .print_string_loop
.print_string_fin   	ret

info_prefix: db "[Info]: ",0
error_prefix: db "[Error]: ",0
