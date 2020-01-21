	global	_ft_strcpy

_ft_strcpy:
	mov		rcx, 0

looping:
	cmp		byte [rsi + rcx], byte 0
	jz		end
	mov		al, byte [rsi + rcx]
	mov		byte [rdi + rcx], al
	inc		rcx
	jmp		looping

end:
	mov		byte [rdi + rcx], byte 0
	mov		rax, rdi
	ret
