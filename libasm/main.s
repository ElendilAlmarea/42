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
	msg_cpy		db  '                    ', 0ah, 0h
	buffer		db	'                    ', 0ah, 0h

section	.bss
	len_msg		equ	20
	len_success	equ	9
	len_fail	equ	8

section	.text
start:
	mov		rdi, 1
	mov		rsi, msg
	mov		rdx, len_msg
	call	_ft_write
	mov		rdi, 1
	mov		rsi, msg
	mov		rdx, len_msg
	call	_write
	mov		rdi, msg			;test ft_strlen
	call	_ft_strlen
	push	rax
	mov		rdi, msg
	push	rbx
	call	_strlen
	pop		rbx
	pop		rcx
	cmp		rax, rcx
	jnz		fail
	mov		rdi, 1
	mov		rsi, msg_success
	mov		rdx, len_success
	call	_ft_write
	mov		rdi, msg_success	;test ft_strcmp
	mov		rsi, msg_fail
	call	_ft_strcmp
	push	rax
	mov		rdi, msg_success
	mov		rsi, msg_fail
	push	rbx
	call	_strcmp
	pop		rbx
	pop		rcx
	cmp		rax, rcx
	jnz		fail
	mov		rdi, 1
	mov		rsi, msg_success
	mov		rdx, len_success
	call	_ft_write
	mov		rdi, msg_success
	mov		rsi, msg_success
	call	_ft_strcmp
	push	rax
	mov		rdi, msg_success
	mov		rsi, msg_success
	push	rbx
	call	_strcmp
	pop		rbx
	pop		rcx
	cmp		rax, rcx
	jnz		fail
	mov		rdi, 1
	mov		rsi, msg_success
	mov		rdx, len_success
	call	_ft_write
	mov		rdi, msg_cpy		;test ft_strcpy
	mov		rsi, msg
	call	_ft_strcpy
	mov		rdi, 1
	mov		rsi, msg_cpy
	mov		rdx, len_msg
	call	_ft_write
	mov		rdi, msg_success	;test ft_strdup
	call	_ft_strdup
	mov		rsi, rax
	mov		rdi, 1
	mov		rdx, len_success
	call	_ft_write
	mov		rax, 0				;test ft_read
	mov		rdx, 20
	mov		rdi, buffer
	call	_ft_read
	mov		rdi, 1
	mov		rsi, buffer
	mov		rdx, 20
	call	_ft_write
	jmp		end

fail:
	mov		rdi, 1
	mov		rsi, msg_fail
	mov		rdx, len_fail
	call	_ft_write
	jmp		end

end:
	mov		rax, 0x02000001		;kill
	mov		rdi, 0
	syscall
