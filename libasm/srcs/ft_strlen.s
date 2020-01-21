	global	_ft_strlen

_ft_strlen:
	mov		rcx, 0

looping:
	cmp		byte [rdi + rcx], byte 0
	jz		end
	inc		rcx
	jmp		looping

end:
	mov		rax, rcx
	ret
