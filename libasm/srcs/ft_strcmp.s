	global	_ft_strcmp

_ft_strcmp:
	mov		rcx, 0

looping:
	mov		al, byte [rdi + rcx]
	cmp		al, byte [rsi + rcx]
	jnz		end
	cmp		al, byte 0
	jz		end
	inc		rcx
	jmp		looping

end:
	sub		al, byte [rsi + rcx]
	ret
