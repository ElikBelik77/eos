; loads dh os sectors into es:bx from drive dl. 
os_disk_load:
	push dx
	mov ah, 2
	mov al, dh
	mov ch, 0
	mov dh, 0
	mov cl, 2
	int 0x13

	jc os_disk_load_error
	pop dx
	cmp dh, al
	jne os_disk_load_error
	ret
os_disk_load_error:
	mov di, error_prefix
	mov si, os_disk_load_message
	call print_string_with_prefix
	hlt

os_disk_load_message: db "Error loading EOS from disk", 10, 13, 0
