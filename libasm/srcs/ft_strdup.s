	global	_ft_strdup
	extern	_malloc
	extern	_ft_strlen
	extern	_ft_strcpy

_ft_strdup:
	push	rdi
	call	_ft_strlen
	mov		rdi, rax
	inc		rdi
	call	_malloc
	mov		rdi, rax
	pop		rsi
	cmp		rsi, 0
	jz		end
	call	_ft_strcpy
	ret

end:
	ret