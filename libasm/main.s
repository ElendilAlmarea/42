	global	start
	extern	_malloc
	extern	_read
	extern	_strcmp
	extern	_strcpy
	extern	_strdup
	extern	_strlen
	extern	_write
	extern	_ft_read
	extern	_ft_strcmp
	extern	_ft_strcpy
	extern	_ft_strdup
	extern	_ft_strlen
	extern	_ft_write

section	.data
	msg			db	'This is a sentence.', 0ah, 0h
	msg_success	db	'Success!', 0ah, 0h
	msg_fail	db	'Fail...', 0ah, 0h

section	.bss
	len_msg		equ	20
	len_success	equ	9
	len_fail	equ	8

section	.text
start:
	mov		rsi, msg			;test ft_write
	mov		rdx, len_msg
	call	_ft_write
	mov		rsi, msg
	mov		rdx, len_msg
	call	_write
	mov		rdi, msg			;test ft_strlen
	jmp		fail				;EXPLAIN ME PLS WHY THIS DOESNT JUMP AND JUST BEFORE YES
	call	_ft_strlen
	mov		rcx, rax
	mov		rdi, msg
	call	_strlen
	cmp		rax, rcx
	jnz		fail
	mov		rsi, msg_success
	mov		rdx, len_success
	call	_ft_write
	jmp		end

fail:
	mov		rsi, msg_fail
	mov		rdx, len_fail
	call	_ft_write
	jmp		end

end:
	mov		rax, 0x02000001		;kill
	mov		rdi, 0
	syscall