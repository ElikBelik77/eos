global init_multitasking
TCB.ESP equ 0
TCB.CR3 equ 4
TCB.NEXT equ 8
TCB.STATE equ 12
init_multitasking:
	lea eax, [esp + 4]
	mov [eax + TCB.ESP], esp
	mov ecx, cr3
	mov [eax + TCB.CR3], ecx
	mov [eax + TCB.NEXT], 0
	mov [eax + TCB.STATE], 0
	ret

switch_to_task:
	push ebx
	push esi
	push edi
	push ebp

	mov edi, [esp + 24]
	mov [edi + TCB.ESP], esp
	mov esi, [esp + 20]
	mov esp, [esi + TCB.ESP]
	mov 
