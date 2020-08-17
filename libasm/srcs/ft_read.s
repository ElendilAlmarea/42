	global	_ft_read
	extern	__errno_location

_ft_read:
	mov		rax, 0x2000003
	syscall
	cmp		rax, 0
	jl		error
	ret

error:
			mov			r8, rax
			mov			rax, -1
			mul			r8
			push		rax
			call        __errno_location
			pop			r8
			mov			[rax], r8
			mov			rax, -1
			ret