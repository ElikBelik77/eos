global enable_paging
global load_page_directory

enable_paging:
	push ebp
	mov ebp, esp
	mov eax, cr0
	or eax, 0x80000001
	mov cr0, eax
	leave
	ret

load_page_directory:
	push ebp
	mov ebp, esp
	mov eax, [esp+8]
	mov cr3, eax
	leave
	ret
